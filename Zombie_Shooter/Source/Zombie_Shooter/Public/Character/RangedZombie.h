// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZombieCharacter.h"
#include "RangedZombie.generated.h"

UCLASS()
class ZOMBIE_SHOOTER_API ARangedZombie : public AZombieCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARangedZombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
