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

}

void ASurvivorCharacter::MovePlayerForward(float Axis)
{
	FRotator NewRotation = FRotator::ZeroRotator;

	NewRotation.Add(0.0f, GetControlRotation().Yaw, 0.0f);

	GetActorForwardVector().Set(NewRotation.Roll, NewRotation.Pitch, NewRotation.Yaw);
	SetActorRotation(NewRotation);

	AddMovementInput(GetActorForwardVector(), Axis, false);
}

void ASurvivorCharacter::MovePlayerRight(float Axis)
{
	FRotator NewRotation = FRotator::ZeroRotator;

	NewRotation.Add(0.0f, GetControlRotation().Yaw, 0.0f);

	GetActorRightVector().Set(NewRotation.Roll, NewRotation.Pitch, NewRotation.Yaw);
	SetActorRotation(NewRotation);

	AddMovementInput(GetActorRightVector(), Axis, false);
}