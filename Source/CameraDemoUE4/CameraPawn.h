// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CameraPawn.generated.h"

class UACameraShake;

UCLASS()
class CAMERADEMOUE4_API ACameraPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector2D mouseInput;

	UPROPERTY(EditAnywhere)
		USpringArmComponent* springArm;	

	void MouseUpDown(float axis);
	void MouseHorizontal(float axis);

	FVector MovementDirection;
	UPROPERTY(EditAnywhere)
		float MovementSpeed = 500.f;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUp(float Value);

	void PlayCameraShake();

	UPROPERTY(EditAnywhere)
		TSubclassOf<UCameraShakeBase> CamShake;
	
	UCameraComponent* camera;

	//UPROPERTY(EditAnywhere)
	//	UStaticMeshComponent* mesh;

};
