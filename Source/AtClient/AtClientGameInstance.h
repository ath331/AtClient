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
	/// �����Ѵ�.
	void HandleSpawn( const Protocol::PlayerInfo& PlayerInfo, bool isMyPlayer );

	/// �����Ѵ�.
	void HandleSpawn( const Protocol::S_EnterGame& EnterGamePkt );

	/// �����Ѵ�.
	void HandleSpawn( const Protocol::S_Spawn& SpawnPkt );

	/// �����Ѵ�.
	void HandleDeSpawn( uint64 ObjectId );

	/// �����Ѵ�.
	void HandleDeSpawn( const Protocol::S_DeSpawn& DespawnPkt );

	/// Move�Ѵ�.
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
