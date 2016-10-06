#pragma once
#include "Command.h"
#include "Character.h"

class GoRightCommand : public Command
{
public:
	GoRightCommand(Character *c);
	~GoRightCommand();
	void execute();
private:
	Character *character;
};

