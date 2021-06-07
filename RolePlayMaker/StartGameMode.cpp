// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameMode.h"
#include "StartMapCamera.h"
#include "GameStartPlayerController.h"


AStartGameMode::AStartGameMode()
{
	DefaultPawnClass = AStartMapCamera::StaticClass();
	PlayerControllerClass = AGameStartPlayerController::StaticClass();
}