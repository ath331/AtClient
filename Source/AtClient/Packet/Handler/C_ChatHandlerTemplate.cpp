////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif Client use handler. !!Auto Make File!!
////////////////////////////////////////////////////////////////////////////////////////////////////


//#include "pch.h"
#include "ServerPacketHandler.h"
#include "Chat/C_ChatHandler.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif HandlerRun
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Handle_C_ChatTemplate( PacketSessionPtr& session, Protocol::C_Chat& pkt )
{
	return C_ChatHandler::Handle( session, pkt );
}