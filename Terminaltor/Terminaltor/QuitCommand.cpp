#include "QuitCommand.h"
#include "windows.h"

QuitCommand::QuitCommand()
{
}


QuitCommand::~QuitCommand()
{
}

void QuitCommand::execute()
{
	exit(0);
}