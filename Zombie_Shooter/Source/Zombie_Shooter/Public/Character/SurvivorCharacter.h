// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "SurvivorCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API ASurvivorCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ASurvivorCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInput(class UInputComponent* PlayerInputComponent);

protected:

	UFUNCTION(BlueprintCallable)
	void MovePlayerForward(float Axis);

	UFUNCTION(BlueprintCallable)
	void MovePlayerRight(float Axis);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	USpringArmComponent* CameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* PlayerCamera;

private:


};
