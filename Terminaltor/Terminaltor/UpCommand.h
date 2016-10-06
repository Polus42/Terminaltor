#pragma once
#include "Command.h"
#include "Menu.h"

class UpCommand :
	public Command
{
public:
	UpCommand(Menu* menu);
	~UpCommand();
	void execute();
private:
	Menu *m;
};

