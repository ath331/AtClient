////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif S_EnterGameHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////


//#include "pch.h"
#include "S_EnterGameHandler.h"
#include "AtClientGameInstance.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif HandlerRun
////////////////////////////////////////////////////////////////////////////////////////////////////
bool S_EnterGameHandler::Handle( PacketSessionPtr& session, Protocol::S_EnterGame& pkt )
{
	if ( auto* gameInstance = Cast< UAtClientGameInstance >( GWorld->GetGameInstance() ) )
	{
		gameInstance->HandleSpawn( pkt );
	}

	return true;
}