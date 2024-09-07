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
	/// �÷��̾� ���� ��ġ
	class Protocol::PosInfo* m_posInfo;

	/// �÷��̾� ���� ���� ��ġ
	class Protocol::PosInfo* m_destPosInfo;

public:
	/// ������
	AAtClientPlayer();

	/// �Ҹ���
	virtual ~AAtClientPlayer();

	/// �÷��̾� ������ �����Ѵ�.
	void SetPosInfo( const Protocol::PosInfo& posInfo );

	/// ���� ��ġ�� �÷��̾� ������ �����Ѵ�.
	void SetDestPosInfo( const Protocol::PosInfo& posInfo );

	/// MoveState�� ��ȯ�Ѵ�.
	Protocol::EMoveState GetMoveState();

	/// MoveState�� �����Ѵ�.
	void SetMoveState( Protocol::EMoveState state );

	/// �÷��̾� ��ġ�� ��ȯ�Ѵ�.
	Protocol::PosInfo* GetPlayerInfo() { return m_posInfo; }

	/// ������ Ȯ���Ѵ�.
	bool IsMyPlayer();

protected:
	virtual void BeginPlay();

	/// �����Ӹ��� ȣ��Ǵ� �Լ�
	virtual void Tick( float deltaTime ) override;
};
