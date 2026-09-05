#include "UI/HTTP/HTTPRequestTypes.h"
#include "DedicatedServers/DedicatedServers.h"

namespace HTTPStatusMessages
{
	const FString SomethingWentWrong{TEXT("Something went wrong!")};
}

void FDSMetaData::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("Meta Data"));
	
	UE_LOG(LogDedicatedServers, Log, TEXT("HTTP Status Code: %d"), httpStatusCode);
	UE_LOG(LogDedicatedServers, Log, TEXT("Request ID: %s"), *requestID);
	UE_LOG(LogDedicatedServers, Log, TEXT("Attempts: %d"), attempts);
	UE_LOG(LogDedicatedServers, Log, TEXT("Total Retry Delay: %f"), totalRetryDelay);
}

void FDSListFleetsResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("List Fleets Response"));
	
	for (const FString& ID : FleetIds)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("Fleet ID: %s"), *ID);
	}
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Next Token: %s"), *NextToken);
}

void FDSGameSession::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("Game Session"));
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Creation Time: %s"), *CreationTime);
	UE_LOG(LogDedicatedServers, Log, TEXT("Creator ID: %s"), *CreatorId);
	UE_LOG(LogDedicatedServers, Log, TEXT("Current Player Session Count: %d"), CurrentPlayerSessionCount);
	UE_LOG(LogDedicatedServers, Log, TEXT("Dns Name: %s"), *DnsName);
	UE_LOG(LogDedicatedServers, Log, TEXT("Fleet Arn: %s"), *FleetArn);
	UE_LOG(LogDedicatedServers, Log, TEXT("Fleet ID: %s"), *FleetId);
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Game Properties"));
	for (const TTuple<FString, FString> GameProperty : GameProperties)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("Key: %s, Value: %s"), *GameProperty.Key, *GameProperty.Value);
	}
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Game Session Data: %s"), *GameSessionData);
	UE_LOG(LogDedicatedServers, Log, TEXT("Game Session ID: %s"), *GameSessionId);
	UE_LOG(LogDedicatedServers, Log, TEXT("IP Address: %s"), *IpAddress);
	UE_LOG(LogDedicatedServers, Log, TEXT("Location: %s"), *Location);
	UE_LOG(LogDedicatedServers, Log, TEXT("Matchmaker Data: %s"), *MatchmakerData);
	UE_LOG(LogDedicatedServers, Log, TEXT("Maximum Player Session Count: %d"), MaximumPlayerSessionCount);
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Name: %s"), *Name);
	UE_LOG(LogDedicatedServers, Log, TEXT("Player Session Creation Policy: %s"), *PlayerSessionCreationPolicy);
	UE_LOG(LogDedicatedServers, Log, TEXT("Port: %d"), Port);
	UE_LOG(LogDedicatedServers, Log, TEXT("Status: %s"), *Status);
	UE_LOG(LogDedicatedServers, Log, TEXT("Status Reason: %s"), *StatusReason);
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Termination Time: %s"), *TerminationTime);
}

void FDSPlayerSession::Dump() const
{
	UE_LOG(LogTemp, Log, TEXT("FDSCreatePlayerSession:"));
	
	UE_LOG(LogTemp, Log, TEXT("Creation Time: %s"), *CreationTime);
	UE_LOG(LogTemp, Log, TEXT("DnsName: %s"), *DnsName);
	UE_LOG(LogTemp, Log, TEXT("Fleet Arn: %s"), *FleetArn);
	UE_LOG(LogTemp, Log, TEXT("Fleet Id: %s"), *FleetId);
	UE_LOG(LogTemp, Log, TEXT("GameSession Id: %s"), *GameSessionId);
	UE_LOG(LogTemp, Log, TEXT("Ip Address: %s"), *IpAddress);
	UE_LOG(LogTemp, Log, TEXT("Player Data: %s"), *PlayerData);
	UE_LOG(LogTemp, Log, TEXT("Player Id: %s"), *PlayerId);
	UE_LOG(LogTemp, Log, TEXT("Player Session Id: %s"), *PlayerSessionId);
	UE_LOG(LogTemp, Log, TEXT("Port: %d"), Port);
	UE_LOG(LogTemp, Log, TEXT("Status: %s"), *Status);
	UE_LOG(LogTemp, Log, TEXT("Termination Time: %s"), *TerminationTime);
}

