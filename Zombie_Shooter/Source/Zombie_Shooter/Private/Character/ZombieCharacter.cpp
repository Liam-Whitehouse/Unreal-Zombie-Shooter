// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ZombieCharacter.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"


// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UZombieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UZombieAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.0f);
}

void AZombieCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Initialiazes on Server
	InitAbilityActorInfo();
	InitializeDefaultAttributes();
	AddCharacterAbilities();
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AZombieCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AZombieCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AZombieCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UZombieAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
}

void AZombieCharacter::InitializeDefaultAttributes()
{
	InitializeVitalAttributes();
	InitializePrimaryAttributes();
}