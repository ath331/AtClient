////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief UAtClientGameInstance Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AtClient.h"
#include "AtClientGameInstance.generated.h"


class AAtClientPlayer;


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
	/// 스폰한다.
	void HandleSpawn( const Protocol::PlayerInfo& PlayerInfo, bool isMyPlayer );

	/// 스폰한다.
	void HandleSpawn( const Protocol::S_EnterGame& EnterGamePkt );

	/// 스폰한다.
	void HandleSpawn( const Protocol::S_Spawn& SpawnPkt );

	/// 디스폰한다.
	void HandleDeSpawn( uint64 ObjectId );

	/// 디스폰한다.
	void HandleDeSpawn( const Protocol::S_DeSpawn& DespawnPkt );

	/// Move한다.
	void HandleMove( const Protocol::S_Move& movePkt );

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT( "192.168.25.22" );
	int16 Port        = 7777;

	TSharedPtr< class PacketSession > GameServerSession;

public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AAtClientPlayer> OtherPlayerClass;

	AAtClientPlayer* myPlayer;
	TMap<uint64, AAtClientPlayer*> Players;
};
