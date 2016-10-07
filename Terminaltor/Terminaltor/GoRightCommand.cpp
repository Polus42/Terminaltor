#include "GoRightCommand.h"

GoRightCommand::GoRightCommand(Character *c)
{
	character = c;
}


GoRightCommand::~GoRightCommand()
{
}

void GoRightCommand::execute()
{
	//*
	character->Move(1);/*/
	terrain->Slide(100);//*/
}