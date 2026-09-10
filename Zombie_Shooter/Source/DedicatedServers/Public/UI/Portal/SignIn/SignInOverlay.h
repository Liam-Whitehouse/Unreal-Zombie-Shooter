#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/HTTP/PortalManager.h"
#include "SignInOverlay.generated.h"

class UPortalManager;
class UJoinGame;
class URichTextBlock;
class URichTextButton;

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
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UJoinGame> JoinGameWidget;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPortalManager> PortalManagerClass;

protected:
	virtual void NativeConstruct() override;
	
private:
	
	UPROPERTY()
	TObjectPtr<UPortalManager> PortalManager;
	
	UFUNCTION()
	void OnJoinGameButtonClicked();

	UFUNCTION()
	void OnQuitGameButtonClicked();
	
	UFUNCTION()
	void OnLaunchSinglePlayerButtonClicked();
	
	UFUNCTION()
	void UpdateJoinGameStatusMessage(const FString& Message, bool bResetJoinGameButton);
};