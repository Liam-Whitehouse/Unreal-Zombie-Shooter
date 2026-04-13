// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/ZombieUserWidget.h"
#include "ZombieAttributeWidgetController.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

USTRUCT(BlueprintType)
struct FZombieWidgetControllerParams
{
	GENERATED_BODY()

	FZombieWidgetControllerParams() {}
	FZombieWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS) :
		PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS) {
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieAttributeWidgetController : public UZombieUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetupWidgetControllerParams(const FZombieWidgetControllerParams& Params);

	void BindCallbackToDependencies() override;
	void BroadcastInitialValues() override;

protected:

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAttributeSet> AttributeSet;
};
