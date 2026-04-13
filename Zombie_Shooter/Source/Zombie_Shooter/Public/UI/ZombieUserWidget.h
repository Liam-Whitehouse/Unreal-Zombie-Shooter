// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieUserWidget.generated.h"

/**
 *
 */
UCLASS()
class ZOMBIE_SHOOTER_API UZombieUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	virtual void BindCallbackToDependencies();
	virtual void BroadcastInitialValues();

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

};