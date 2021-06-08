// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "StartMapCameraPawn.generated.h"

UCLASS()
class ROLEPLAYMAKER_API AStartMapCameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AStartMapCameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CameraChangeViewTarget(int32 index);

	void ChangeCamera();

public:
	UPROPERTY(EditAnywhere)
		TArray<AActor*> Cameras;

private:
	UPROPERTY()
		class AGameStartPlayerController* PlayerController;

	int CurrentCameraIndex;
	bool First;
};
