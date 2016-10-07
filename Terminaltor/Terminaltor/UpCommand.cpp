#include "UpCommand.h"

UpCommand::UpCommand(Menu* menu) :
m(menu)
{
}

UpCommand::~UpCommand()
{
}

void UpCommand::execute()
{
	m->Up();
}