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
	UE_LOG(LogDedicatedServers, Log, TEXT("FDSCreatePlayerSession:"));
	
	UE_LOG(LogDedicatedServers, Log, TEXT("Creation Time: %s"), *CreationTime);
	UE_LOG(LogDedicatedServers, Log, TEXT("DnsName: %s"), *DnsName);
	UE_LOG(LogDedicatedServers, Log, TEXT("Fleet Arn: %s"), *FleetArn);
	UE_LOG(LogDedicatedServers, Log, TEXT("Fleet Id: %s"), *FleetId);
	UE_LOG(LogDedicatedServers, Log, TEXT("GameSession Id: %s"), *GameSessionId);
	UE_LOG(LogDedicatedServers, Log, TEXT("Ip Address: %s"), *IpAddress);
	UE_LOG(LogDedicatedServers, Log, TEXT("Player Data: %s"), *PlayerData);
	UE_LOG(LogDedicatedServers, Log, TEXT("Player Id: %s"), *PlayerId);
	UE_LOG(LogDedicatedServers, Log, TEXT("Player Session Id: %s"), *PlayerSessionId);
	UE_LOG(LogDedicatedServers, Log, TEXT("Port: %d"), Port);
	UE_LOG(LogDedicatedServers, Log, TEXT("Status: %s"), *Status);
	UE_LOG(LogDedicatedServers, Log, TEXT("Termination Time: %s"), *TerminationTime);
}

void FDSCodeDeliveryDetails::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("Attribute Name: % s"), *AttributeName);
	UE_LOG(LogDedicatedServers, Log, TEXT("Delivery Medium: % s"), *DeliveryMedium);
	UE_LOG(LogDedicatedServers, Log, TEXT("Destination: % s"), *Destination);
}

void FDSSignUpResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("FDSSignUpResponse:"));

	CodeDeliveryDetails.Dump();

	UE_LOG(LogDedicatedServers, Log, TEXT("User Confirmed: %s"), (UserConfirmed ? TEXT("True"): TEXT("False") ));
	UE_LOG(LogDedicatedServers, Log, TEXT("User Sub: %s"), *UserSub);
}

void FDSNewDeviceMetaData::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("Device Group Key: %s"), *DeviceGroupKey);
	UE_LOG(LogDedicatedServers, Log, TEXT("Device Key: %s"), *DeviceKey);
}

void FDSChallengeParameters::Dump() const
{
	for (auto Params : Parameters)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("Challenge Value: %s"), *Params.Value);
		UE_LOG(LogDedicatedServers, Log, TEXT("Challenge Key: %s"), *Params.Key);
	}
}

void FDSAuthenticationResult::Dump() const
{

	UE_LOG(LogDedicatedServers, Log, TEXT("Access Token: %s"), *AccessToken);
	UE_LOG(LogDedicatedServers, Log, TEXT("Expires In: %s"), *ExpiresIn);

	UE_LOG(LogDedicatedServers, Log, TEXT("Token In: %s"), *IdToken);

	NewDeviceMetaData.Dump();

	UE_LOG(LogDedicatedServers, Log, TEXT("Refresh Token: %s"), *RefreskToken);
	UE_LOG(LogDedicatedServers, Log, TEXT("Token Type: %s"), *TokenType);
}

void FDSInitiateAuthResponse::Dump() const
{
	AuthenticationResult.Dump();

	ChallengeParameters.Dump();

	UE_LOG(LogDedicatedServers, Log, TEXT("Challenge Name: %s"), *ChallengeName);
	UE_LOG(LogDedicatedServers, Log, TEXT("Session: %s"), *Session);
}