// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HTTP/HTTPRequestManager.h"

#include "JsonObjectConverter.h"
#include "DedicatedServers/DedicatedServers.h"
#include "UI/HTTP/HTTPRequestTypes.h"


bool UHTTPRequestManager::ContainsErrors(TSharedPtr<FJsonObject> JsonObject)
{
	if (JsonObject->HasField("errorType") || JsonObject->HasField("errorMessage"))
	{
		FString ErrorType = JsonObject->HasField("errorType") ? JsonObject->GetStringField("errorType") : TEXT("Unknown Error");
		FString ErrorMessage = JsonObject->HasField("errorMessage") ? JsonObject->GetStringField("errorMessage") : TEXT("Unknown Error Message");
			
		UE_LOG(LogDedicatedServers, Error, TEXT("Error Type: %s, Error Message: %s"), *ErrorType, *ErrorMessage);
			
		return true;
	}

	if (JsonObject->HasField("$fault"))
	{
		FString FaultType = JsonObject->HasField("name") ? JsonObject->GetStringField("name") : TEXT("Unknown Error");
		UE_LOG(LogDedicatedServers, Error, TEXT("Error Type: %s"), *FaultType);
			
		return true;
	}
	
	return false;
}

void UHTTPRequestManager::DumpMetaData(TSharedPtr<FJsonObject> JsonObject) const
{
	if (JsonObject->HasField(TEXT("$metadata")))
	{
		TSharedPtr<FJsonObject> MetaDataJsonObject = JsonObject->GetObjectField(TEXT("$metadata"));
		FDSMetaData DSMetaData;
		FJsonObjectConverter::JsonObjectToUStruct(MetaDataJsonObject.ToSharedRef(), &DSMetaData);
			
		DSMetaData.Dump();
	}
}