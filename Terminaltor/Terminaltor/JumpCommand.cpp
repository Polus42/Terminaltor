#include "JumpCommand.h"


JumpCommand::JumpCommand(Character* character) :
c(character)
{
}


JumpCommand::~JumpCommand()
{
}

void JumpCommand::execute()
{
	c->Jump();
}