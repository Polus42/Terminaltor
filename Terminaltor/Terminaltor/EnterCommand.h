#pragma once
#include "Command.h"
#include "Menu.h"

class EnterCommand :
	public Command
{
public:
	EnterCommand(Menu* menu);
	~EnterCommand();
	void execute();
private:
	Menu *m;
};

