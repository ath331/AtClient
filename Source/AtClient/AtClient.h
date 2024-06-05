////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief  AtClient.h
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"


struct PacketHeader
{
	uint16 size;
	uint16 id; // 프로토콜ID (ex. 1=로그인, 2=이동요청)
};

class SendBuffer : public TSharedFromThis< SendBuffer >
{
public:
	SendBuffer( int32 bufferSize );
	~SendBuffer();

	BYTE* Buffer()    { return _buffer.GetData(); }
	int32 WriteSize() { return _writeSize; }
	int32 Capacity()  { return static_cast< int32 >( _buffer.Num() ); }

	void CopyData( void* data, int32 len );
	void Close   ( uint32 writeSize      );

private:
	TArray< BYTE >	_buffer;
	int32			_writeSize = 0;
};

#define USING_SHARED_PTR(name)	using name##Ptr = TSharedPtr< class name >;

USING_SHARED_PTR( Session );
USING_SHARED_PTR( PacketSession );
USING_SHARED_PTR( SendBuffer );


#include "Packet/Handler/ServerPacketHandler.h"
#include "AtClientGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#define SEND_PACKET( pkt ) \
	SendBufferPtr sendBuffer = ServerPacketHandler::MakeSendBuffer( pkt ); \
	Cast< UAtClientGameInstance >( GWorld->GetGameInstance() )->SendPacket( sendBuffer );