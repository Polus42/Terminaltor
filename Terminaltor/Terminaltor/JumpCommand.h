#pragma once
#include "Command.h"
#include "Character.h"
class JumpCommand : public Command
{
public:
	JumpCommand();
	~JumpCommand();
	virtual void execute();
private:
	Character *c;
};

