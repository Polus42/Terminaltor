#pragma once
#include <vector>
#include "Button.h"
#include "InputHandler.h"


class Menu : public InputHandler
{
public:
	Menu( int buttonsWidth );
	~Menu();

	void Up();
	void Down();
	void Enter() { m_buttons[m_index]->Push(); };
	inline std::vector<Button*>& Buttons() { return m_buttons; };
	inline std::vector<Menu*>& Children() { return m_children; };
	void LoadParent();
	void LoadChild( int index );
	inline int Index() { return m_index; };
	inline int ButtonsWidth() { return m_buttonsWidth; };
	inline void SetParent( Menu* parent ) { m_parent = parent; };

	inline Menu& operator<<( Button* button ) { m_buttons.push_back( button ); return *this; };
	inline Menu& operator<<( Menu* menu ) { m_children.push_back( menu ); return *this; };

private:
	std::vector<Button*> m_buttons;
	std::vector<Menu*> m_children;
	Menu* m_parent;
	int m_index;
	int m_buttonsWidth;
};

