////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif C_LeaveGameHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include "AtClient.h"
#include "Packet/Protocol.pb.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif C_LeaveGameHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////
class C_LeaveGameHandler
{
public:
	// HandlerRun
	static bool Handle( PacketSessionPtr& session, Protocol::C_LeaveGame& pkt );
};
