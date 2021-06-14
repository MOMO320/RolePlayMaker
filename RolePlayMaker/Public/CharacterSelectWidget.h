// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectWidget.generated.h"

/**
 * 
 */
UCLASS()
class ROLEPLAYMAKER_API UCharacterSelectWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetCharacterSlot(class UPlayerSaveGame* PlayerSaveData , class UText*  PlayerName , class UText* PlayerLevel);

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnCreateCharacterClicked();

	UFUNCTION()
		void OnGameStartClicked();

private:
	void SetSlotData();

protected:
	UPROPERTY()
		TArray<class UCanvasPanel*> CharacterSlot1Panel;

	UPROPERTY()
		TArray<class UCanvasPanel*> CharacterSlot2Panel;

	UPROPERTY()
		TArray<class UButton*> DisableSlotButtons;

	UPROPERTY()
		TArray<class UButton*> EnableSlotButtons;

	UPROPERTY()
		class UButton* GameStartButton;

	
};
