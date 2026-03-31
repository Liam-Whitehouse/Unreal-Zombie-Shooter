// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ZombieCharacter.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include "Controller/AIZombieController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameModes/MainGameMode.h"
#include "Loot/LootComponent.h"


// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UZombieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UZombieAttributeSet>("AttributeSet");

	LootComp = CreateDefaultSubobject<ULootComponent>("LootComponent");

	SetNetUpdateFrequency(100.0f);
}

void AZombieCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Initialiazes on Server
	InitAbilityActorInfo();
	InitializeDefaultAttributes();
	AddCharacterAbilities();

	if (HasAuthority() == false)
	{
		return;
	}

	ZombieAIController = Cast<AAIZombieController>(NewController);

	ZombieAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);

	ZombieAIController->GetBlackboardComponent()->SetValueAsEnum(TEXT("ClassType"), (uint8)ClassType);
	ZombieAIController->RunBehaviorTree(BehaviorTree);
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

void AZombieCharacter::SetCurrentTarget(APawn* NewTarget)
{
	if (IsValid(NewTarget) == false)
	{
		Target = nullptr;
		return;
	}

	Target = NewTarget;
}

APawn* AZombieCharacter::GetCurrentTarget()
{
	if (IsValid(Target) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Current Target is null for %s"), *GetName());
		return nullptr;
	}
	return Target;
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

void AZombieCharacter::HandleDeath()
{
	Super::HandleDeath();
	
	MulticastHandleDeath();
	
	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());
	if (IsValid(GameMode) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("This should never get hit as if we dont have a valid GameMode we are in trouble."));
		return;
	}
	GameMode->DecreaseZombieCount();

	LootComp->GenerateLoot();
	
	Controller->UnPossess();

	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->DisableMovement();

	//Play a sound in here if any.

	//Initiate a Respawn as well.

	GetWorldTimerManager().SetTimer(DeathTimer, this, &AZombieCharacter::HandleDestruction, DeathCountDown, false);
}

float AZombieCharacter::GetAggressionRange() const
{
	return AggressionRange;
}

EZombieClassType AZombieCharacter::GetClassType()
{
	return ClassType;
}

void AZombieCharacter::HandleDestruction()
{
	//Play a Particle Effect Here

	Destroy();
}
