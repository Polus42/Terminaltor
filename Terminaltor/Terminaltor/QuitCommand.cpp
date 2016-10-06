#include "QuitCommand.h"
#include "windows.h"

QuitCommand::QuitCommand(GameState* gameState):
m_gameState(gameState)
{
}


QuitCommand::~QuitCommand()
{
}

void QuitCommand::execute()
{
	m_gameState->SetState(STATE_EXIT);
}