#include "DownCommand.h"

DownCommand::DownCommand(Menu* menu) :
m(menu)
{
}

DownCommand::~DownCommand()
{
}

void DownCommand::execute()
{
	m->Down();
}