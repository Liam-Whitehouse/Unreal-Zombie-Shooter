// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/ZombiePlayerState.h"
#include "AbilitySystem/ZombieAbilitySystemComponent.h"
#include "AbilitySystem/ZombieAttributeSet.h"
#include <Net/UnrealNetwork.h>
#include "DedicatedServers/Public/UI/HTTP/HTTPRequestTypes.h"
#include <Subsystems/Player/DSLocalPlayerSubsystem.h>

AZombiePlayerState::AZombiePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UZombieAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UZombieAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.0f);

	ZombiesKilled = 0;
}

void AZombiePlayerState::OnMatchEnded(const FString& Username)
{
	Super::OnMatchEnded(Username);

	APlayerController* PlayerController = GetPlayerController();
	if (!IsValid(PlayerController))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller is invalid in [%s]"), *GetName());
		return;
	}

	ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
	if (!IsValid(LocalPlayer))
	{
		UE_LOG(LogTemp, Warning, TEXT("Local Player is invalid in [%s]"), *GetName());
		return;
	}

	UDSLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UDSLocalPlayerSubsystem>();
	if (IsValid(Subsystem))
	{
		if (Subsystem->GetIsLoggedIn())
		{
			FDSRecordMatchStatsInput RecordMatchStatsInput;
			RecordMatchStatsInput.username = Username;
			RecordMatchStatsInput.matchStats.kills = ZombiesKilled;

			UpdateLeaderboard(Username);
			RecordMatchStats(RecordMatchStatsInput);
		}
	}
}

void AZombiePlayerState::BeginPlay()
{
	Super::BeginPlay();

}

UAbilitySystemComponent* AZombiePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

int32 AZombiePlayerState::GetZombiesKilled()
{
	return ZombiesKilled;
}

void AZombiePlayerState::IncrementZombiesKilled()
{
	ZombiesKilled++;
}

void AZombiePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AZombiePlayerState, ZombiesKilled);
}