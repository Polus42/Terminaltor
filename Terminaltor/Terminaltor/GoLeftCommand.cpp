#include "GoLeftCommand.h"

GoLeftCommand::GoLeftCommand(Character *c)
{
	character = c;
}

GoLeftCommand::~GoLeftCommand()
{
}

void GoLeftCommand::execute()
{
	//*
	character->Move(-1);/*/
	terrain->Slide(100);//*/
}