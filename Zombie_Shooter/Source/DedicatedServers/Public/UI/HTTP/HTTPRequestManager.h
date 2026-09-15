// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Interfaces/IHttpRequest.h"
#include "HTTPRequestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAPIStatusMessage, const FString&, StatusMessage, bool, bShouldResetWidget);

class UAPIData;
class FJsonObject;

/**
 * 
 */
UCLASS(Blueprintable)
class DEDICATEDSERVERS_API UHTTPRequestManager : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAPIData> APIData;
	
	void FocusPlayerControllerBackToScreen();

protected:
	
	bool ContainsErrors(TSharedPtr<FJsonObject> JsonObject);
	
	void DumpMetaData(TSharedPtr<FJsonObject> JsonObject) const;
	
	FString SerializedJsonContent(const TMap<FString, FString>& Params);
};
