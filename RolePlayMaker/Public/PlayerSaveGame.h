// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ROLEPLAYMAKER_API UPlayerSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPlayerSaveGame();

public:

	UPROPERTY()
		FString Name;

	UPROPERTY()
		int32 Level;

	UPROPERTY()
		int32 Exp;

	UPROPERTY()
		int32 Money;

	UPROPERTY()
		FColor BodyRGB;

	UPROPERTY()
		int32 HairIndex;

	UPROPERTY()
		FColor HairRGB;

	UPROPERTY()
		int32 TopIndex;



	// 아이템

	// 퀘스트

};
