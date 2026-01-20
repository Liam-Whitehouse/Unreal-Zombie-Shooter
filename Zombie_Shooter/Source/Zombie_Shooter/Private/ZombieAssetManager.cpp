// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAssetManager.h"

#include "ZombieGameplayTags.h"

UZombieAssetManager& UZombieAssetManager::Get()
{
	UZombieAssetManager* ZombieAssetManager = Cast<UZombieAssetManager>(GEngine->AssetManager);
	check(ZombieAssetManager);
	
	return *ZombieAssetManager;
}

void UZombieAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FZombieGameplayTags::InitializeNativeGameplayTags();
}
