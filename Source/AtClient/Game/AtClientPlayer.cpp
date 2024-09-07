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

	m_posInfo     = new Protocol::PosInfo();
	m_destPosInfo = new Protocol::PosInfo();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �Ҹ���
////////////////////////////////////////////////////////////////////////////////////////////////////
AAtClientPlayer::~AAtClientPlayer()
{
	if ( m_posInfo )
	{
		delete m_posInfo;
		m_posInfo = nullptr;
	}

	if ( m_destPosInfo )
	{
		delete m_destPosInfo;
		m_destPosInfo = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief �÷��̾� ������ �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::SetPosInfo( const Protocol::PosInfo& posInfo )
{
	if ( m_posInfo->id() != 0 )
		assert( m_posInfo->id() == posInfo.id() );

	m_posInfo->CopyFrom( posInfo );

	FVector Location( posInfo.x(),
					  posInfo.y(),
					  posInfo.z() );

	SetActorLocation( Location );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief ���� ��ġ�� �÷��̾� ������ �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::SetDestPosInfo( const Protocol::PosInfo& posInfo )
{
	if ( m_destPosInfo->id() != 0 )
		assert( m_destPosInfo->id() == posInfo.id() );

	m_destPosInfo->CopyFrom( posInfo );

	SetMoveState( posInfo.move_state() );
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief MoveState�� ��ȯ�Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
Protocol::EMoveState AAtClientPlayer::GetMoveState()
{
	return m_posInfo->move_state();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief MoveState�� �����Ѵ�.
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::SetMoveState( Protocol::EMoveState state )
{
	if ( m_posInfo->move_state() == state )
		return;

	m_posInfo->set_move_state( state );
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
		m_destPosInfo->set_x( location.X );
		m_destPosInfo->set_y( location.Y );
		m_destPosInfo->set_z( location.Z );
		m_destPosInfo->set_yaw( GetControlRotation().Yaw );

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
		m_posInfo->set_x( location.X );
		m_posInfo->set_y( location.Y );
		m_posInfo->set_z( location.Z );
		m_posInfo->set_yaw( GetControlRotation().Yaw );
	}

	if ( !IsMyPlayer() )
	{
		// �ִϸ��̼� ó�� �� �Ǵ� �ҽ�
		/*FVector location = GetActorLocation();
		FVector destLocation = FVector(
			m_destPosInfo->x(),
			m_destPosInfo->y(),
			m_destPosInfo->z() );

		FVector moveDir = destLocation - location;
		const float distToDest = moveDir.Length();
		moveDir.Normalize();

		float moveDist = ( moveDir * 600.f * deltaTime ).Length();
		moveDist = FMath::Min( moveDist, distToDest );
		FVector nextLocation = location + moveDir * moveDist;

		SetActorLocation( nextLocation );*/

		if ( m_posInfo->move_state() == Protocol::MOVE_STATE_RUN )
		{
			SetActorRotation( FRotator( 0, m_destPosInfo->yaw(), 0 ) );
			AddMovementInput( GetActorForwardVector() );
		}
		else
		{

		}
	}
}
