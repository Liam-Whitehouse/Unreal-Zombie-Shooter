// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffectActor/EffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "ZombieGameplayTags.h"

// Sets default values
AEffectActor::AEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectActor::ApplyEffectToTarget(AActor* TargetActor)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr)
	{
		return;
	}

	TargetASC->ApplyGameplayEffectSpecToSelf(*GameEffectSpecHandle.Data.Get());
}

void AEffectActor::AssignGameplayEffectSpec(const FGameplayEffectSpecHandle& SpecHandle, float ScaledDamage)
{
	FZombieGameplayTags GameplayTags = FZombieGameplayTags::Get();
	
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Attribute_Damage, ScaledDamage);
	AddSpecHandle(SpecHandle);
}

void AEffectActor::AddSpecHandle(const FGameplayEffectSpecHandle& SpecHandle)
{
	GameEffectSpecHandle = SpecHandle;
}
