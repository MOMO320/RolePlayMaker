// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMapCamera.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AStartMapCamera::AStartMapCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CurrentCameraIndex = 0;
}

// Called when the game starts or when spawned
void AStartMapCamera::BeginPlay()
{
	Super::BeginPlay();

	Controller = UGameplayStatics::GetPlayerController(this, 0);

	if (Controller)
	{
		Controller->SetViewTarget(Cameras[CurrentCameraIndex]);
	}
}

void AStartMapCamera::CameraChange(ECameraState cameraState)
{
}

// Called every frame
void AStartMapCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

