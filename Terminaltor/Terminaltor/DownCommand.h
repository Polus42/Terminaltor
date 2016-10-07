#pragma once
#include "Command.h"
#include "Menu.h"

class DownCommand :
	public Command
{
public:
	DownCommand(Menu* menu);
	~DownCommand();
	void execute();
private:
	Menu *m;
};