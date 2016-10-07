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
	GameState::SetDelay(100);
	GameState::SetState(STATE_MENU);
}