#pragma once
#include "Command.h"
#include "GameState.h"

class QuitCommand : public Command
{
public:
	QuitCommand();
	~QuitCommand();
	virtual void execute();
};

