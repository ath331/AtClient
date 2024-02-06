////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief PacketSession Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"
#include "AtClient.h" //< SendBuffer�� ���� Ŭ����ȭ �ϱ�


/**
 * 
 */
class ATCLIENT_API PacketSession : public TSharedFromThis< PacketSession >
{
public:
	/// ������
	PacketSession( class FSocket* Socket );

	/// �Ҹ���
	~PacketSession();

	/// ������ ���۽�Ų��.
	void Run();

	/// ���� ��Ŷ�� ó���Ѵ�.
	UFUNCTION( BlueprintCallable )
	void HandleRecvPackets();

	/// ��Ŷ�� �����Ѵ�.
	void SendPacket( SendBufferPtr SendBuffer );

	/// ���� ������ ���´�.
	void Disconnect();

public:
	/// ����
	class FSocket* Socket;
	
	TSharedPtr< class RecvWorker > RecvWorkerThread;
	TSharedPtr< class SendWorker > SendWorkerThread;

	// GameThread�� NetworkThread�� ������ �ְ� �޴� ���� ť.
	TQueue< TArray< uint8 > > RecvPacketQueue;
	TQueue< SendBufferPtr >   SendPacketQueue;
};
