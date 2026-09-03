// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "APITestOverlay.generated.h"

struct FDSListFleetsResponse;
class UListFleetsBox;
class UAPITestManager;
class UFleetID;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UAPITestOverlay : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAPITestManager> APITestManagerClass;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UFleetID> FleetIDWidgetClass;

protected:

	virtual void NativeConstruct() override;

private:

	UFUNCTION()
	void ListFleetsButtonClicked();
	
	UFUNCTION()
	void OnListFleetsResponseReceived(const FDSListFleetsResponse& ListFleetsReponse, bool bWasSuccessful);
	
	UPROPERTY()
	TObjectPtr<UAPITestManager> APITestManager;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UListFleetsBox> ListFleetsBox;
};
