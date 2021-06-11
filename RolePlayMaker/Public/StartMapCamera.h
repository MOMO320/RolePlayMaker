// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RolePlayMaker.h"
#include "GameFramework/Actor.h"
#include "StartMapCamera.generated.h"

UCLASS()
class ROLEPLAYMAKER_API AStartMapCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStartMapCamera();

public:
	void CameraChange();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void CameraChangeViewTarget(int32 index);

public:	
	UPROPERTY(EditAnywhere )
		TArray<AActor*> Cameras;

private:
	UPROPERTY()
		class	AGameStartPlayerController* PlayerController;

	
	

	int CurrentCameraIndex;
};
