// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SurvivorCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASurvivorCharacter::ASurvivorCharacter()
{
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>("Player Camera");
	CameraArm = CreateDefaultSubobject<USpringArmComponent>("Camera Spring Arm");

	CameraArm->SetupAttachment(RootComponent);
	PlayerCamera->SetupAttachment(RootComponent);
	PlayerCamera->AttachToComponent(CameraArm, FAttachmentTransformRules::KeepRelativeTransform);

	CameraArm->bUsePawnControlRotation = true;
	CameraArm->bEnableCameraLag = true;
	CameraArm->TargetArmLength = 300.0f;
}

void ASurvivorCharacter::Tick(float DeltaTime)
{
}

void ASurvivorCharacter::SetupPlayerInput(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//PlayerInputComponent->BindAction();
}