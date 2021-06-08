// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameWidget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>
#include "StartMapCameraPawn.h"


void UStartGameWidget::BindCameraPawn(AStartMapCameraPawn* CurrentCameraPawn)
{
	CameraPawn = CurrentCameraPawn;
}

void UStartGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameStartButton = Cast<UButton>(GetWidgetFromName(TEXT("sys_GameStartBtn")));
	
	if (nullptr != GameStartButton)
	{
		GameStartButton->OnClicked.AddDynamic(this, &UStartGameWidget::OnGameStartClicked);
	}
}

void UStartGameWidget::OnGameStartClicked()
{
	CameraPawn->ChangeCamera();
}
