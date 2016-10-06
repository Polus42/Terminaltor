#pragma once
#include "Command.h"

class Button
{
public:
	Button(Command* c);
	~Button();

	void Push() { m_command->execute(); };

private:
	Command* m_command;
};

