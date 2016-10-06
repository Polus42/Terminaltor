#pragma once

#define STATE_MENU 2
#define STATE_PLAYING 1
#define STATE_EXIT 0

class GameState
{
public:
	GameState();
	~GameState();

	inline int State() { return m_state; }
	inline void SetState(int state) { m_state = state; }

private:
	int m_state;
};

