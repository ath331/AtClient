////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief UAtClientGameInstance Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#include "AtClientGameInstance.h"
#include "Sockets.h"
#include "Common/TcpSocketBuilder.h"
#include "Serialization/ArrayWriter.h"
#include "SocketSubsystem.h"


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

		// Session
		// GameServerSession = MakeShared< PacketSession >( Socket );
		// GameServerSession->Run();
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
	if ( Socket )
	{
		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
		SocketSubsystem->DestroySocket( Socket );
		Socket = nullptr;
	}
}
