

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DSMatchPlayerState.generated.h"

class UGameStatsManager;
struct FDSRecordMatchStatsInput;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API ADSMatchPlayerState : public APlayerState
{
	GENERATED_BODY()
	
	
public:

	virtual void OnMatchEnded(const FString& Username);
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameStatsManager> GameStatsManagerClass;

protected:
	virtual void BeginPlay() override;

	void RecordMatchStats(const FDSRecordMatchStatsInput& RecordMatchStatsInput) const;

	void UpdateLeaderboard(const FString& Username) const;

private:


	UPROPERTY()
	TObjectPtr<UGameStatsManager> GameStatsManager;
};
