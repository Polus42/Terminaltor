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
#include "ParentMenuCommand.h"
#include "SubMenuCommand.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "GoRightCommand.h"
#include "GoLeftCommand.h"
#include "ShootCommand.h"
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
	float buffer = 0;
	GameState::SetDelay(0.1f);
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
	player_input->setKeyCtrl(new ShootCommand(c));

	// Creating menu and buttons
	Menu* menu = new Menu(20);
	*menu << new Button(new PlayCommand(), "Play") << new Button(new SubMenuCommand(menu, 0), "Credits") << new Button(new QuitCommand(), "Quit");
	GameState::SetMainMenu(menu);
	//menu->setEscape(new QuitCommand());
	menu->setKeyEnter(new EnterCommand(menu));
	menu->setKeyUp(new UpCommand(menu));
	menu->setKeyDown(new DownCommand(menu));

	// Creating credits
	Menu* credits = new Menu(20);
	*credits << new Button(new QuitCommand(), "Coucou");
	*credits << new Button(new QuitCommand(), "Bisou");
	credits->setEscape(new ParentMenuCommand(credits));
	credits->setKeyEnter(new EnterCommand(credits));
	credits->setKeyUp(new UpCommand(credits));
	credits->setKeyDown(new DownCommand(credits));
	credits->SetParent(menu);

	*menu << credits;

	// Boucle affichage
	aff->draw();
	while (GameState::State())
	{
		if (buffer > GameState::Delay())
		{
			//GameState::SetFps(1.0f / buffer);
			GameState::SetFps(buffer*1000000.f);//t->getElapsedSeconds()*1000000.0f
			/////////////////////////////////////////
			// Update physics and input here
			/////////////////////////////////////////
			switch (GameState::State())
			{
			case STATE_PLAYING:
				player_input->handleInput();
				Terrain::GetInstance().Update(buffer*1000.0f);
				break;
			case STATE_MENU:
				GameState::MainMenu()->handleInput();
				break;
			case STATE_PLAYER_DEAD:

				break;
			default:
				break;
			}
			buffer -= GameState::Delay();
			aff->draw();
		}
		/////////////////////////////////////////
		// Update drawing here
		/////////////////////////////////////////
		//aff->draw();
		/////////////////////////////////////////
		buffer += t->getElapsedSeconds(true);
	}
	return 0;
}