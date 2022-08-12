// Fill out your copyright notice in the Description page of Project Settings.


#include "InputPlayerController.h"
#include "Kismet/GameplayStatics.h"

void AInputPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MouseYaw", this, &AInputPlayerController::MouseYaw);
	InputComponent->BindAxis("MousePitch", this, &AInputPlayerController::MousePitch);
	InputComponent->BindAxis("MoveForward", this, &AInputPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AInputPlayerController::MoveRight);
	InputComponent->BindAxis("MoveUp", this, &AInputPlayerController::MoveUp);
	InputComponent->BindAction("Shake", EInputEvent::IE_Pressed, this, &AInputPlayerController::PlayCameraShake);
}

void AInputPlayerController::SetupPlayer(ACameraPawn* NewPlayer)
{
	MyPlayer = NewPlayer;
}

void AInputPlayerController::MouseYaw(float axis)
{
	MyPlayer->MouseHorizontal(axis);
}

void AInputPlayerController::MousePitch(float axis)
{
	MyPlayer->MouseUpDown(axis);
}

void AInputPlayerController::MoveForward(float Value)
{
	MyPlayer->MoveForward(Value);
}

void AInputPlayerController::MoveRight(float Value)
{
	MyPlayer->MoveRight(Value);
}

void AInputPlayerController::MoveUp(float Value)
{
	MyPlayer->MoveUp(Value);
}

void AInputPlayerController::PlayCameraShake()
{
	MyPlayer->PlayCameraShake();
	
}
