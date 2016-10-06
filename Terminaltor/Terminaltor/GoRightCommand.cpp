#include "GoRightCommand.h"
#include "Character.h"
#include "Terrain.h"

GoRightCommand::GoRightCommand(Character *c,Terrain* t)
{
	character = c;
	terrain = t;
}


GoRightCommand::~GoRightCommand()
{
}

void GoRightCommand::execute()
{
	character->Move(1);
	//terrain->Slide(1);
}