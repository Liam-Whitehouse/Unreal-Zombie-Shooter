// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UGameplayEffect;
class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayAbility;

UCLASS()
class ZOMBIE_SHOOTER_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UFUNCTION()
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UFUNCTION(BlueprintPure)
	virtual UAttributeSet* GetAttributeSet() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
	virtual void InitAbilityActorInfo();

	void InitializeVitalAttributes() const;
	void InitializePrimaryAttributes() const;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Vital Attributes")
	TSubclassOf<UGameplayEffect> VitalAttributes;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Primary Attributes")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;

	void InitializeAttributes(const TSubclassOf<UGameplayEffect> Attribute) const;

	virtual void InitializeDefaultAttributes();

	void AddCharacterAbilities(UAbilitySystemComponent* ASC) const;
	
private:
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

};
