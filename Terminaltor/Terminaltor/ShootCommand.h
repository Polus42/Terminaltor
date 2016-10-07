#pragma once
#include "Command.h"
#include "Character.h"

class ShootCommand :
	public Command
{
public:
	ShootCommand(Character *c);
	~ShootCommand();
	void execute();
private:
	Character *character;
};

