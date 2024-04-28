////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief UAtClientGameInstance Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AtClient.h"
#include "AtClientGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class ATCLIENT_API UAtClientGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	/// ������ �����Ѵ�.
	UFUNCTION( BlueprintCallable )
	void ConnectToGameServer();

	/// ������ ������ ���´�.
	UFUNCTION( BlueprintCallable )
	void DisconnectFromGameServer();

	/// ���� ��Ŷ�� ó���Ѵ�.
	UFUNCTION( BlueprintCallable )
	void HandleRecvPackets();

	/// ��Ŷ�� �����Ѵ�.
	void SendPacket( SendBufferPtr SendBuffer );

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT( "192.168.25.22" );
	int16 Port        = 7777;

	TSharedPtr< class PacketSession > GameServerSession;
};
