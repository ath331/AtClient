////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief PacketSession Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"


/**
 * 
 */
class ATCLIENT_API PacketSession : public TSharedFromThis< PacketSession >
{
public:
	/// 생성자
	PacketSession( class FSocket* Socket );

	/// 소멸자
	~PacketSession();

	/// 세션을 동작시킨다.
	void Run();

	/// 세션 연결을 끊는다.
	void Disconnect();

public:
	/// 소켓
	class FSocket* Socket;
	
	TSharedPtr< class RecvWorker > RecvWorkerThread;
	TSharedPtr< class SendWorker > SendWorkerThread;

	// GameThread와 NetworkThread가 데이터 주고 받는 공용 큐.
	TQueue< TArray< uint8 > > RecvPacketQueue;
};
