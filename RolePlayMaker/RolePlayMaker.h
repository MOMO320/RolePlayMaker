// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

UENUM(BlueprintType)
enum class ECameraState : uint8
{
	GAME_START,
	CHARACTER_CHOICE,
	CHARACTER_MAKE,
	IN_GAME
};