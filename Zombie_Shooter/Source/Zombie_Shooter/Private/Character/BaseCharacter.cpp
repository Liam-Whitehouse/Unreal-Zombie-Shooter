// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ABaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitAbilityActorInfo()
{
	
}

void ABaseCharacter::InitializeVitalAttributes() const
{
	InitializeAttributes(VitalAttributes);
}

void ABaseCharacter::InitializePrimaryAttributes() const
{
	InitializeAttributes(PrimaryAttributes);
}

void ABaseCharacter::InitializeAttributes(const TSubclassOf<UGameplayEffect> Attribute) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(Attribute);
	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(GetAbilitySystemComponent()->GetAvatarActor());
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Attribute, 1.0f, EffectContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ABaseCharacter::InitializeDefaultAttributes()
{
}

void ABaseCharacter::AddCharacterAbilities(UAbilitySystemComponent* ASC) const
{
	UZombieAbilitySystemComponent* ZombieAbilitySystemComponent = CastChecked<UZombieAbilitySystemComponent>(ASC);

	if (HasAuthority() == false)
	{
		return;
	}

	ZombieAbilitySystemComponent->AddCharacterAbilities(StartupAbilities);
}