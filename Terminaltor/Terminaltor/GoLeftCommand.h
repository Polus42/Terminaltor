#pragma once
#include "Command.h"
#include "Character.h"
#include "Terrain.h"
class GoLeftCommand: public Command
{
public:
	GoLeftCommand(Character *c, Terrain* t);
	~GoLeftCommand();
	void execute();
private:
	Character *character;
	Terrain *terrain;
};

