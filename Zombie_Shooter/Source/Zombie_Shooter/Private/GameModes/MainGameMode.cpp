// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/MainGameMode.h"

AMainGameMode::AMainGameMode()
{

}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AMainGameMode::AddZombieCount()
{
	if (HasAuthority() == false)
	{
		return;
	}

	CurrentZombieAmount++;
}

void AMainGameMode::DecreaseZombieCount()
{
	if (HasAuthority() == false)
	{
		return;
	}

	CurrentZombieAmount--;
}

bool AMainGameMode::HasReachedMaxZombieCount() const
{
	if (HasAuthority() == false)
	{
		return false;
	}

	if (CurrentZombieAmount >= MaxZombieAmount)
	{
		return true;
	}

	return false;
}
