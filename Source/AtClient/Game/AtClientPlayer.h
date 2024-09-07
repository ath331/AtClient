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
	/// 플레이어 현재 위치
	class Protocol::PosInfo* m_posInfo;

	/// 플레이어 다음 예정 위치
	class Protocol::PosInfo* m_destPosInfo;

public:
	/// 생성자
	AAtClientPlayer();

	/// 소멸자
	virtual ~AAtClientPlayer();

	/// 플레이어 정보를 세팅한다.
	void SetPosInfo( const Protocol::PosInfo& posInfo );

	/// 다음 위치의 플레이어 정보를 세팅한다.
	void SetDestPosInfo( const Protocol::PosInfo& posInfo );

	/// MoveState를 반환한다.
	Protocol::EMoveState GetMoveState();

	/// MoveState를 세팅한다.
	void SetMoveState( Protocol::EMoveState state );

	/// 플레이어 위치를 반환한다.
	Protocol::PosInfo* GetPlayerInfo() { return m_posInfo; }

	/// 나인지 확인한다.
	bool IsMyPlayer();

protected:
	virtual void BeginPlay();

	/// 프레임마다 호출되는 함수
	virtual void Tick( float deltaTime ) override;
};
