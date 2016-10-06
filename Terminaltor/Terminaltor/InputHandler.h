#pragma once
#include "Command.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	void handleInput();
	void setEscape(Command* c);
	void setKeyEnter(Command* c);
	void setKeySpace(Command* c);
	void setKeyUp(Command* c);
	void setKeyLeft(Command* c);
	void setKeyDown(Command* c);
	void setKeyRight(Command* c);
private:
	// List of command, assign each key a command
	Command* key_escape;
	Command* key_enter;
	Command* key_space;
	Command* key_up;
	Command* key_left;
	Command* key_down;
	Command* key_right;

};

