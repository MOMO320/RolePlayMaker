// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterSelectWidget.h"
#include "Components/Button.h"
#include <Kismet/GameplayStatics.h>
#include "Components/CanvasPanel.h"


void UCharacterSelectWidget::SetCharacterSlot(class UPlayerSaveGame* PlayerSaveData, class UText* PlayerName, class UText* PlayerLevel)
{

}

void UCharacterSelectWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ChoiceSlot = ECharacterSlot::SLOT1;
	
	CharacterSlot1Panel.Add(Cast<UCanvasPanel>(GetWidgetFromName(TEXT("sys_Disable_Character_Slot1"))));
	CharacterSlot1Panel.Add(Cast<UCanvasPanel>(GetWidgetFromName(TEXT("sys_Enable_Character_Slot1"))));

	CharacterSlot2Panel.Add(Cast<UCanvasPanel>(GetWidgetFromName(TEXT("sys_Disable_Character_Slot2"))));
	CharacterSlot2Panel.Add(Cast<UCanvasPanel>(GetWidgetFromName(TEXT("sys_Enable_Character_Slot2"))));

	DisableSlotButtons.Add(Cast<UButton>(GetWidgetFromName(TEXT("sys_Disable_Character_Slot1_btn"))));
	DisableSlotButtons.Add(Cast<UButton>(GetWidgetFromName(TEXT("sys_Disable_Character_Slot2_btn"))));

	EnableSlot1Button = Cast<UButton>(GetWidgetFromName(TEXT("sys_Enable_Character_Slot1_btn")));
	EnableSlot2Button = Cast<UButton>(GetWidgetFromName(TEXT("sys_Enable_Character_Slot2_btn")));


	for (int i = 0; i < DisableSlotButtons.Num(); i++)
	{
		DisableSlotButtons[i]->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnCreateCharacterClicked);
	}

	EnableSlot1Button->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnSlot1CharacterSetClicked);
	EnableSlot2Button->OnClicked.AddDynamic(this, &UCharacterSelectWidget::OnSlot2CharacterSetClicked);

	// CharacterSlot Data Check!
	CharacterSlotEnable();



	SetSlotData();
}

void UCharacterSelectWidget::OnCreateCharacterClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("CharacterCustumMap"));
}

void UCharacterSelectWidget::OnGameStartClicked()
{
	// later
}

void UCharacterSelectWidget::OnSlot1CharacterSetClicked()
{
	ChoiceSlot = ECharacterSlot::SLOT1;
	
	SetCharacterModel(ChoiceSlot);
}

void UCharacterSelectWidget::OnSlot2CharacterSetClicked()
{
	ChoiceSlot = ECharacterSlot::SLOT2;

	SetCharacterModel(ChoiceSlot);
}

void UCharacterSelectWidget::SetSlotData()
{
}

void UCharacterSelectWidget::SetCharacterModel(ECharacterSlot CurrentSlot)
{
}

void UCharacterSelectWidget::CharacterSlotEnable()
{
	
}


