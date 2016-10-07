#include <iostream>
#include <windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "Affichage.h"
#include "NYTimer.h"
#include "Terrain.h"
#include "InputHandler.h"
#include "QuitCommand.h"
#include "EnterCommand.h"
#include "MenuCommand.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "GoRightCommand.h"
#include "GoLeftCommand.h"
#include "JumpCommand.h"
#include "PlayCommand.h"
#include "GameState.h"
#include "Menu.h"
#include "Button.h"

int main(int argc, char *argv[])
{
	Affichage *aff = new Affichage();
	NYTimer *t = new NYTimer();
	t->start();
	int previous = 0;
	int current = t->getElapsedMs();
	int buffer = 0;
	GameState::SetDelay(100);
	int keysMask = 0;
	
	//Creation terrrain
	Terrain::ResizeInstance(80, 25);
	//Initialisation gamestate
	GameState::SetState(STATE_MENU);
	//Creation character
	Character *c = new Character(100, MAX_HEIGHT*100, 50, 180, 100);
	Terrain::GetInstance().SetCharacter(c);
	//Creation player input handler
	InputHandler *player_input = new InputHandler();
	player_input->setEscape(new MenuCommand());
	player_input->setKeyRight(new GoRightCommand(c));
	player_input->setKeySpace(new JumpCommand(c));
	player_input->setKeyLeft(new GoLeftCommand(c));

	// Creating menu and buttons
	Menu* menu = new Menu(20);
	*menu << new Button(new PlayCommand(), "Play");
	*menu << new Button(new PlayCommand(), "Credits");
	*menu << new Button(new QuitCommand(), "Quit");
	GameState::SetMainMenu(menu);
	//Creation menu input handler
	//menu->setEscape(new QuitCommand());
	menu->setKeyEnter(new EnterCommand(menu));
	menu->setKeyUp(new UpCommand(menu));
	menu->setKeyDown(new DownCommand(menu));

	// Boucle affichage
	while (GameState::State())
	{
		previous = current;

		if (buffer > GameState::Delay())
		{

			GameState::SetFps(1000/buffer);

			buffer = buffer % GameState::Delay();
			/////////////////////////////////////////
			// Update physics and input here
			/////////////////////////////////////////
			switch (GameState::State())
			{
			case STATE_PLAYING:
				player_input->handleInput();
				Terrain::GetInstance().Update(buffer);
				break;
			case STATE_MENU:
				menu->handleInput();
				break;
			case STATE_PLAYER_DEAD:

				break;
			default:
				break;
			}
		}
		/////////////////////////////////////////
		// Update drawing here
		/////////////////////////////////////////
		aff->draw();
		/////////////////////////////////////////
		current = t->getElapsedMs();
		buffer += current - previous;
	}
	return 0;
}