// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerCharacterSetting.generated.h"

/**
 * 
 */
UCLASS(config=RolePlay)
class ROLEPLAYSETTING_API UPlayerCharacterSetting : public UObject
{
	GENERATED_BODY()
	
public:
	UPlayerCharacterSetting();

	UPROPERTY(config)
		TArray<FSoftObjectPath> CharacterHairAssets;

	UPROPERTY(config)
		TArray<FSoftObjectPath> CharacterTopAssets;
};
