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
