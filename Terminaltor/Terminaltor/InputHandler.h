#pragma once
#include "Terrain.h"
#include "Character.h"
#include "Command.h"
class InputHandler
{
public:
	InputHandler(Terrain& t, Character& c);
	~InputHandler();
	void handleInput();
	void setKeyUp(Command* c);
	void setEscape(Command* c);
	void setKeySpace(Command* c);
	void setKeyRight(Command* c);
	void setKeyLeft(Command* c);
	void setKeyDown(Command* c);
private:
	// List of command, assign each key a command
	Command* key_up;
	Command* key_down;
	Command* key_left;
	Command* key_right;
	Command* key_escape;
	Command* key_space;

};

