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
	/// ������
	FPacketHeader() : PacketSize( 0 ), PacketID( 0 )
	{
	}

	/// ������
	FPacketHeader( uint16 PacketSize, uint16 PacketID ) : PacketSize( PacketSize ), PacketID( PacketID )
	{
	}

	/// << �����ε�
	friend FArchive& operator<<( FArchive& Ar, FPacketHeader& Header )
	{
		Ar << Header.PacketSize;
		Ar << Header.PacketID;
		return Ar;
	}

	/// ��Ŷ ������
	uint16 PacketSize;

	/// ��Ŷ ���̵�
	uint16 PacketID;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  RecvWorker Class
////////////////////////////////////////////////////////////////////////////////////////////////////
class ATCLIENT_API RecvWorker : public FRunnable
{
public:
	/// ������
	RecvWorker( FSocket* Socket, TSharedPtr< PacketSession > Session );

	/// �Ҹ���
	~RecvWorker();

	/// �ʱ�ȭ �Ѵ�
	virtual bool Init()  override;

	/// �����Ѵ�.
	virtual uint32 Run() override;

	/// �����Ѵ�.
	virtual void Exit()  override;

	/// �����带 �����.
	void Destroy();

private:
	/// ��Ŷ�� �����Ѵ�.
	bool ReceivePacket( TArray<uint8>& OutPacket );

	/// ��Ŷ ũ�⸸ŭ�� ������ ����Ѵ�.
	bool ReceiveDesiredBytes( uint8* Results, int32 Size );

protected:

	/// ������
	FRunnableThread* Thread = nullptr;

	/// ������ ���� üũ
	bool Running = true;

	/// ����
	FSocket* Socket;

	/// ����
	TWeakPtr< PacketSession > SessionWPtr;

};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief  SendWorker Class
////////////////////////////////////////////////////////////////////////////////////////////////////
class ATCLIENT_API SendWorker : public FRunnable
{
public:
	/// ������
	SendWorker( FSocket* Socket, TSharedPtr< class PacketSession > Session );

	/// �Ҹ���
	~SendWorker();

	/// �ʱ�ȭ�Ѵ�.
	virtual bool Init() override;

	/// �����Ѵ�.
	virtual uint32 Run() override;

	/// �����Ѵ�.
	virtual void Exit() override;

	/// ��Ŷ�� �����Ѵ�.
	bool SendPacket( SendBufferPtr SendBuffer );

	/// �����带 �����.
	void Destroy();

private:
	/// size��ŭ Buffer�� �����Ѵ�.
	bool SendDesiredBytes( const uint8* Buffer, int32 Size );

protected:
	/// ������
	FRunnableThread* Thread = nullptr;

	/// ������ ���� üũ
	bool Running = true;

	/// ����
	FSocket* Socket;

	/// ����
	TWeakPtr< class PacketSession > SessionWPtr;
};