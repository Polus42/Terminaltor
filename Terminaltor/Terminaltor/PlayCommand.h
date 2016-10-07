#pragma once
#include "Command.h"

class PlayCommand : public Command
{
public:
	PlayCommand();
	~PlayCommand();
	void execute();
};

