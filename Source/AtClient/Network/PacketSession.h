////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief PacketSession Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"


/**
 * 
 */
class ATCLIENT_API PacketSession : public TSharedFromThis< PacketSession >
{
public:
	/// 생성자
	PacketSession( class FSocket* Socket );

	/// 소멸자
	~PacketSession();

	/// 세션을 동작시킨다.
	void Run();

	/// 세션 연결을 끊는다.
	void Disconnect();

public:
	/// 소켓
	class FSocket* Socket;
};
