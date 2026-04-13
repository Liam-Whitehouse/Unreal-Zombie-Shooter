// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"

class UZombieAttributeWidgetController;
struct FZombieWidgetControllerParams;
class UZombieUserWidget;

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:
	UZombieAttributeWidgetController* GetOverlayWidgetController(const FZombieWidgetControllerParams& Params);

	UPROPERTY()
	TObjectPtr<UZombieUserWidget> OverlayWidget;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UZombieUserWidget> OverlayWidgetClass;

};
