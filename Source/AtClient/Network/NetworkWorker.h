////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  NetworkWorker Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"
#include "AtClient.h"


class FSocket;
class PacketSession;


////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  FPacketHeader Class
////////////////////////////////////////////////////////////////////////////////////////////////////
struct ATCLIENT_API FPacketHeader
{
	/// 생성자
	FPacketHeader() : PacketSize( 0 ), PacketID( 0 )
	{
	}

	/// 생성자
	FPacketHeader( uint16 PacketSize, uint16 PacketID ) : PacketSize( PacketSize ), PacketID( PacketID )
	{
	}

	/// << 오버로딩
	friend FArchive& operator<<( FArchive& Ar, FPacketHeader& Header )
	{
		Ar << Header.PacketSize;
		Ar << Header.PacketID;
		return Ar;
	}

	/// 패킷 사이즈
	uint16 PacketSize;

	/// 패킷 아이디
	uint16 PacketID;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  RecvWorker Class
////////////////////////////////////////////////////////////////////////////////////////////////////
class ATCLIENT_API RecvWorker : public FRunnable
{
public:
	/// 생성자
	RecvWorker( FSocket* Socket, TSharedPtr< PacketSession > Session );

	/// 소멸자
	~RecvWorker();

	/// 초기화 한다
	virtual bool Init()  override;

	/// 실행한다.
	virtual uint32 Run() override;

	/// 종료한다.
	virtual void Exit()  override;

	/// 스레드를 멈춘다.
	void Destroy();

private:
	/// 패킷을 수신한다.
	bool ReceivePacket( TArray<uint8>& OutPacket );

	/// 패킷 크기만큼의 수신을 대기한다.
	bool ReceiveDesiredBytes( uint8* Results, int32 Size );

protected:

	/// 스레드
	FRunnableThread* Thread = nullptr;

	/// 스레드 동작 체크
	bool Running = true;

	/// 소켓
	FSocket* Socket;

	/// 세션
	TWeakPtr< PacketSession > SessionWPtr;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  SendWorker Class
////////////////////////////////////////////////////////////////////////////////////////////////////
class ATCLIENT_API SendWorker : public FRunnable
{
public:
	/// 생성자
	SendWorker( FSocket* Socket, TSharedPtr< class PacketSession > Session );

	/// 소멸자
	~SendWorker();

	/// 초기화한다.
	virtual bool Init() override;

	/// 실행한다.
	virtual uint32 Run() override;

	/// 종료한다.
	virtual void Exit() override;

	/// 패킷을 전송한다.
	bool SendPacket( SendBufferPtr SendBuffer );

	/// 스레드를 멈춘다.
	void Destroy();

private:
	/// size만큼 Buffer를 전송한다.
	bool SendDesiredBytes( const uint8* Buffer, int32 Size );

protected:
	/// 스레드
	FRunnableThread* Thread = nullptr;

	/// 스레드 동작 체크
	bool Running = true;

	/// 소켓
	FSocket* Socket;

	/// 세션
	TWeakPtr< class PacketSession > SessionWPtr;
};