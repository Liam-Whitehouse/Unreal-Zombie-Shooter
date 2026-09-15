#include "GameplayTags/DedicatedServersTags.h"

namespace DedicatedServersTags
{
	namespace GameSessionsAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ListFleets, "DedicatedServers.GameSessions.ListFleets", "List Fleets Resource on the GameSessions API.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(FindOrCreateGameSession, "DedicatedServers.GameSessions.FindOrCreateGameSession", "Retrieves an Active Game Session, creating one if one doesnt exist on the GameSessions API.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(CreatePlayerSession, "DedicatedServers.GameSessions.CreatePlayerSession", "Create a new Player Session on the GameSessions API.");
	}

	namespace PortalAPI
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(SignUp, "DedicatedServers.Portal.SignUp", "Creates a New Player in the Portal API.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ConfirmSignUp, "DedicatedServers.Portal.ConfirmSignUp", "Confirms the players Sign Up using the Portal API.");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(SignIn, "DedicatedServers.Portal.SignIn", "Retrieves Access Token, ID Token and Refresh Token for the Player in the Portal API.");
	}
}