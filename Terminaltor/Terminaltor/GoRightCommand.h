#pragma once
#include "Command.h"
#include "Character.h"
#include "Terrain.h"
class GoRightCommand : public Command
{
public:
	GoRightCommand(Character *c, Terrain* t);
	~GoRightCommand();
	void execute();
private:
	Character *character;
	Terrain *terrain;
};

