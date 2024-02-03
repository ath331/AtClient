////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief UAtClientGameInstance Class
////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma once


#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AtClientGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class ATCLIENT_API UAtClientGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// ������ �����Ѵ�.
	UFUNCTION( BlueprintCallable )
	void ConnectToGameServer();

	// ������ ������ ���´�.
	UFUNCTION( BlueprintCallable )
	void DisconnectFromGameServer();

public:
	// GameServer
	class FSocket* Socket;
	FString IpAddress = TEXT( "127.0.0.1" );
	int16 Port = 7777;


};
