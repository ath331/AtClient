#include "ServerPacketHandler.h"
#include "Packet/BufferReader.h"


PacketHandlerFunc GPacketHandler[UINT16_MAX];


bool Handle_INVALID( PacketSessionPtr& session, BYTE* buffer, int32 len )
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	return false;
}
