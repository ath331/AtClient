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
	/// �÷��̾� ����
	class Protocol::PlayerInfo* m_playerInfo;

public:
	/// ������
	AAtClientPlayer();

	/// �Ҹ���
	virtual ~AAtClientPlayer();

	/// �÷��̾� ������ �����Ѵ�.
	void SetPlayerInfo( const Protocol::PlayerInfo& playerInfo );

	/// �÷��̾� ������ ��ȯ�Ѵ�.
	Protocol::PlayerInfo* GetPlayerInfo() { return m_playerInfo; }

	/// ������ Ȯ���Ѵ�.
	bool IsMyPlayer();

protected:
	virtual void BeginPlay();

	/// �����Ӹ��� ȣ��Ǵ� �Լ�
	virtual void Tick( float deltaTime ) override;
};
