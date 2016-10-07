#include "Button.h"

Button::Button( Command* c, const std::string& text ) :
m_command( c ),
m_text( text )
{
}

Button::~Button()
{
	delete m_command;
}