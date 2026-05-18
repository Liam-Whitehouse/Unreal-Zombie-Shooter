// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameLiftServer/Source/GameLiftServerSDK/Public/GameLiftServerSDK.h"
#include "MainGameMode.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogZombieShooterGameMode, Log, All);

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

private:
	FProcessParameters ProcessParameters;

	void InitGameLift();

	void SetServerParameters(FServerParameters& OutParams);

	void ParseCommandLinePort(int32& OutPort);
};
