// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterState.h"
#include "PlayerSaveGame.h"
#include "Kismet/GameplayStatics.h"

APlayerCharacterState::APlayerCharacterState()
{
	CharacterLevel = 1;
	CharacterExp = 0;
	CharacterMoney = 300;
	CharacterBodyRGB = FColor(1.0, 0.79, 0.79, 1.0);
	CharacterHairIndex = 0;
	CharacterHairRGB = FColor::Yellow;
	CharacterTopIndex = 0;
	SaveSlotName = TEXT("");
}

int32 APlayerCharacterState::GetCharacterLevel() const
{
	return CharacterLevel;
}

int32 APlayerCharacterState::GetCharacterMoney() const
{
	return CharacterMoney;
}

FColor APlayerCharacterState::GetChracterBodyRGB() const
{
	return CharacterBodyRGB;
}

int32 APlayerCharacterState::GetCharacterHairIndex() const
{
	return CharacterHairIndex;
}

FColor APlayerCharacterState::GetCharacterHairRGB() const
{
	return CharacterHairRGB;
}

int32 APlayerCharacterState::GetCharacterTopIndex() const
{
	return CharacterTopIndex;
}

FSaveSlotData APlayerCharacterState::GetSlot1Data() const
{
	return Slot1Data;
}

FSaveSlotData APlayerCharacterState::GetSlot2Data() const
{
	return Slot2Data;
}

float APlayerCharacterState::GetExpRatio() const
{
	return 0.0f;
}

bool APlayerCharacterState::AddExp(int32 ComeExp)
{
	return false;
}

void APlayerCharacterState::AddPlayerMoney()
{
}

void APlayerCharacterState::InitPlayerData(FSaveSlotData SlotData)
{
	SlotData.PlayerSaveSlot = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotData.SaveSlotName, SlotData.SlotIndex));

	if (nullptr == SlotData.PlayerSaveSlot)
	{
		SlotData.PlayerSaveSlot = GetMutableDefault<UPlayerSaveGame>();
	}

	UPlayerSaveGame* PlayerSaveGame = SlotData.PlayerSaveSlot;

	SetPlayerName(PlayerSaveGame->Name);
	//SetCharacterLevel(PlayerSaveGame->Level);
	CharacterLevel = PlayerSaveGame->Level;
	CharacterExp = PlayerSaveGame->Exp;
	CharacterMoney = PlayerSaveGame->Money;
	CharacterBodyRGB = PlayerSaveGame->BodyRGB;
	CharacterHairIndex = PlayerSaveGame->HairIndex;
	CharacterHairRGB = PlayerSaveGame->HairRGB;
	CharacterTopIndex = PlayerSaveGame->TopIndex;

	//SavePlayerData();
}

void APlayerCharacterState::SavePlayerData(FSaveSlotData SlotData)
{
	UPlayerSaveGame* NewPlayerData = NewObject<UPlayerSaveGame>();
	NewPlayerData->Name = GetPlayerName();
	NewPlayerData->Level = CharacterLevel;
	NewPlayerData->Exp = CharacterExp;
	NewPlayerData->Money = CharacterMoney;
	NewPlayerData->BodyRGB = CharacterBodyRGB;
	NewPlayerData->HairIndex = CharacterHairIndex;
	NewPlayerData->HairRGB = CharacterHairRGB;
	NewPlayerData->TopIndex = CharacterTopIndex;

	SlotData.PlayerSaveSlot = NewPlayerData;

	if (!UGameplayStatics::SaveGameToSlot(SlotData.PlayerSaveSlot, SlotData.SaveSlotName, SlotData.SlotIndex))
	{
		UE_LOG(LogTemp, Error, TEXT("Save Game Error"));
	}

}

bool APlayerCharacterState::LoadSaveFileCheck(FSaveSlotData SlotData)
{
	if (SlotData.PlayerSaveSlot != nullptr)
		return true;
	else return false;
}

//void APlayerCharacterState::SetCharacterLevel(int32 CharacterLevel)
//{
//
//}
