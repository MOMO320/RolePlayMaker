// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMapCameraPawn.h"
#include "GameStartPlayerController.h"

// Sets default values
AStartMapCameraPawn::AStartMapCameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentCameraIndex = 0;
}

// Called when the game starts or when spawned
void AStartMapCameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
	First = false;
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
	CurrentCameraIndex++;
	CameraChangeViewTarget(CurrentCameraIndex);
}

