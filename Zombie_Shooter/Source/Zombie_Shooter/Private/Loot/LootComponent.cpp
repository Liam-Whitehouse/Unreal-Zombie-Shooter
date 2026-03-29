// Fill out your copyright notice in the Description page of Project Settings.


#include "Loot/LootComponent.h"

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

	AActor* chosenLoot = GetRandomLoot();
	if (chosenLoot == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Loot was found"));
		return;
	}

	AEffectActor* SpawnedLoot = GetWorld()->SpawnActorDeferred<AEffectActor>(chosenLoot->GetClass(), ActorTransform, GetOwner(), GetOwner()->GetInstigator(), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	if (IsValid(SpawnedLoot) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Loot is invalid and wont spawn in inside of [%s]"), *GetName());
		return;
	}

	SpawnedLoot->FinishSpawning(ActorTransform);
}

TArray<FLootItems> ULootComponent::GetLootItems()
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

	//This is temp until I get more items into the game
	int32 chosenIndex = FMath::RandRange(0, 100);
	for (const auto& Chosen : Loot)
	{
		if (chosenIndex <= Chosen.DropChance)
		{
			return Chosen.Loot.GetDefaultObject();
		}
	}

	return nullptr;
}
