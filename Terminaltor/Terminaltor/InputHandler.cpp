#include "InputHandler.h"
#include "windows.h"
#include "Command.h"

InputHandler::InputHandler(Terrain& t,Character& c)
{
}


InputHandler::~InputHandler()
{
}

void InputHandler::handleInput()
{
	if (GetAsyncKeyState(VK_ESCAPE) && key_escape)
	{
		key_escape->execute();
	}
	if (GetAsyncKeyState(VK_SPACE) && key_space)
	{
		key_space->execute();
	}
	if (GetAsyncKeyState(VK_UP) && key_up)
	{
		key_up->execute();
	}
	if (GetAsyncKeyState(VK_DOWN) && key_down)
	{
		key_down->execute();
	}

	if (GetAsyncKeyState(VK_RIGHT) && key_right)
	{
		key_right->execute();
	}
	else if (GetAsyncKeyState(VK_LEFT) && key_left)
	{
		key_left->execute();
	}
	else {

	}
}
void InputHandler::setEscape(Command* c)
{
	key_escape = c;
}
void InputHandler::setKeyDown(Command* c)
{
	key_down = c;
}
void InputHandler::setKeyLeft(Command* c)
{
	key_left = c;
}
void InputHandler::setKeyRight(Command* c)
{
	key_right = c;
}
void InputHandler::setKeySpace(Command* c)
{
	key_space = c;
}
void InputHandler::setKeyUp(Command* c)
{
	key_up = c;
}