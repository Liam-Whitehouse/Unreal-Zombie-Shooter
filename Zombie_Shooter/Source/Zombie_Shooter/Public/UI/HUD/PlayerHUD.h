// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class UZombieAttributeWidgetController;
struct FZombieWidgetControllerParams;
class UZombieUserWidget;
class UAbilitySystemComponent;
class UAttributeSet;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	UZombieAttributeWidgetController* GetOverlayWidgetController(const FZombieWidgetControllerParams& Params);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UZombieUserWidget> OverlayWidget;

private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UZombieUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UZombieAttributeWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UZombieAttributeWidgetController> OverlayWidgetControllerClass;
};
