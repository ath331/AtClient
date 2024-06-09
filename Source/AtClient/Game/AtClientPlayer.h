// Fill out your copyright notice in the Description page of Project Settings.


#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
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

public:
	AAtClientPlayer();
	
protected:
	virtual void BeginPlay();
};
