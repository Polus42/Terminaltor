#include "MenuCommand.h"
#include "GameState.h"

MenuCommand::MenuCommand()
{
}

MenuCommand::~MenuCommand()
{
}

void MenuCommand::execute()
{
	GameState::SetDelay(0.1f);
	GameState::SetState(STATE_MENU);
}