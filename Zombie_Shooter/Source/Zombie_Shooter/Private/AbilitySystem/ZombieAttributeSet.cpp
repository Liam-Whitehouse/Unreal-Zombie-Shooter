// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ZombieAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "ZombieGameplayTags.h"
#include "Character/BaseCharacter.h"
#include "GameFramework/Character.h"

UZombieAttributeSet::UZombieAttributeSet()
{
	const FZombieGameplayTags& GameplayTags = FZombieGameplayTags::Get();

	TagsToAttributes.Add(GameplayTags.Attribute_Damage, GetDamageAttribute);
}

void UZombieAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UZombieAttributeSet, CriticalChance, COND_None, REPNOTIFY_Always);
}

void UZombieAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
}

void UZombieAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		if (Data.Target.AbilityActorInfo->IsNetAuthority() == false)
		{
			return;
		}
		
		const float LocalDamage = GetDamage();
		SetDamage(0.0f);
		if (LocalDamage <= 0.0f)
		{
			return;
		}

		if (GetHealth() <= 0.0f)
		{
			return;
		}

		const float NewHealth = GetHealth() - LocalDamage;

		UE_LOG(LogTemp, Warning, TEXT("Executed Attribute: %s"), *Data.EvaluatedData.Attribute.GetName());
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Health Before Damage: [%f]"), GetHealth()));
		SetHealth(FMath::Clamp(NewHealth, 0.0f, GetMaxHealth()));

		ABaseCharacter* Target = Cast<ABaseCharacter>(Props.TargetCharacter);
		if (Target == nullptr)
		{
			return;
		}

		const bool bFatal = NewHealth <= 0.0f;
		if (bFatal == false)
		{
			return;
		}

		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Health After Damage: [%f]"), NewHealth));
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Damage Dealt: [%f]"), LocalDamage));
		Target->HandleDeath();
	}
}

void UZombieAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, Health, OldHealth);
}

void UZombieAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, MaxHealth, OldMaxHealth);
}

void UZombieAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, MovementSpeed, OldMovementSpeed);
}

void UZombieAttributeSet::OnRep_CriticalChance(const FGameplayAttributeData& OldCritChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UZombieAttributeSet, CriticalChance, OldCritChance);
}

void UZombieAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	//Source = Cause of the Effect.
	//Target = Target of the effect (Owner of this AttributeSet).
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceAbiltiySystemComponent = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
	if (IsValid(Props.SourceAbiltiySystemComponent) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ability System Component is invalid"));
		return;
	}

	Props.SourceAvatarActor = Props.SourceAbiltiySystemComponent->AbilityActorInfo->AvatarActor.Get();
	if (IsValid(Props.SourceAvatarActor) == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor is Invalid."));
		return;
	}

	const AController* SourceController = Props.SourceAbiltiySystemComponent->AbilityActorInfo->PlayerController.Get();
	if (IsValid(SourceController) == false && IsValid(Props.SourceAvatarActor) == false)
	{
		if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
		{
			Props.SourceController = Pawn->GetController();
		}

		if (IsValid(Props.SourceController) == true)
		{
			Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Abiltiy Actor Info is invalid."));
		return;
	}

	if (Data.Target.AbilityActorInfo->AvatarActor.IsValid() == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Avatar Actor is invalid."));
		return;
	}

	Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
	Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
	Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
	Props.TargetAbiltiySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
}