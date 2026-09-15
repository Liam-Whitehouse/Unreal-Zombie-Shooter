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
	TObjectPtr<URichTextButton> LaunchSinglePlayerWidget;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> QuitGameWidget;
	
	/* Test Buttpms for switching Widgets */

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignInButtonTest;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SignUpButtonTest;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> ConfirmationSignUpButtonTest;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextButton> SuccessConfirmedButtonTest;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPortalManager> PortalManagerClass;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher;

protected:
	virtual void NativeConstruct() override;
	
private:
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USignInPage> SignInPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USignUpPage> SignUpPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UConfirmationSignUpPage> ConfirmationSignUpPage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USuccessConfirmedPage> SuccessConfirmPage;

	UPROPERTY()
	TObjectPtr<UPortalManager> PortalManager;

	UFUNCTION()
	void OnQuitGameButtonClicked();
	
	UFUNCTION()
	void OnLaunchSinglePlayerButtonClicked();

	/* Test Button Switching */

	UFUNCTION()
	void ShowSignInPage();

	UFUNCTION()
	void ShowSignUpPage();

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
};