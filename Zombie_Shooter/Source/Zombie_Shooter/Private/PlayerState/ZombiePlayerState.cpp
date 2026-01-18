// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/ZombiePlayerState.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"


AZombiePlayerState::AZombiePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UZombieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UZombieAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.0f);
}

void AZombiePlayerState::BeginPlay()
{
	Super::BeginPlay();

}

UAbilitySystemComponent* AZombiePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AZombiePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}