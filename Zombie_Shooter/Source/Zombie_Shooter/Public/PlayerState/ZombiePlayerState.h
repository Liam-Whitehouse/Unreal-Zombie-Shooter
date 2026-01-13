// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ZombiePlayerState.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API AZombiePlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AZombiePlayerState();

	virtual void BeginPlay() override;

};
