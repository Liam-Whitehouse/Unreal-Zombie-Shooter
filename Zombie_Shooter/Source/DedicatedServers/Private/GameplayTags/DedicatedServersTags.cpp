#include "GameplayTags/DedicatedServersTags.h"

namespace DedicatedServersTags
{
	namespace GameSessionsAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ListFleets, "DedicatedServers.GameSessions.ListFleets", "List Fleets Resource on the GameSessions API.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(FindOrCreateGameSession, "DedicatedServers.GameSessions.FindOrCreateGameSession", "Retrieves an Active Game Session, creating one if one doesnt exist on the GameSessions API.");
	}
}