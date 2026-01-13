// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Controller.h"
#include "ZombieController.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API AZombieController : public AController
{
	GENERATED_BODY()

public:
	AZombieController();

	virtual void BeginPlay() override;

};
