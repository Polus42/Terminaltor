#pragma once
#include "Command.h"
#include "GameState.h"

class QuitCommand : public Command
{
public:
	QuitCommand(GameState* gameState);
	~QuitCommand();
	virtual void execute();

private:
	GameState* m_gameState;
};

