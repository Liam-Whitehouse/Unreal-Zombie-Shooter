// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ZombieDeveloperSettings.generated.h"

class AZombieCharacter;

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

	UZombieDeveloperSettings();

	UFUNCTION(BlueprintPure)
	static const UZombieDeveloperSettings* GetZombieDeveloperSettings();
};
