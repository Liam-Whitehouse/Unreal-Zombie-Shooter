// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "ZombieAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	static UZombieAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
