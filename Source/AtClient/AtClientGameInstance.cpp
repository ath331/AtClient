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
#include "Packet/Protocol.pb.h"
#include "Packet/Handler/ServerPacketHandler.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ������ �����Ѵ�.
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
// @brief ������ ������ ���´�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::DisconnectFromGameServer()
{
	if ( Socket )
	{
		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
		SocketSubsystem->DestroySocket( Socket );
		Socket = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ���� ��Ŷ�� ó���Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleRecvPackets()
{
	if ( !Socket || !GameServerSession )
		return;

	GameServerSession->HandleRecvPackets();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ��Ŷ�� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::SendPacket( SendBufferPtr SendBuffer )
{
	if ( !Socket || !GameServerSession )
		return;

	GameServerSession->SendPacket( SendBuffer );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleSpawn( const Protocol::PlayerInfo& PlayerInfo )
{
	if ( Socket == nullptr || GameServerSession == nullptr )
		return;

	auto* World = GetWorld();
	if ( World == nullptr )
		return;

	// �ߺ� ó�� üũ
	const uint64 ObjectId = PlayerInfo.id();
	if ( Players.Find( ObjectId ) != nullptr )
		return;

	FVector SpawnLocation( PlayerInfo.x(), PlayerInfo.y(), PlayerInfo.z() );
	AActor* Actor = World->SpawnActor( PlayerClass, &SpawnLocation );

	Players.Add( PlayerInfo.id(), Actor );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleSpawn( const Protocol::S_EnterGame& EnterGamePkt )
{
	HandleSpawn( EnterGamePkt.player() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleSpawn( const Protocol::S_Spawn& SpawnPkt )
{
	for ( auto& Player : SpawnPkt.players() )
	{
		HandleSpawn( Player );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleDespawn( uint64 ObjectId )
{
	if ( Socket == nullptr || GameServerSession == nullptr )
		return;

	auto* World = GetWorld();
	if ( World == nullptr )
		return;

	AActor** FindActor = Players.Find( ObjectId );
	if ( FindActor == nullptr )
		return;

	World->DestroyActor( *FindActor );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void UAtClientGameInstance::HandleDespawn( const Protocol::S_DeSpawn& DespawnPkt )
{
	for ( auto& ObjectId : DespawnPkt.ids() )
	{
		HandleDespawn( ObjectId );
	}
}
