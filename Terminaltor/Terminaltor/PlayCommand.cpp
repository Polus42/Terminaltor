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
	GameState::SetDelay(33);
	GameState::SetState(STATE_PLAYING);
}