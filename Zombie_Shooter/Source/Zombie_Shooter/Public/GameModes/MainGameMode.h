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

	UFUNCTION(BlueprintCallable)
	void AddZombieCount();

	UFUNCTION(BlueprintCallable)
	void DecreaseZombieCount();

	UFUNCTION(BlueprintCallable)
	bool HasReachedMaxZombieCount() const;
	
protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Max Zombie Amount")
	int32 MaxZombieAmount = 50;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Current Zombie Amount")
	int32 CurrentZombieAmount = 0;
};
