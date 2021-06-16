// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameMode.h"
#include "StartMapCameraPawn.h"
#include "GameStartPlayerController.h"
#include "PlayerCharacterState.h"


AStartGameMode::AStartGameMode()
{
	DefaultPawnClass = AStartMapCameraPawn::StaticClass();
	PlayerControllerClass = AGameStartPlayerController::StaticClass();
	PlayerStateClass = APlayerCharacterState::StaticClass();
}

void AStartGameMode::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AStartGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	auto PlayerCharacterState = Cast<APlayerCharacterState>(NewPlayer->PlayerState);
}
