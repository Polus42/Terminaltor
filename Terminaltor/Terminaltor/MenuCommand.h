#pragma once
#include "Command.h"

class MenuCommand :
	public Command
{
public:
	MenuCommand();
	~MenuCommand();
	void execute();
};

