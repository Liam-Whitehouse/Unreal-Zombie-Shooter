// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/APITest/APITestOverlay.h"
#include "UI/APITest/APITestManager.h"
#include "UI/API/ListFleets/ListFleetsBox.h"
#include "Components/Button.h"
#include "Components/RichTextBlock.h"
#include "Components/ScrollBox.h"
#include "UI/API/ListFleets/FleetID.h"
#include "UI/HTTP/HTTPRequestTypes.h"

void UAPITestOverlay::NativeConstruct()
{
	Super::NativeConstruct();

	check(APITestManagerClass);
	APITestManager = NewObject<UAPITestManager>(this, APITestManagerClass);

	check(ListFleetsBox)
	check(ListFleetsBox->ListFleetsButton)
	ListFleetsBox->ListFleetsButton->OnClicked.AddDynamic(this, &UAPITestOverlay::ListFleetsButtonClicked);
}

void UAPITestOverlay::ListFleetsButtonClicked()
{
	check(APITestManager);
	APITestManager->OnListFleetResponseReceived.AddDynamic(this, &UAPITestOverlay::OnListFleetsResponseReceived);
	APITestManager->ListFleets();
	ListFleetsBox->ListFleetsButton->SetIsEnabled(false);
}

void UAPITestOverlay::OnListFleetsResponseReceived(const FDSListFleetsResponse& ListFleetsReponse, bool bWasSuccessful)
{
	if (APITestManager->OnListFleetResponseReceived.IsAlreadyBound(this, &UAPITestOverlay::OnListFleetsResponseReceived))
	{
		APITestManager->OnListFleetResponseReceived.RemoveDynamic(this, &UAPITestOverlay::OnListFleetsResponseReceived);
	}
	
	ListFleetsBox->ListFleetsScrollBox->ClearChildren();
	
	if (bWasSuccessful)
	{
		for (const FString& FleetId : ListFleetsReponse.FleetIds)
		{
			UFleetID* FleetIdBox = CreateWidget<UFleetID>(this, FleetIDWidgetClass);
			FleetIdBox->FleetIDRichText->SetText(FText::FromString(FleetId));
			ListFleetsBox->ListFleetsScrollBox->AddChild(FleetIdBox);
		}
	}
	else
	{
		UFleetID* FleetIdBox = CreateWidget<UFleetID>(this, FleetIDWidgetClass);
		FleetIdBox->FleetIDRichText->SetText(FText::FromString("Error Occured!"));
		ListFleetsBox->ListFleetsScrollBox->AddChild(FleetIdBox);
	}
	
	ListFleetsBox->ListFleetsButton->SetIsEnabled(true);
}