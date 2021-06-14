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
	SaveSlotName = TEXT("Player1");
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

void APlayerCharacterState::InitPlayerData()
{
	auto PlayerSaveGame = Cast<UPlayerSaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));

	if (nullptr == PlayerSaveGame)
	{
		PlayerSaveGame = GetMutableDefault<UPlayerSaveGame>();
	}

	SetPlayerName(PlayerSaveGame->Name);
	//SetCharacterLevel(PlayerSaveGame->Level);
	CharacterLevel = PlayerSaveGame->Level;
	CharacterExp = PlayerSaveGame->Exp;
	CharacterMoney = PlayerSaveGame->Money;
	CharacterBodyRGB = PlayerSaveGame->BodyRGB;
	CharacterHairIndex = PlayerSaveGame->HairIndex;
	CharacterHairRGB = PlayerSaveGame->HairRGB;
	CharacterTopIndex = PlayerSaveGame->TopIndex;

	SavePlayerData();
}

void APlayerCharacterState::SavePlayerData()
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

	if (!UGameplayStatics::SaveGameToSlot(NewPlayerData, SaveSlotName, 0))
	{
		UE_LOG(LogTemp, Error, TEXT("Save Game Error"));
	}

}

//void APlayerCharacterState::SetCharacterLevel(int32 CharacterLevel)
//{
//
//}
