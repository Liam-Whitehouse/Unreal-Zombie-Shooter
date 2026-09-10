// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DevelopersTextWidget.generated.h"

class UScrollBox;
class URichTextBlock;
class URichTextWidget;

USTRUCT()
struct FDeveloperRichText
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FText Name;

	UPROPERTY(EditDefaultsOnly)
	FText Role;
};

/**
 * 
 */
UCLASS()
class ZOMBIE_SHOOTER_API UDevelopersTextWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<URichTextBlock> DevelopersHeading;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UScrollBox> ListDevelopersScrollBox;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<URichTextWidget> DeveloperNameWidgetClass;

protected:
	virtual void NativeConstruct() override;
	
private:

	UPROPERTY(EditDefaultsOnly)
	TArray<FDeveloperRichText> Developers;

};
