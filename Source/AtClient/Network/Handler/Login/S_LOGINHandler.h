////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif S_LOGINHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include "AtClient.h"
#include "Network/Protocol.pb.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif S_LOGINHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////
class S_LOGINHandler
{
public:
	// HandlerRun
	static bool Handle( PacketSessionPtr& session, Protocol::S_Login& pkt );
};