// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ZombieUserWidget.generated.h"

struct FZombieWidgetControllerParams;
class UZombieAttributeWidgetController;
class UZombieCountWidget;

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

	//UFUNCTION(BlueprintCallable)
	void SetupAIWidgetController(const FZombieWidgetControllerParams& Params);

	UFUNCTION(BlueprintPure)
	UObject* GetWidgetController();

	virtual void BindCallbackToDependencies();
	virtual void BroadcastInitialValues();

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UZombieCountWidget> ZombieKillCounterWidget;

	void UpdateKillCounter();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

	virtual void NativeConstruct() override;

private:
	UPROPERTY()
	TObjectPtr<UZombieAttributeWidgetController> AIWidgetController;


	UPROPERTY(EditAnywhere)
	TSubclassOf<UZombieAttributeWidgetController> AIWidgetControllerClass;

};