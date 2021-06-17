// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "PlayerGameInstance.generated.h"


USTRUCT(BlueprintType)
struct FPlayerCharacterData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FPlayerCharacterData() : Level(1), MaxHP(100.0f), Attack(10.0f), NextExp(50) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float MaxHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		float Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
		int32 NextExp;
};


/**
 * 
 */
UCLASS()
class ROLEPLAYMAKER_API UPlayerGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPlayerGameInstance();

	virtual void Init() override;
	FPlayerCharacterData * GetPlayerData(int32 Level);

private:
	UPROPERTY()
		class UDataTable* PlayerCharacterTable;
	
};
