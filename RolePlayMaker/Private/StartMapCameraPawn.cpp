// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMapCameraPawn.h"
#include "GameStartPlayerController.h"
#include "MovieSceneSequencePlayer.h"
#include "PlayerCharacterSetting.h"

// Sets default values
AStartMapCameraPawn::AStartMapCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto DefaultSetting = GetDefault<UPlayerCharacterSetting>();

	if (DefaultSetting->CharacterHairAssets.Num() > 0)
	{
		for (auto ChracterHair : DefaultSetting->CharacterHairAssets)
		{
			UE_LOG(LogTemp,Warning, TEXT("Hair Asset : %s"), *ChracterHair.ToString());
		}
	}

	if (DefaultSetting->CharacterTopAssets.Num() > 0)
	{
		for (auto ChracterTop : DefaultSetting->CharacterTopAssets)
		{
			UE_LOG(LogTemp,Warning, TEXT("Top Asset : %s"), *ChracterTop.ToString());
		}
	}

	CurrentCameraIndex = 0;
}

// Called when the game starts or when spawned
void AStartMapCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = Cast<AGameStartPlayerController>(GetController());
	

	if (Cameras.Num() != 0)
	{
		CameraChangeViewTarget(CurrentCameraIndex);
		PlayerController->SetStartWidgetCameraPawn(this);
	}
}

// Called every frame
void AStartMapCameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AStartMapCameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AStartMapCameraPawn::CameraChangeViewTarget(int32 index)
{
	if (PlayerController != nullptr && Cameras.Num() != 0)
		PlayerController->SetViewTarget(Cameras[index]);
}

void AStartMapCameraPawn::ChangeCamera()
{
	
	FMovieSceneSequencePlaybackSettings PlaybackSettings;
	ULevelSequencePlayer * LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
		GetWorld(), 
		ChangeCameraSequence , 
		PlaybackSettings, 
		LevelSequenceActor
	);

	LevelSequencePlayer->OnFinished.AddDynamic(this, &AStartMapCameraPawn::CharacterSelectCamera);

	LevelSequencePlayer->Play();
}

void AStartMapCameraPawn::CharacterSelectCamera()
{
	CurrentCameraIndex++;
	CameraChangeViewTarget(CurrentCameraIndex);
}

