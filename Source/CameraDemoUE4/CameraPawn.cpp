// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"
#include "InputPlayerController.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	bUseControllerRotationYaw = false;

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));	
	//mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	//RootComponent = mesh;

	springArm->AttachTo(RootComponent);
	springArm->TargetArmLength = 350.f;
	springArm->SetWorldRotation(FRotator(-60.f, 0.f, 0.f));

	springArm->bEnableCameraLag = true;
	springArm->CameraLagSpeed = 2;
	springArm->CameraLagMaxDistance = 1.5f;

	springArm->bEnableCameraRotationLag = true;
	springArm->CameraRotationLagSpeed = 4;
	springArm->CameraLagMaxTimeStep = 1;

	camera->AttachTo(springArm, USpringArmComponent::SocketName);
	//Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//MOVE_Flying
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	AInputPlayerController* PlayerController= GetController<AInputPlayerController>();
	if (PlayerController)
		PlayerController->SetupPlayer(this);
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACameraPawn::MouseUpDown(float axis)
{
	if (axis) {
		float temp = springArm->GetRelativeRotation().Pitch + axis;
		if (temp<25 && temp>-65) {
			springArm->AddLocalRotation(FRotator(axis, 0, 0));
		}
	}
}

void ACameraPawn::MouseHorizontal(float axis)
{
	if (axis) {
		AddActorLocalRotation(FRotator(0, axis, 0));
	}
}

void ACameraPawn::MoveForward(float Value)
{
	if (Value) {
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ACameraPawn::MoveRight(float Value)
{
	if (Value) {
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ACameraPawn::MoveUp(float Value)
{
	if (Value) {
		AddMovementInput(GetActorUpVector(), Value);
	}
}

void ACameraPawn::PlayCameraShake()
{
	GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(CamShake);
}
