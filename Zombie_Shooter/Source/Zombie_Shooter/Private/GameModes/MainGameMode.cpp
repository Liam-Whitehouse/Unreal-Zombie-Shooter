// Fill out your copyright notice in the Description page of Project Settings.

#include "GameModes/MainGameMode.h"
#include <Kismet/GameplayStatics.h>

#include "Controller/SurvivorController.h"
#include <Subsystems/Player/DSMatchPlayerState.h>

AMainGameMode::AMainGameMode()
{

}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);

	const FString PlayerSessionID = UGameplayStatics::ParseOption(Options, TEXT("PlayerSessionId"));
	const FString Username = UGameplayStatics::ParseOption(Options, TEXT("Username"));

	TryAcceptPlayerSession(PlayerSessionID, Username, ErrorMessage);
	
	UE_LOG(LogTemp, Warning, TEXT("ProLogin has been called and has initialized the player"));
}

void AMainGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	ASurvivorController* SurvivorController = Cast<ASurvivorController>(Exiting);
	if (!IsValid(SurvivorController))
	{
		UE_LOG(LogTemp, Warning, TEXT("Controller is not of type ASurvivorController"));
		return;
	}
	
	const FString& PlayerSessionID = SurvivorController->PlayerSessionID;
	UE_LOG(LogTemp, Warning, TEXT("Removing Player Session [%s]"), *PlayerSessionID);

	//Record Match Stats Here
	ADSMatchPlayerState* MatchPlayerState = SurvivorController->GetPlayerState<ADSMatchPlayerState>();
	if (IsValid(MatchPlayerState))
	{
		MatchPlayerState->OnMatchEnded(SurvivorController->Username);
	}

#if WITH_GAMELIFT
	if (!PlayerSessionID.IsEmpty())
	{
		Aws::GameLift::Server::RemovePlayerSession(TCHAR_TO_ANSI(*PlayerSessionID));
	}
	
#endif
	UE_LOG(LogTemp, Warning, TEXT("Logout has been called and has removed the player"));
}

FString AMainGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	FString InitializedString = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);

	const FString PlayerSessionID = UGameplayStatics::ParseOption(Options, TEXT("PlayerSessionId"));
	const FString Username = UGameplayStatics::ParseOption(Options, TEXT("Username"));

	ASurvivorController* SurvivorController = Cast<ASurvivorController>(NewPlayerController);
	if (IsValid(SurvivorController))
	{
		SurvivorController->PlayerSessionID = PlayerSessionID;
		SurvivorController->Username = Username;
	}

	return InitializedString;
}

void AMainGameMode::TryAcceptPlayerSession(const FString& PlayerSessionID, const FString& Username, FString& OutErrorMessage)
{
	if (PlayerSessionID.IsEmpty() || Username.IsEmpty())
	{
		OutErrorMessage = TEXT("Player SessionID or the Username is invalid");
		return;
	}



#if WITH_GAMELIFT
	Aws::GameLift::Server::Model::DescribePlayerSessionsRequest DescribePlayerSessionsRequest;
	DescribePlayerSessionsRequest.SetPlayerSessionId(TCHAR_TO_ANSI(*PlayerSessionID));

	const auto& DescribePlayerSessionsOutcome = Aws::GameLift::Server::DescribePlayerSessions(DescribePlayerSessionsRequest);
	if (!DescribePlayerSessionsOutcome.IsSuccess())
	{
		OutErrorMessage = TEXT("Describe Player Sessions Failed");
		return;
	}

	const auto& DescribePlayerSessionsResult = DescribePlayerSessionsOutcome.GetResult();
	int32 Count = 0;
	const Aws::GameLift::Server::Model::PlayerSession* PlayerSessions = DescribePlayerSessionsResult.GetPlayerSessions(Count);

	if (PlayerSessions == nullptr || Count == 0)
	{
		OutErrorMessage = TEXT("Player Sessions is Empty.");
		return;
	}

	for (int32 i = 0; i < Count; i++)
	{
		const Aws::GameLift::Server::Model::PlayerSession& PlayerSession = PlayerSessions[i];

		if (!Username.Equals(PlayerSession.GetPlayerId()))
		{
			continue;
		}

		if (PlayerSession.GetStatus() != Aws::GameLift::Server::Model::PlayerSessionStatus::RESERVED)
		{
			OutErrorMessage = FString::Printf(TEXT("Session for %s not RESERVED. Failed PreLogin."), *Username);
			return;
		}

		const auto& AcceptPlayerSessionOutcome = Aws::GameLift::Server::AcceptPlayerSession(TCHAR_TO_ANSI(*PlayerSessionID));

		OutErrorMessage = AcceptPlayerSessionOutcome.IsSuccess() ? TEXT("") : FString::Printf(TEXT("Failed to accept Player Session for %s"), *Username);
	}
#endif
}

void AMainGameMode::AddZombieCount()
{
	if (HasAuthority() == false)
	{
		return;
	}

	CurrentZombieAmount++;
}

void AMainGameMode::DecreaseZombieCount()
{
	if (HasAuthority() == false)
	{
		return;
	}

	CurrentZombieAmount--;
}

bool AMainGameMode::HasReachedMaxZombieCount() const
{
	if (HasAuthority() == false)
	{
		return false;
	}

	if (CurrentZombieAmount >= MaxZombieAmount)
	{
		return true;
	}

	return false;
}