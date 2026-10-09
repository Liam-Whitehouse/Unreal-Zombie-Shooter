#include "Subsystems/Player/DSMatchPlayerState.h"
#include "UI/GameStats/GameStatsManager.h"


void ADSMatchPlayerState::OnMatchEnded(const FString& Username)
{
	
}

void ADSMatchPlayerState::BeginPlay()
{
	Super::BeginPlay();

	GameStatsManager = NewObject<UGameStatsManager>(this, GameStatsManagerClass);
}

void ADSMatchPlayerState::RecordMatchStats(const FDSRecordMatchStatsInput& RecordMatchStatsInput) const
{
	check(GameStatsManager);
	GameStatsManager->RecordMatchStats(RecordMatchStatsInput);
}

void ADSMatchPlayerState::UpdateLeaderboard(const FString& Username) const
{
	check(GameStatsManager);

	GameStatsManager->UpdateLeaderboard(Username);
}