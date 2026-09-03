#include "UI/HTTP/HTTPRequestTypes.h"
#include "DedicatedServers/DedicatedServers.h"

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