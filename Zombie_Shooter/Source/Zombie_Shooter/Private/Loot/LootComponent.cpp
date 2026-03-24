// Fill out your copyright notice in the Description page of Project Settings.


#include "Loot/LootComponent.h"

#include "GameplayEffectActor/EffectActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
ULootComponent::ULootComponent()
{

}


// Called when the game starts
void ULootComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void ULootComponent::GenerateLoot()
{
	FTransform ActorTransform;
	ActorTransform.SetLocation(GetOwner()->GetActorLocation());
	ActorTransform.SetRotation(GetOwner()->GetActorQuat());
	
	AEffectActor* SpawnedLoot = GetWorld()->SpawnActorDeferred<AEffectActor>(GetRandomLoot()->GetClass(), ActorTransform, GetOwner(), GetOwner()->GetInstigator(), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	if (IsValid(SpawnedLoot) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Loot is invalid and wont spawn in inside of [%s]"), *GetName());
		return;
	}

	SpawnedLoot->FinishSpawning(ActorTransform);
}

TArray<TSubclassOf<AEffectActor>> ULootComponent::GetLoot()
{
	return Loot;
}

AEffectActor* ULootComponent::GetRandomLoot()
{
	if (Loot.IsEmpty() == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Loot table is empty inside of [%s]"), *GetOwner()->GetName());
		return nullptr;
	}

	int32 chosenIndex = FMath::RandRange(0, Loot.Num() - 1);

	return Loot[chosenIndex].GetDefaultObject();
}
