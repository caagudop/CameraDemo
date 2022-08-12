// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraPawn.h"
#include "GameFramework/PlayerController.h"
#include "InputPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CAMERADEMOUE4_API AInputPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	void SetupInputComponent() override;
	void SetupPlayer(class ACameraPawn* NewPlayer);

	void MouseYaw(float axis);
	void MousePitch(float axis);

	FVector MovementDirection;
	UPROPERTY(EditAnywhere)
		float MovementSpeed = 500.f;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUp(float Value);

	void PlayCameraShake();

	UPROPERTY()
		class ACameraPawn* MyPlayer = nullptr;

};
