#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JoinGame.generated.h"

class URichTextBlock;
class UButton;
/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UJoinGame : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> JoinGameButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> StatusMessage;
	
	void SetStatusMessage(const FString& Message) const;
};