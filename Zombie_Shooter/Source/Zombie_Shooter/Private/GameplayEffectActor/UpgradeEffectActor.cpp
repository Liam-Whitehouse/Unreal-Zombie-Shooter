// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffectActor/UpgradeEffectActor.h"
#include "SubSystems/ZombieSpawnerSystem.h"
#include "Components/BoxComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Character/BaseCharacter.h"

AUpgradeEffectActor::AUpgradeEffectActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
	EffectActorBoxComp = CreateDefaultSubobject<UBoxComponent>("Effect Actor Collision Box");
	EffectActorBoxComp->SetupAttachment(GetRootComponent());

	EffectActorBoxComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	EffectActorBoxComp->SetCollisionObjectType(ECC_WorldDynamic);
	EffectActorBoxComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	EffectActorBoxComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	bReplicates = true;
}

void AUpgradeEffectActor::InitializeActor(FTransform SpawnLocation)
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);

	SetActorTransform(SpawnLocation);

	GetWorldTimerManager().SetTimer(EffectActorTimer, this, &AEffectActor::DeInitializeActor, EffectActorActiveTimer, false);
}

void AUpgradeEffectActor::DeInitializeActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);

	SetActorLocation(FVector::Zero());
	UZombieSpawnerSystem* SpawnerSubSystem = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	SpawnerSubSystem->LoadedBullets.Add(this);
}

void AUpgradeEffectActor::ApplyEffectToTarget(AActor* TargetActor)
{
	//Upgrade a Random Talent / Damage
	if (HasAuthority() == false)
	{
		return;
	}

	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (TargetASC == nullptr)
	{
		return;
	}
	
	//I dont like this but I am a bit tired to think of a better solution currently.
	//We have this here as since we are spawning a bullet as an Effect Actor, it passes in its Spec Handle.
	//This is for when we have an a buff item on the map.
	if (IsValid(InstantGameplayEffectClass) == true)
	{
		const FGameplayEffectSpecHandle& Handle = TargetASC->MakeOutgoingSpec(InstantGameplayEffectClass, 1, TargetASC->MakeEffectContext());

		if (Handle.IsValid() == false)
		{
			UE_LOG(LogTemp, Warning, TEXT("Ability Effect Spec Handle is Invalid for class [%s]"), *GetName());
			return;
		}
		
		TargetASC->ApplyGameplayEffectSpecToSelf(*Handle.Data.Get());
	}
}