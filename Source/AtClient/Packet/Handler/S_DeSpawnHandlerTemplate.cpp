////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif Client use handler. !!Auto Make File!!
////////////////////////////////////////////////////////////////////////////////////////////////////


//#include "pch.h"
#include "ServerPacketHandler.h"
#include "Spawn/S_DeSpawnHandler.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif HandlerRun
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Handle_S_DeSpawnTemplate( PacketSessionPtr& session, Protocol::S_DeSpawn& pkt )
{
	return S_DeSpawnHandler::Handle( session, pkt );
}