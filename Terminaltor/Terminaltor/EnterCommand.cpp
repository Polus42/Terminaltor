#include "EnterCommand.h"

EnterCommand::EnterCommand(Menu* menu) :
m(menu)
{
}

EnterCommand::~EnterCommand()
{
}

void EnterCommand::execute()
{
	m->Enter();
}