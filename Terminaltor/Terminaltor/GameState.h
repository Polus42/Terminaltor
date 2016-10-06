#pragma once

#define STATE_PLAYER_DEAD 3
#define STATE_MENU 2
#define STATE_PLAYING 1
#define STATE_EXIT 0

class GameState
{
public:
	static inline int State() { return m_state; }
	static inline void SetState(int state) { m_state = state; }

private:
	GameState();
	~GameState();

	static int m_state;
};

