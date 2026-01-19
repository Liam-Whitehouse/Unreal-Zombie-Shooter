// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "ZombieAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() {}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;
	UPROPERTY()
	AController* SourceController = nullptr;
	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;
	UPROPERTY()
	UAbilitySystemComponent* SourceAbiltiySystemComponent = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;
	UPROPERTY()
	AController* TargetController = nullptr;
	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
	UPROPERTY()
	UAbilitySystemComponent* TargetAbiltiySystemComponent = nullptr;
};

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UZombieAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UZombieAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UZombieAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MovementSpeed", Category = "Vital Attributes")
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UZombieAttributeSet, MovementSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_CriticalChance", Category = "Secondary Attributes")
	FGameplayAttributeData CriticalChance;
	ATTRIBUTE_ACCESSORS(UZombieAttributeSet, CriticalChance);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldMovementSpeed) const;

	UFUNCTION()
	void OnRep_CriticalChance(const FGameplayAttributeData& OldCritChance) const;

private:

	void SetEffectProperties(FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};