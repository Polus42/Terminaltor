#include "ShootCommand.h"

ShootCommand::ShootCommand(Character *c)
{
	character = c;
}

ShootCommand::~ShootCommand()
{
}

void ShootCommand::execute()
{
	//*
	character->Shoot();/*/
					   terrain->Slide(100);//*/
}