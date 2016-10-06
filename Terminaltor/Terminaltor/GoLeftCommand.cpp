#include "GoLeftCommand.h"


GoLeftCommand::GoLeftCommand(Character *c, Terrain* t)
{
	character = c;
	terrain = t;
}


GoLeftCommand::~GoLeftCommand()
{
}

void GoLeftCommand::execute()
{
	//character->Move(-1);
	terrain->Slide(1);
}