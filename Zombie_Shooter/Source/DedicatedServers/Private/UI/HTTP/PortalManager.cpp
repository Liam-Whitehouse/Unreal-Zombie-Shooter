// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HTTP/PortalManager.h"

#include "Kismet/GameplayStatics.h"
#include "HttpModule.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "Data/API/APIData.h"
#include <UI/HTTP/HTTPRequestTypes.h>
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"

void UPortalManager::SignIn(const FString& Username, const FString& Password)
{

}

void UPortalManager::SignUp(const FString& Username, const FString& Password, const FString& Email)
{
	SignUpStatusMessageDelegate.Broadcast(TEXT("Creating a New Account!"), false);

	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::SignUp_Response);

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::PortalAPI::SignUp);

	//Sets the Request URL
	Request->SetURL(APIUrl);

	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("POST"));

	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	TMap<FString, FString> Params = {
		{ TEXT("username"), Username },
		{ TEXT("password"), Password },
		{ TEXT("email"), Email }
	};

	const FString Content = SerializedJsonContent(Params);

	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::ConfirmationCode(const FString& ConfirmationCode)
{

}

void UPortalManager::LaunchSinglePlayerGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("MainLevel")));
	
	FocusPlayerControllerBackToScreen();
}

void UPortalManager::SignUp_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		SignUpStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
	}


	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			SignUpStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
		}
	
		FDSSignUpResponse SignUpResponse;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &SignUpResponse);
		SignUpResponse.Dump();



	}
}