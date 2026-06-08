// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ZombieCharacter.h"

#include "../../../../../../UnrealEngine-5.7-Source/Engine/Plugins/Animation/MotionWarping/Source/MotionWarping/Public/MotionWarpingComponent.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include "AbilitySystem/Abilities/ZombieAnimationAbility.h"
#include "Controller/AIZombieController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameModes/MainGameMode.h"
#include "Loot/LootComponent.h"
#include "Components/WidgetComponent.h"
#include "SubSystems/ZombieSpawnerSystem.h"
#include "UI/ZombieUserWidget.h"
#include "UI/ZombieAttributeWidgetController.h"



// Sets default values
AZombieCharacter::AZombieCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//Allows the Tick ot run on a Dedicated Server, so hopefully they keep running even when the player is far away-ish
	PrimaryActorTick.bAllowTickOnDedicatedServer = true;

	AbilitySystemComponent = CreateDefaultSubobject<UZombieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UZombieAttributeSet>("ZombieAttributeSet");

	LootComp = CreateDefaultSubobject<ULootComponent>("LootComponent");
	
	MotionWarpComp = CreateDefaultSubobject<UMotionWarpingComponent>("Motion Warping Component");

	HealthBarWidget = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBarWidget->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	SetNetUpdateFrequency(100.0f);
}

void AZombieCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	ZombieAIController = Cast<AAIZombieController>(NewController);
	if (IsValid(ZombieAIController) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller was not able to get Casted into a Zombie Controller inside of [%s]. This is a problem"), *GetName());
		return;
	}
	
	HandleZombieInitialize_Implementation();
}

void AZombieCharacter::HandleZombieInitialize_Implementation()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorTickEnabled(true);
	GetCharacterMovement()->SetComponentTickEnabledAsync(true);
	
	//Initialiazes on Server
	InitAbilityActorInfo();
	InitializeDefaultAttributes();
	AddCharacterAbilities();

	if (ZombieAIController == nullptr)
	{
		SpawnDefaultController();
		ZombieAIController = Cast<AAIZombieController>(GetController());
	}

	ZombieAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	ZombieAIController->GetBlackboardComponent()->SetValueAsEnum(TEXT("ClassType"), (uint8)ClassType);
	ZombieAIController->RunBehaviorTree(BehaviorTree);
	
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->SetComponentTickEnabled(true);
	Movement->SetMovementMode(MOVE_Walking);
	
	if(IsValid(SpawnAbility) == true)
	{
		MulticastZombieSpawn_Implementation();
	}
}

void AZombieCharacter::HandleZombieDeInitialize_Implementation()
{
	GetAbilitySystemComponent()->CancelAllAbilities();
	
	Spawner = GetWorld()->GetSubsystem<UZombieSpawnerSystem>();
	if (Spawner == nullptr)
	{
		return;
	}
	
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	SetActorTickEnabled(false);
	GetCharacterMovement()->SetComponentTickEnabledAsync(false);
	
	Spawner->LoadedZombies.Add(this);
}

void AZombieCharacter::MulticastZombieSpawn_Implementation()
{
	FGameplayAbilitySpec AbilitySpec(SpawnAbility, 1);
	GetAbilitySystemComponent()->GiveAbilityAndActivateOnce(AbilitySpec);
}

// Called when the game starts or when spawned
void AZombieCharacter::BeginPlay()
{
	Super::BeginPlay();

	WidgetClass = Cast<UZombieUserWidget>(HealthBarWidget->GetUserWidgetObject());
	if (WidgetClass == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Health Bar User Widget is not of Subclass UZombieUserWidget [%s]"), *GetName());
		return;
	}

	const FZombieWidgetControllerParams Params(nullptr, nullptr, AbilitySystemComponent, AttributeSet);
	WidgetClass->SetupAIWidgetController(Params);

	AttributeWidgetController = Cast<UZombieAttributeWidgetController>(WidgetClass->GetWidgetController());
	if (IsValid(AttributeWidgetController) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Health Bar Widget does not have a valid Widget Controller setup in [%s]"), *GetName());
		return;
	}

	AttributeWidgetController->SetupZombieWidgetControllerParams(Params);
	AttributeWidgetController->BindCallbackToDependencies();
	AttributeWidgetController->BroadcastInitialValues();
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
	
	ZombieAIController->BrainComponent->StopLogic("Dead");
	
	UCharacterMovementComponent* Movement = GetCharacterMovement();
	Movement->DisableMovement();

	GetWorldTimerManager().SetTimer(DeathTimer, this, &AZombieCharacter::HandleZombieDeInitialize_Implementation, DeathCountDown, false);
}

float AZombieCharacter::GetAggressionRange() const
{
	return AggressionRange;
}

EZombieClassType AZombieCharacter::GetClassType()
{
	return ClassType;
}
