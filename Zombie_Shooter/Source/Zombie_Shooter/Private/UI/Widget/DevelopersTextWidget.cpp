// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/DevelopersTextWidget.h"
#include <UI/Widget/RichTextWidget.h>
#include "Components/RichTextBlock.h"
#include "Components/ScrollBox.h"

void UDevelopersTextWidget::NativeConstruct()
{
	for (FDeveloperRichText& DevInfo : Developers)
	{
		URichTextWidget* DeveloperWidget = CreateWidget<URichTextWidget>(this, DeveloperNameWidgetClass);

		FText FullDevInfo = FText::Format(FText::FromString("{0} - {1}"), DevInfo.Name, DevInfo.Role);

		DeveloperWidget->TextWidget->SetText(FullDevInfo);
		ListDevelopersScrollBox->AddChild(DeveloperWidget);
	}
}