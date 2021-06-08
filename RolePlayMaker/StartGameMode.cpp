// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameMode.h"
#include "StartMapCameraPawn.h"
#include "GameStartPlayerController.h"


AStartGameMode::AStartGameMode()
{
	DefaultPawnClass = AStartMapCameraPawn::StaticClass();
	PlayerControllerClass = AGameStartPlayerController::StaticClass();
}