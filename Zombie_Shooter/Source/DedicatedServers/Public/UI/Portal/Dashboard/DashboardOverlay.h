// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardOverlay.generated.h"

class UWidgetSwitcher;
class UGamePage;
class ULeaderboardsPage;
class URichTextButton;
class UWBP_DevelopersPage;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UDashboardOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UGamePage> Gamepage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<ULeaderboardsPage> LeaderboardsPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWBP_DevelopersPage> DevelopersPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> GamePageButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> LeaderboardButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> DevelopersButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> QuitGameButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignInButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignUpButton;

protected:
	virtual void NativeConstruct() override;
};
