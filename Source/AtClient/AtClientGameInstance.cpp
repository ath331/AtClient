////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief UAtClientGameInstance Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "AtClientGameInstance.h"
#include "Sockets.h"
#include "Common/TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"
#include "PacketSession.h"
#include "Engine.h"
#include "Game/AtClientMyPlayer.h"
#include "Packet/Protocol.pb.h"
#include "Packet/Handler/ServerPacketHandler.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 서버에 연결한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::ConnectToGameServer()
{
	Socket = ISocketSubsystem::Get( PLATFORM_SOCKETSUBSYSTEM )->CreateSocket( TEXT( "Stream" ), TEXT( "Client Socket" ) );

	FIPv4Address Ip;
	FIPv4Address::Parse( IpAddress, Ip );

	TSharedRef< FInternetAddr > InternetAddr = ISocketSubsystem::Get( PLATFORM_SOCKETSUBSYSTEM )->CreateInternetAddr();
	InternetAddr->SetIp( Ip.Value );
	InternetAddr->SetPort( Port );

	GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, FString::Printf( TEXT( "Connecting To Server..." ) ) );

	bool Connected = Socket->Connect( *InternetAddr );

	if ( Connected )
	{
		GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, FString::Printf( TEXT( "Connection Success" ) ) );

		GameServerSession = MakeShared< PacketSession >( Socket );
		GameServerSession->Run();

		{
			Protocol::C_Login pkt;
			SendBufferPtr sendBuffer = ServerPacketHandler::MakeSendBuffer( pkt );
			SendPacket( sendBuffer );
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage( -1, 5.f, FColor::Red, FString::Printf( TEXT( "Connection Failed" ) ) );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 서버와 연결을 끊는다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::DisconnectFromGameServer()
{ 
	if ( !Socket || !GameServerSession )
		return;

	Protocol::C_LeaveGame pkt;
	SEND_PACKET( pkt );

	// if ( Socket )
	// {
	// 	ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
	// 	SocketSubsystem->DestroySocket( Socket );
	// 	Socket = nullptr;
	// }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 받은 패킷을 처리한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleRecvPackets()
{
	if ( !Socket || !GameServerSession )
		return;

	GameServerSession->HandleRecvPackets();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 패킷을 전송한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::SendPacket( SendBufferPtr SendBuffer )
{
	if ( !Socket || !GameServerSession )
		return;

	GameServerSession->SendPacket( SendBuffer );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 스폰한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleSpawn( const Protocol::PlayerInfo& PlayerInfo, bool isMyPlayer )
{
	if ( Socket == nullptr || GameServerSession == nullptr )
		return;

	auto* World = GetWorld();
	if ( World == nullptr )
		return;

	// 중복 처리 체크
	const uint64 ObjectId = PlayerInfo.id();
	if ( Players.Find( ObjectId ) != nullptr )
		return;

	FVector SpawnLocation( PlayerInfo.x(), PlayerInfo.y(), PlayerInfo.z() );

	if ( isMyPlayer )
	{
		auto* PC = UGameplayStatics::GetPlayerController( this, 0 );
		AAtClientPlayer* player = Cast< AAtClientPlayer >( PC->GetPawn() );
		if ( !player )
			return;

		myPlayer = player;
		Players.Add( PlayerInfo.id(), player );
	}
	else
	{
		AAtClientPlayer* Player = Cast< AAtClientPlayer>( World->SpawnActor( OtherPlayerClass, &SpawnLocation ) );
		Players.Add( PlayerInfo.id(), Player );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 스폰한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleSpawn( const Protocol::S_EnterGame& EnterGamePkt )
{
	HandleSpawn( EnterGamePkt.player(), true );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 스폰한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleSpawn( const Protocol::S_Spawn& SpawnPkt )
{
	for ( auto& Player : SpawnPkt.players() )
	{
		HandleSpawn( Player, false );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 디스폰한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleDeSpawn( uint64 ObjectId )
{
	if ( Socket == nullptr || GameServerSession == nullptr )
		return;

	auto* World = GetWorld();
	if ( World == nullptr )
		return;

	AAtClientPlayer** FindActor = Players.Find( ObjectId );
	if ( FindActor == nullptr )
		return;

	World->DestroyActor( *FindActor );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 디스폰한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleDeSpawn( const Protocol::S_DeSpawn& DespawnPkt )
{
	for ( auto& ObjectId : DespawnPkt.ids() )
	{
		HandleDeSpawn( ObjectId );
	}
}
