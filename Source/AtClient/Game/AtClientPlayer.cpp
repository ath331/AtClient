// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AtClientPlayer.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "AtClientMyPlayer.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ������
////////////////////////////////////////////////////////////////////////////////////////////////////
AAtClientPlayer::AAtClientPlayer()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize( 42.f, 96.0f );

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator( 0.0f, 500.0f, 0.0f ); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	GetCharacterMovement()->bRunPhysicsWithNoController = true;

	m_playerInfo     = new Protocol::PlayerInfo;
	m_destPlayerInfo = new Protocol::PlayerInfo;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �Ҹ���
////////////////////////////////////////////////////////////////////////////////////////////////////
AAtClientPlayer::~AAtClientPlayer()
{
	if ( m_playerInfo )
	{
		delete m_playerInfo;
		m_playerInfo = nullptr;
	}

	if ( m_destPlayerInfo )
	{
		delete m_destPlayerInfo;
		m_destPlayerInfo = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �÷��̾� ������ �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::SetPlayerInfo( const Protocol::PlayerInfo& playerInfo )
{
	if ( m_playerInfo->id() != 0 )
		assert( m_playerInfo->id() == playerInfo.id() );

	m_playerInfo->CopyFrom( playerInfo );

	FVector Location( playerInfo.x(), playerInfo.y(), playerInfo.z() );
	SetActorLocation( Location );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ���� ��ġ�� �÷��̾� ������ �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::SetDestPlayerInfo( const Protocol::PlayerInfo& playerInfo )
{
	if ( m_destPlayerInfo->id() != 0 )
		assert( m_destPlayerInfo->id() == playerInfo.id() );

	m_destPlayerInfo->CopyFrom( playerInfo );

	SetMoveState( playerInfo.movestate() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief MoveState�� ��ȯ�Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
Protocol::MoveState AAtClientPlayer::GetMoveState()
{
	return m_playerInfo->movestate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief MoveState�� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::SetMoveState( Protocol::MoveState state )
{
	if ( m_playerInfo->movestate() == state )
		return;

	m_playerInfo->set_movestate( state );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ������ Ȯ���Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
bool AAtClientPlayer::IsMyPlayer()
{
	return Cast< AAtClientMyPlayer >( this ) != nullptr;
}

void AAtClientPlayer::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	{
		FVector location = GetActorLocation();
		m_destPlayerInfo->set_x( location.X );
		m_destPlayerInfo->set_y( location.Y );
		m_destPlayerInfo->set_z( location.Z );
		m_destPlayerInfo->set_yaw( GetControlRotation().Yaw );

		SetMoveState( Protocol::MOVE_STATE_IDLE );
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �����Ӹ��� ȣ��Ǵ� �Լ�
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::Tick( float deltaTime )
{
	Super::Tick( deltaTime );

	{
		FVector location = GetActorLocation();
		m_playerInfo->set_x( location.X );
		m_playerInfo->set_y( location.Y );
		m_playerInfo->set_z( location.Z );
		m_playerInfo->set_yaw( GetControlRotation().Yaw );
	}

	if ( !IsMyPlayer() )
	{
		// �ִϸ��̼� ó�� �� �Ǵ� �ҽ�
		/*FVector location = GetActorLocation();
		FVector destLocation = FVector(
			m_destPlayerInfo->x(),
			m_destPlayerInfo->y(),
			m_destPlayerInfo->z() );

		FVector moveDir = destLocation - location;
		const float distToDest = moveDir.Length();
		moveDir.Normalize();

		float moveDist = ( moveDir * 600.f * deltaTime ).Length();
		moveDist = FMath::Min( moveDist, distToDest );
		FVector nextLocation = location + moveDir * moveDist;

		SetActorLocation( nextLocation );*/

		if ( m_playerInfo->movestate() == Protocol::MOVE_STATE_RUN )
		{
			SetActorRotation( FRotator( 0, m_destPlayerInfo->yaw(), 0 ) );
			AddMovementInput( GetActorForwardVector() );
		}
		else
		{

		}
	}
}
