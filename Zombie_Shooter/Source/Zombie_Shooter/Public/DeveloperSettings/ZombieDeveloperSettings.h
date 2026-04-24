// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ZombieDeveloperSettings.generated.h"

class AZombieCharacter;
class AEffectActor;

/**
 * 
 */
UCLASS(config=Game, defaultconfig, meta=(DisplayName="Objects to Load Settings"))
class ZOMBIE_SHOOTER_API UZombieDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<AZombieCharacter>> Zombies;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	int32 ZombieAmount = 0;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<AEffectActor>> PickUps;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	int32 PickUpObjectAmount = 0;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<AEffectActor>> Bullets;

	UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	int32 BulletObjectAmount = 0;

	UZombieDeveloperSettings();

	UFUNCTION(BlueprintPure)
	static const UZombieDeveloperSettings* GetZombieDeveloperSettings();
};
