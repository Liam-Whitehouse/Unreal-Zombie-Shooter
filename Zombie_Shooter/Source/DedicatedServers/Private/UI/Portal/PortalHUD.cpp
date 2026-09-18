// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Portal/PortalHUD.h"
#include "UI/Portal/SignIn/SignInOverlay.h"
#include "UI/Portal/Dashboard/DashboardOverlay.h"
#include "Blueprint/UserWidget.h"

void APortalHUD::OnSignIn()
{
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->RemoveFromParent();
	}

	APlayerController* PlayerController = GetOwningPlayerController();
	DashboardOverlay = CreateWidget<UDashboardOverlay>(PlayerController, DashboardOverlayClass);
	if (IsValid(DashboardOverlay))
	{
		DashboardOverlay->AddToViewport();
		DashboardOverlay->AdjustWidgets();
	}
}

void APortalHUD::OnOfflinePlayNow()
{
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->RemoveFromParent();
	}

	APlayerController* PlayerController = GetOwningPlayerController();
	DashboardOverlay = CreateWidget<UDashboardOverlay>(PlayerController, DashboardOverlayClass);
	if (IsValid(DashboardOverlay))
	{
		//Set the Dashboard Widget to Play Now Options 
		DashboardOverlay->AddToViewport();
		DashboardOverlay->AdjustWidgets();
	}
}

void APortalHUD::EnterSignInMenu()
{
	if (IsValid(DashboardOverlay))
	{
		DashboardOverlay->RemoveFromParent();
	}

	APlayerController* PlayerController = GetOwningPlayerController();
	SignInOverlay = CreateWidget<USignInOverlay>(PlayerController, SignInOverlayClass);
	if (IsValid(SignInOverlay))
	{
		//Set the Dashboard Widget to Play Now Options 
		SignInOverlay->AddToViewport();
		SignInOverlay->AdjustWidgets();
		SignInOverlay->ShowSignInPage();
	}
}

void APortalHUD::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = GetOwningPlayerController();
	SignInOverlay = CreateWidget<USignInOverlay>(PlayerController, SignInOverlayClass);
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->AddToViewport();
		SignInOverlay->AdjustWidgets();
	}
	
	FInputModeGameAndUI InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}