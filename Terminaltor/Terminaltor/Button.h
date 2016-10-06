#pragma once
#include "Command.h"
#include <string>

class Button
{
public:
	Button(Command* c, const std::string& text);
	~Button();

	void Push() { m_command->execute(); };
	inline std::string& Text() { return m_text; };

private:
	Command* m_command;
	std::string m_text;
};

