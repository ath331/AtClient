// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "Packet/Protocol.pb.h"
#include "AtClientPlayer.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


UCLASS()
class ATCLIENT_API AAtClientPlayer : public ACharacter
{
	GENERATED_BODY()

protected:
	/// 플레이어 정보
	class Protocol::PlayerInfo* m_playerInfo;

public:
	/// 생성자
	AAtClientPlayer();

	/// 소멸자
	virtual ~AAtClientPlayer();

	/// 플레이어 정보를 세팅한다.
	void SetPlayerInfo( const Protocol::PlayerInfo& playerInfo );

	/// 플레이어 정보를 반환한다.
	Protocol::PlayerInfo* GetPlayerInfo() { return m_playerInfo; }

	/// 나인지 확인한다.
	bool IsMyPlayer();

protected:
	virtual void BeginPlay();

	/// 프레임마다 호출되는 함수
	virtual void Tick( float deltaTime ) override;
};
