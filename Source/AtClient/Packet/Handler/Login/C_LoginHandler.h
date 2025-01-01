////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif C_LoginHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once
#include "AtClient.h"
#include "Packet/Protocol.pb.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @breif C_LoginHandler class
////////////////////////////////////////////////////////////////////////////////////////////////////
class C_LoginHandler
{
public:
	// HandlerRun
	static bool Handle( PacketSessionPtr& session, Protocol::C_Login& pkt );
};