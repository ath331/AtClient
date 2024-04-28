// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Protocol.pb.h"
#include "AtClientGameInstance.h"
#include "ServerPacketHandler.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	Protocol::C_CHAT msg;
	msg.set_msg( "hello Server" );

	SendBufferPtr sendBufferPtr = ServerPacketHandler::MakeSendBuffer( msg );
	Cast< UAtClientGameInstance >( GetGameInstance() )->SendPacket( sendBufferPtr );
}

