////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif S_MoveHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include "AtClient.h"
#include "Packet/Protocol.pb.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif S_MoveHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////
class S_MoveHandler
{
public:
	// HandlerRun
	static bool Handle( PacketSessionPtr& session, Protocol::S_Move& pkt );
};