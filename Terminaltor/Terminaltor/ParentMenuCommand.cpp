#include "ParentMenuCommand.h"

ParentMenuCommand::ParentMenuCommand( Menu* menu ) : 
m( menu )
{
}

ParentMenuCommand::~ParentMenuCommand()
{
}

void ParentMenuCommand::execute()
{
	m->LoadParent();
}