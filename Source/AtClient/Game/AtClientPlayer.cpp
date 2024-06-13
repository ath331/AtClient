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
// @brief 생성자
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

	m_playerInfo = new Protocol::PlayerInfo;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 소멸자
////////////////////////////////////////////////////////////////////////////////////////////////////
AAtClientPlayer::~AAtClientPlayer()
{
	if ( m_playerInfo )
	{
		delete m_playerInfo;
		m_playerInfo = nullptr;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 플레이어 정보를 세팅한다.
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
// @brief 나인지 확인한다.
////////////////////////////////////////////////////////////////////////////////////////////////////
bool AAtClientPlayer::IsMyPlayer()
{
	return Cast< AAtClientMyPlayer >( this ) != nullptr;
}

void AAtClientPlayer::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 프레임마다 호출되는 함수
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientPlayer::Tick( float deltaTime )
{
	Super::Tick( deltaTime );

	FVector location = GetActorLocation();
	m_playerInfo->set_x  ( location.X               );
	m_playerInfo->set_y  ( location.Y               );
	m_playerInfo->set_z  ( location.Z               );
	m_playerInfo->set_yaw( GetControlRotation().Yaw );
}
