// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameInstance.h"

UPlayerGameInstance::UPlayerGameInstance()
{
	FString CharacterDataPath = TEXT("/Game/DataTables/PlayerCharacterData.PlayerCharacterData");

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_PLAYERCHARACTER(*CharacterDataPath);

	if (DT_PLAYERCHARACTER.Succeeded())
	{
		PlayerCharacterTable = DT_PLAYERCHARACTER.Object;
	}
}

void UPlayerGameInstance::Init()
{
	Super::Init();
}

FPlayerCharacterData * UPlayerGameInstance::GetPlayerData(int32 Level)
{
	return PlayerCharacterTable->FindRow<FPlayerCharacterData>(*FString::FromInt(Level), TEXT(""));
}
