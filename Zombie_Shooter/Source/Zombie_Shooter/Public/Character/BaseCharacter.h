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
	
	void UpdateCharacterSpeed(float NewSpeed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Server, Reliable)
	virtual void HandleDeath();

	UFUNCTION(NetMulticast, Reliable)
	virtual void MulticastHandleDeath();

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

	void AddCharacterAbilities() const;

	//Used for both AI and Players Death
	FTimerHandle DeathTimer;

	//Used for both AI and Players Death
	UPROPERTY(EditDefaultsOnly, Category = "Death Timer")
	float DeathCountDown = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Death - Ability")
	TSubclassOf<UGameplayAbility> DeathAbility;
	
	UPROPERTY(EditAnywhere, Category = "Spawn - Ability")
	TSubclassOf<UGameplayAbility> SpawnAbility;
	
private:
	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};
