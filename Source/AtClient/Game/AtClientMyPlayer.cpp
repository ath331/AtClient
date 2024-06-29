// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/AtClientMyPlayer.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "AtClient.h"
#include "Kismet/KismetMathLibrary.h"


//////////////////////////////////////////////////////////////////////////
// AAtClientMyPlayer

AAtClientMyPlayer::AAtClientMyPlayer()
{
	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>( TEXT( "CameraBoom" ) );
	CameraBoom->SetupAttachment( RootComponent );
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>( TEXT( "FollowCamera" ) );
	FollowCamera->SetupAttachment( CameraBoom, USpringArmComponent::SocketName ); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void AAtClientMyPlayer::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if ( APlayerController* PlayerController = Cast<APlayerController>( Controller ) )
	{
		if ( UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>( PlayerController->GetLocalPlayer() ) )
		{
			Subsystem->AddMappingContext( DefaultMappingContext, 0 );
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// @brief 프레임마다 호출되는 함수
////////////////////////////////////////////////////////////////////////////////////////////////////
void AAtClientMyPlayer::Tick( float deltaTime )
{
	Super::Tick( deltaTime );

	// Send 판정
	bool forceSendPacket = false;

	if ( lastDesiredInput != desiredInput )
	{
		forceSendPacket = true;
		lastDesiredInput = desiredInput;
	}

	if ( desiredInput == FVector2D::Zero() )
		SetMoveState( Protocol::MOVE_STATE_IDLE );
	else
		SetMoveState( Protocol::MOVE_STATE_RUN );

	m_movePacketSendTimer -= deltaTime;

	if ( m_movePacketSendTimer <= 0 || forceSendPacket )
	{
		Protocol::C_Move movePkt;
		Protocol::PosInfo* posInfo =  movePkt.mutable_info();
		posInfo->CopyFrom( *m_posInfo );
		posInfo->set_yaw( desiredYaw );
		posInfo->set_move_state( GetMoveState() );

		SEND_PACKET( movePkt );

		m_movePacketSendTimer = MOVE_PACKET_SEND_DELAY;
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AAtClientMyPlayer::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
	// Set up action bindings
	if ( UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>( PlayerInputComponent ) )
	{

		// Jumping
		EnhancedInputComponent->BindAction( JumpAction, ETriggerEvent::Started,   this, &ACharacter::Jump        );
		EnhancedInputComponent->BindAction( JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping );

		// Moving
		EnhancedInputComponent->BindAction( MoveAction, ETriggerEvent::Triggered, this, &AAtClientMyPlayer::Move );
		EnhancedInputComponent->BindAction( MoveAction, ETriggerEvent::Completed, this, &AAtClientMyPlayer::Move );

		// Looking
		EnhancedInputComponent->BindAction( LookAction, ETriggerEvent::Triggered, this, &AAtClientMyPlayer::Look );
	}
	// else
	// {
	// 	UE_LOG( LogTemplateCharacter, Error, TEXT( "'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file." ), *GetNameSafe( this ) );
	// }
}

void AAtClientMyPlayer::Move( const FInputActionValue& Value )
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if ( Controller != nullptr )
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation( 0, Rotation.Yaw, 0 );

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::X );

		// get right vector 
		const FVector RightDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::Y );

		// add movement 
		AddMovementInput( ForwardDirection, MovementVector.Y );
		AddMovementInput( RightDirection, MovementVector.X );

		// Cache
		{
			desiredInput = MovementVector;

			desiredMoveDirection = FVector::ZeroVector;
			desiredMoveDirection += ForwardDirection * MovementVector.Y;
			desiredMoveDirection += RightDirection * MovementVector.X;
			desiredMoveDirection.Normalize();

			const FVector location = GetActorLocation();
			FRotator rotator = UKismetMathLibrary::FindLookAtRotation( location, location + desiredMoveDirection );
			desiredYaw = rotator.Yaw;
		}
	}
}

void AAtClientMyPlayer::Look( const FInputActionValue& Value )
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if ( Controller != nullptr )
	{
		// add yaw and pitch input to controller
		AddControllerYawInput( LookAxisVector.X );
		AddControllerPitchInput( LookAxisVector.Y );
	}
}