// Fill out your copyright notice in the Description page of Project Settings.


#include "Loot/LootComponent.h"

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

AActor* ULootComponent::GenerateLoot()
{
	return GetRandomLoot();
}

TArray<AActor*> ULootComponent::GetLoot()
{
	return Loot;
}

AActor* ULootComponent::GetRandomLoot()
{
	if (Loot.IsEmpty() == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Loot table is empty inside of [%s]"), *GetOwner()->GetName());
		return;
	}

	int32 chosenIndex = FMath::RandRange(0, Loot.Num());

	return Loot[chosenIndex];
}