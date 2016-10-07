#pragma once
#include "Command.h"
#include "Character.h"

class GoLeftCommand: public Command
{
public:
	GoLeftCommand(Character *c);
	~GoLeftCommand();
	void execute();

private:
	Character *character;
};

