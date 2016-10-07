#include "Menu.h"
#include "GameState.h"

Menu::Menu( int buttonsWidth ) :
m_buttonsWidth( buttonsWidth ),
m_index( 0 )
{
	m_buttons = std::vector<Button*>();
}

Menu::~Menu()
{
}

void Menu::LoadParent()
{
	if ( m_parent )
		GameState::SetMainMenu( m_parent );
}

void Menu::LoadChild( int index )
{
	if ( index < m_children.size() && m_children[index] )
		GameState::SetMainMenu( m_children[index] );
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