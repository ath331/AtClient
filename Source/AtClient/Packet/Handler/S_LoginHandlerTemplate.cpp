////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif Client use handler. !!Auto Make File!!
////////////////////////////////////////////////////////////////////////////////////////////////////


//#include "pch.h"
#include "ServerPacketHandler.h"
#include "Login/S_LoginHandler.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif HandlerRun
////////////////////////////////////////////////////////////////////////////////////////////////////
bool Handle_S_LoginTemplate( PacketSessionPtr& session, Protocol::S_Login& pkt )
{
	return S_LoginHandler::Handle( session, pkt );
}