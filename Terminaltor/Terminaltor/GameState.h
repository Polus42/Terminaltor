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
	static inline int Fps() { return m_fps; }
	static inline void SetFps(int fps) { m_fps = fps; }
	static inline Menu* MainMenu() { return m_mainMenu; }
	static inline void SetMainMenu(Menu* menu) { m_mainMenu = menu; }

private:
	GameState();
	~GameState();

	static int m_state;
	static int m_fps;
	static Menu* m_mainMenu;
};

