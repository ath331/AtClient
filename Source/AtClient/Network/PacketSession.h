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
	/// ������
	PacketSession( class FSocket* Socket );

	/// �Ҹ���
	~PacketSession();

	/// ������ ���۽�Ų��.
	void Run();

	/// ���� ������ ���´�.
	void Disconnect();

public:
	/// ����
	class FSocket* Socket;
};
