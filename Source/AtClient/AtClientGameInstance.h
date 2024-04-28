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
	/// 서버에 연결한다.
	UFUNCTION( BlueprintCallable )
	void ConnectToGameServer();

	/// 서버와 연결을 끊는다.
	UFUNCTION( BlueprintCallable )
	void DisconnectFromGameServer();

	/// 받은 패킷을 처리한다.
	UFUNCTION( BlueprintCallable )
	void HandleRecvPackets();

	/// 패킷을 전송한다.
	void SendPacket( SendBufferPtr SendBuffer );

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT( "192.168.25.22" );
	int16 Port        = 7777;

	TSharedPtr< class PacketSession > GameServerSession;
};
