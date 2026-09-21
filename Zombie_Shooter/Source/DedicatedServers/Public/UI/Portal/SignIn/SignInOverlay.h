#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/HTTP/PortalManager.h"
#include "SignInOverlay.generated.h"

class UPortalManager;
class UJoinGame;
class URichTextBlock;
class URichTextButton;
class UWidgetSwitcher;
class USignInPage;
class USignUpPage;
class UConfirmationSignUpPage;
class USuccessConfirmedPage;
class UWBP_DevelopersPage;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API USignInOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> GameTitleText;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> PlayGameButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> LeaderboardsButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> DevelopersButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignInButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignOutButton;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> QuitGameWidget;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPortalManager> PortalManagerClass;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher;

	UFUNCTION()
	void ShowSignUpPage();

	UFUNCTION()
	void ShowSignInPage();

	void AdjustWidgets();

protected:
	virtual void NativeConstruct() override;
	
private:
	
	FString GetAccessToken() const;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USignInPage> SignInPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USignUpPage> SignUpPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UConfirmationSignUpPage> ConfirmationSignUpPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USuccessConfirmedPage> SuccessConfirmPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWBP_DevelopersPage> DevelopersPage;

	UPROPERTY()
	TObjectPtr<UPortalManager> PortalManager;

	UFUNCTION()
	void OnQuitGameButtonClicked();

	UFUNCTION()
	void OnPlayNowClicked();

	UFUNCTION()
	void OnShowDevelopersClicked();

	UFUNCTION()
	void ShowConfirmationSignUpPage();

	UFUNCTION()
	void ShowSuccessConfirmPage();

	UFUNCTION()
	void SignInButtonClicked();

	UFUNCTION()
	void SignUpButtonClicked();

	UFUNCTION()
	void ConfirmButtonClicked();

	UFUNCTION()
	void OnSignUpSucceeded();

	UFUNCTION()
	void OnConfirmSucceeded();
};