// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectWidget.generated.h"

UENUM(BlueprintType)
enum class ECharacterSlot : uint8
{
	SLOT1,
	SLOT2
};

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

	UFUNCTION()
		void OnSlot1CharacterSetClicked();

	UFUNCTION()
		void OnSlot2CharacterSetClicked();

private:
	void SetSlotData();

	void SetCharacterModel(ECharacterSlot CurrentSlot);

	void CharacterSlotCheck(TArray<class UCanvasPanel*> CharacterSlotPanel ,class  UPlayerSaveGame* PlayerSaveData);

protected:
	UPROPERTY()
		TArray<class UCanvasPanel*> CharacterSlot1Panel;

	UPROPERTY()
		TArray<class UCanvasPanel*> CharacterSlot2Panel;

	UPROPERTY()
		TArray<class UButton*> DisableSlotButtons;

	UPROPERTY()
		class UButton* EnableSlot1Button;


	UPROPERTY()
		class UButton* EnableSlot2Button;

	UPROPERTY()
		class UButton* GameStartButton;


private:

	UPROPERTY(EditAnywhere)
	ECharacterSlot ChoiceSlot;
};
