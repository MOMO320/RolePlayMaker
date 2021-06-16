// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RolePlayMaker.h"
#include "GameFramework/PlayerController.h"
#include "GameStartPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ROLEPLAYMAKER_API AGameStartPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	AGameStartPlayerController();
	
	void ChangeInputMode(bool bGameMode = true);
	void SetStartWidgetCameraPawn(class AStartMapCameraPawn* currenPawn) const;
	void ViewCharacterSelectWidget();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* aPawn) override;

private:
	void SetInputModeChange(FInputModeDataBase& inputMode ,bool bGameMode);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UStartGameWidget> StartGameWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
		TSubclassOf<class UCharacterSelectWidget> CharacterSelectWidgetClass;
		
private:
	UPROPERTY()
		class UStartGameWidget* StartGameWidget;

	UPROPERTY()
		class UCharacterSelectWidget* CharacterSelectWidget;

	FInputModeUIOnly UIInputMode;
	FInputModeGameOnly GameInputMode;
};
