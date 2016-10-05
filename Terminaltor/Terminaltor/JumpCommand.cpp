#include "JumpCommand.h"


JumpCommand::JumpCommand()
{
}


JumpCommand::~JumpCommand()
{
}

void JumpCommand::execute()
{
	c->Jump();
}