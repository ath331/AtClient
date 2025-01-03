////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif C_EnterGameHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include "AtClient.h"
#include "Packet/Protocol.pb.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif C_EnterGameHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////
class C_EnterGameHandler
{
public:
	// HandlerRun
	static bool Handle( PacketSessionPtr& session, Protocol::C_EnterGame& pkt );
};
