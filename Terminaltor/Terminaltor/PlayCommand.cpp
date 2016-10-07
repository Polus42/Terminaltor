#include "PlayCommand.h"
#include "GameState.h"

PlayCommand::PlayCommand()
{
}

PlayCommand::~PlayCommand()
{
}

void PlayCommand::execute()
{
	GameState::SetDelay(0.033f);
	GameState::SetState(STATE_PLAYING);
}