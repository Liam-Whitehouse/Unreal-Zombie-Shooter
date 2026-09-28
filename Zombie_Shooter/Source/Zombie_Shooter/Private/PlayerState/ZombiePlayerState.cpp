// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/ZombiePlayerState.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include <Net/UnrealNetwork.h>


AZombiePlayerState::AZombiePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UZombieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UZombieAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.0f);

	ZombiesKilled = 0;
}

void AZombiePlayerState::BeginPlay()
{
	Super::BeginPlay();

}

UAbilitySystemComponent* AZombiePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

int32 AZombiePlayerState::GetZombiesKilled()
{
	return ZombiesKilled;
}

void AZombiePlayerState::IncrementZombiesKilled()
{
	ZombiesKilled++;
}

void AZombiePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AZombiePlayerState, ZombiesKilled);
}