// Fill out your copyright notice in the Description page of Project Settings.


#include "StartMapCamera.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AStartMapCamera::AStartMapCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CurrentCameraIndex = 0;
	Tags.Add("CameraActor");
}

// Called when the game starts or when spawned
void AStartMapCamera::BeginPlay()
{
	Super::BeginPlay();

	//PlayerController = Cast<AGameStartPlayerController>(UGameplayStatics::GetPlayerController(this, 0));


	if (Cameras.Num() != 0)
	{
		CameraChangeViewTarget(CurrentCameraIndex);
	}
}


void AStartMapCamera::CameraChangeViewTarget(int32 index)
{
	//Controller = UGameplayStatics::GetPlayerController(this, 0);
	//if (Controller && Cameras.Num() != 0)
	//{
	//	Controller->SetViewTarget(Cameras[index]);
	//}
}

void AStartMapCamera::CameraChange()
{
	CurrentCameraIndex++;

	CameraChangeViewTarget(CurrentCameraIndex);
}

// Called every frame
void AStartMapCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

