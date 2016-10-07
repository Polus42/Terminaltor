#include "Menu.h"

Menu::Menu( int buttonsWidth ) :
m_buttonsWidth( buttonsWidth ),
m_index( 0 )
{
	m_buttons = std::vector<Button*>();
}

Menu::~Menu()
{
}

void Menu::Down()
{
	if ( ++m_index >= m_buttons.size() )
		m_index = 0;
}

void Menu::Up()
{
	if ( --m_index < 0 )
		m_index = m_buttons.size() - 1;
}