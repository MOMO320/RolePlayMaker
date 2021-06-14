// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerCharacterState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnPlayerStateChangeDelegate);

/**
 * 
 */
UCLASS()
class ROLEPLAYMAKER_API APlayerCharacterState : public APlayerState
{
	GENERATED_BODY()

public:

	APlayerCharacterState();

	int32 GetCharacterLevel() const;
	int32 GetCharacterMoney() const;
	FColor GetChracterBodyRGB() const;
	int32 GetCharacterHairIndex() const;
	FColor GetCharacterHairRGB() const;
	int32 GetCharacterTopIndex() const;
	
	float GetExpRatio() const;
	bool AddExp(int32 ComeExp);
	void AddPlayerMoney();

	void InitPlayerData();
	void SavePlayerData();


private:
	void SetCharacterLevel(int32 CharacterLevel);

public:
	FString SaveSlotName;

	FOnPlayerStateChangeDelegate OnPlayerStateChanged;

protected:

	UPROPERTY()
		int32 CharacterLevel;

	UPROPERTY()
		int32 CharacterExp;

	UPROPERTY()
		int32 CharacterMoney;

	UPROPERTY()
		FColor CharacterBodyRGB;

	UPROPERTY()
		int32 CharacterHairIndex;

	UPROPERTY()
		FColor CharacterHairRGB;

	UPROPERTY()
		int32 CharacterTopIndex;


};
