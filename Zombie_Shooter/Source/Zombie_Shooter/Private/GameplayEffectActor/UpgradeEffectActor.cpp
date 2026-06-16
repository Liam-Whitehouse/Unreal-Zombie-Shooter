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

	ABaseCharacter* Character = Cast<ABaseCharacter>(TargetActor);

	UAttributeSet* AS = Character->GetAttributeSet();

	//Upgrading an Attribute | MOVE INTO FUNCTION
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(TargetASC->GetAvatarActor());
	UGameplayEffect* GE = Cast<UGameplayEffect>(InstantGameplayEffectClass->StaticClass);
	int32 RandomIndex = FMath::RandRange(0, GE->Modifiers.Num());
	FGameplayModifierInfo MI = GE->Modifiers[RandomIndex];
	TargetASC->ApplyModToAttribute(MI.Attribute, MI.ModifierOp, +1);

	//Need a random chosen Attribute
	//FGameplayEffectSpecHandle SpecHandle = TargetASC->MakeOutgoingSpec(InstantGameplayEffectClass, 1.0f, EffectContextHandle);
	//TargetASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), TargetASC);

	//I dont like this but I am a bit tired to think of a better solution currently.
	//We have this here as since we are spawning a bullet as an Effect Actor, it passes in its Spec Handle.
	//This is for when we have an a buff item on the map.
	if (IsValid(InstantGameplayEffectClass) == true)
	{
		GameEffectSpecHandle = TargetASC->MakeOutgoingSpec(InstantGameplayEffectClass, 1, TargetASC->MakeEffectContext());
	}

	if (GameEffectSpecHandle.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability Effect Spec Handle is Invalid for class [%s]"), *GetName());
		return;
	}

	TargetASC->ApplyGameplayEffectSpecToSelf(*GameEffectSpecHandle.Data.Get());
}