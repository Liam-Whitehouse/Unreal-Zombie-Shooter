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
class UPortalManager;
class UGameStatsManager;

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
	TObjectPtr<URichTextButton> SignOutButton;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPortalManager> PortalManagerClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameStatsManager> GameStatsManagerClass;

	void AdjustWidgets();

protected:
	virtual void NativeConstruct() override;

private:

	FString GetAccessToken() const;

	UPROPERTY()
	TObjectPtr<UPortalManager> PortalManager;

	UPROPERTY()
	TObjectPtr<UGameStatsManager> GameStatsManager;
	
	UFUNCTION()
	void OnGameButtonClicked();

	UFUNCTION()
	void OnLeaderboardButtonClicked();

	UFUNCTION()
	void OnDevelopersButtonClicked();

	UFUNCTION()
	void OnQuitGameButtonClicked();

	UFUNCTION()
	void OnSignInButtonClicked();

	UFUNCTION()
	void OnSignOutButtonClicked();

	UFUNCTION()
	void LaunchSinglePlayer();
};
