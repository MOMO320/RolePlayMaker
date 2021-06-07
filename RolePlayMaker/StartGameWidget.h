// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RolePlayMaker.h"
#include "Blueprint/UserWidget.h"
#include "StartGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROLEPLAYMAKER_API UStartGameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnGameStartClicked();


protected:
	UPROPERTY()
		class UButton* GameStartButton;
	
};
