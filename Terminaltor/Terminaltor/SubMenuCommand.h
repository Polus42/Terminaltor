#pragma once
#include "Command.h"
#include "Menu.h"

class SubMenuCommand :
	public Command
{
public:
	SubMenuCommand( Menu* menu, int index );
	~SubMenuCommand();
	virtual void execute();

private:
	Menu* m;
	int m_index;
};

