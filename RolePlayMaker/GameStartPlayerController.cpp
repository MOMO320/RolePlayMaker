// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStartPlayerController.h"
#include "StartGameWidget.h"
#include "StartMapCameraPawn.h"

AGameStartPlayerController::AGameStartPlayerController()
{
	static ConstructorHelpers::FClassFinder<UStartGameWidget> UI_GAMESTART_C(TEXT("/Game/UI/Start_Widget.Start_Widget_C"));
	if (UI_GAMESTART_C.Succeeded())
	{
		StartGameWidgetClass = UI_GAMESTART_C.Class;
	}

}

void AGameStartPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	StartGameWidget = CreateWidget<UStartGameWidget>(this, StartGameWidgetClass);
}


void AGameStartPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ChangeInputMode(false);

	if (StartGameWidget != nullptr)
	{
		StartGameWidget->AddToViewport();
	}
}

void AGameStartPlayerController::ChangeInputMode(bool bGameMode)
{
	if (bGameMode)
	{
		SetInputModeChange(GameInputMode, bGameMode);
	}
	else
	{
		SetInputModeChange(UIInputMode, bGameMode);
	}
}

void AGameStartPlayerController::SetStartWidgetCameraPawn(class AStartMapCameraPawn* currenPawn) const
{
	if (StartGameWidget != nullptr)
	{
		StartGameWidget->BindCameraPawn(currenPawn);
	}
}

void AGameStartPlayerController::SetInputModeChange(FInputModeDataBase& inputMode, bool bGameMode)
{
	SetInputMode(inputMode);
	bShowMouseCursor = !bGameMode;
}
