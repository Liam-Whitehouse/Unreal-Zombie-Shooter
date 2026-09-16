// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/HTTP/PortalManager.h"

#include "Kismet/GameplayStatics.h"
#include "HttpModule.h"
#include "GameplayTags/DedicatedServersTags.h"
#include "Data/API/APIData.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"
#include <Subsystems/Player/DSLocalPlayerSubsystem.h>

void UPortalManager::SignIn(const FString& Username, const FString& Password)
{
	SignInStatusMessageMessageDelegate.Broadcast(TEXT("Logging In!"), false);

	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::SignIn_Response);

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::PortalAPI::SignIn);

	//Sets the Request URL
	Request->SetURL(APIUrl);

	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("POST"));

	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	LastUsername = Username;

	TMap<FString, FString> Params = {
		{ TEXT("username"), Username },
		{ TEXT("password"), Password }
	};

	const FString Content = SerializedJsonContent(Params);

	Request->SetContentAsString(Content);
	Request->ProcessRequest();
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

	LastUsername = Username;

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
	check(APIData);

	ConfirmStatusMessageDelegate.Broadcast(TEXT("Checking Verification Code..."), false);

	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::Confirm_Response);

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::PortalAPI::ConfirmSignUp);

	//Sets the Request URL
	Request->SetURL(APIUrl);

	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("PUT"));

	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	TMap<FString, FString> Params = {
		{ TEXT("username"), LastUsername },
		{ TEXT("confirmationCode"), ConfirmationCode }
	};

	const FString Content = SerializedJsonContent(Params);

	Request->SetContentAsString(Content);
	Request->ProcessRequest();
}

void UPortalManager::RefreshToken(const FString& RefreshToken)
{
	check(APIData);
	TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();

	Request->OnProcessRequestComplete().BindUObject(this, &UPortalManager::RefreshToken_Response);

	const FString APIUrl = APIData->GetAPIEndPoint(DedicatedServersTags::PortalAPI::SignIn);

	//Sets the Request URL
	Request->SetURL(APIUrl);

	//Sets what Type of Request we want (POST in this case)
	Request->SetVerb(TEXT("POST"));

	//Sets the Header information for this request.
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	TMap<FString, FString> Params = {
		{ TEXT("refreshToken"), RefreshToken },
	};

	const FString Content = SerializedJsonContent(Params);

	Request->SetContentAsString(Content);
	Request->ProcessRequest();
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
		
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			FString Exception = JsonObject->GetStringField(TEXT("message"));
			if (Exception.Contains("A User with this email already exists"))
			{	
				SignUpStatusMessageDelegate.Broadcast(HTTPStatusMessages::EmailAddressIsNotUnique, true);
				return;
			}

			SignUpStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
			return;
		}
	
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &LastSignUpResponse);
		OnAPIRequestSucceeded.Broadcast();
	}
}

void UPortalManager::SignIn_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		SignInStatusMessageMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			FString Exception = JsonObject->GetStringField(TEXT("message"));
			if (Exception.Contains("Incorrect Username or Password"))
			{
				SignInStatusMessageMessageDelegate.Broadcast(HTTPStatusMessages::CredentialsIncorrect, true);
				return;
			}

			SignInStatusMessageMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
			return;
		}

		FDSInitiateAuthResponse AuthResponse;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &AuthResponse);

		UDSLocalPlayerSubsystem* Subsystem = GetDSLocalPlayerSubSystem();
		if (IsValid(Subsystem))
		{
			Subsystem->InitTokens(AuthResponse.AuthenticationResult, this);
		}
	}
}

void UPortalManager::Confirm_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		ConfirmStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
		return;
	}


	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			if (JsonObject->HasField(TEXT("name")))
			{
				FString Exception = JsonObject->GetStringField(TEXT("name"));
				if (Exception.Equals(TEXT("CodeMismatchException")))
				{
					ConfirmStatusMessageDelegate.Broadcast(TEXT("Incorrect Verification Code."), true); 
					return;
				}
			}

			ConfirmStatusMessageDelegate.Broadcast(HTTPStatusMessages::SomethingWentWrong, true);
			return;
		}
	}

	OnConfirmSucceeded.Broadcast();
}

void UPortalManager::RefreshToken_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (FJsonSerializer::Deserialize(JsonReader, JsonObject))
	{
		if (ContainsErrors(JsonObject))
		{
			return;
		}

		FDSInitiateAuthResponse AuthResponse;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject.ToSharedRef(), &AuthResponse);

		UDSLocalPlayerSubsystem* Subsystem = GetDSLocalPlayerSubSystem();
		if (IsValid(Subsystem))
		{
			Subsystem->UpdateTokens(AuthResponse.AuthenticationResult.AccessToken, AuthResponse.AuthenticationResult.IdToken);
		}
	}
}