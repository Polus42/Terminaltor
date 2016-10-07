#pragma once
#include "Command.h"
#include "Menu.h"

class ParentMenuCommand :
	public Command
{
public:
	ParentMenuCommand( Menu* menu );
	~ParentMenuCommand();
	virtual void execute();

private:
	Menu* m;
};

