// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSaveGame.h"


UPlayerSaveGame::UPlayerSaveGame()
{
	Name = TEXT("Player");
	Level = 1;
	Exp = 0;
	Money = 300;
	
	BodyRGB = FColor(1.0, 0.79, 0.79, 1.0);
	HairIndex = 0;
	HairRGB = FColor::Yellow;
	TopIndex = 0;
}
