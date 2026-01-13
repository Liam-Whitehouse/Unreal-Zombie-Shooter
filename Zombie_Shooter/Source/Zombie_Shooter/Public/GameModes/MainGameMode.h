// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainGameMode.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API AMainGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AMainGameMode();

	virtual void BeginPlay() override;

};
