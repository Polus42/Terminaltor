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
#include "GoRightCommand.h"
#include "GoLeftCommand.h"
#include "GameState.h"

int main(int argc, char *argv[])
{
	Affichage *aff = new Affichage();
	NYTimer *t = new NYTimer();
	t->start();
	int previous = 0;
	int current = t->getElapsedMs();
	int buffer = 0;
	int delay = 33;
	int keysMask = 0;
	
	//Creation terrrain
	Terrain::ResizeInstance(80, 25);
	//Initialisation gamestate
	GameState::SetState(STATE_PLAYING);
	//Creation character
	Character *c = new Character(0, 0, 50, 180, 100);
	//Creation input handler
	InputHandler *input = new InputHandler(Terrain::GetInstance(),*c);
	// Assigning each key a command
	input->setEscape(new QuitCommand());
	input->setKeyRight(new GoRightCommand(c, &Terrain::GetInstance()));
	input->setKeyLeft(new GoLeftCommand(c, &Terrain::GetInstance()));

	// Boucle affichage
	while (GameState::State())
	{
		previous = current;

		if (buffer > delay)
		{
			buffer = buffer % delay;
			/////////////////////////////////////////
			// Update physics and input here
			/////////////////////////////////////////
			input->handleInput();
			switch (GameState::State())
			{
			case STATE_PLAYING:
				Terrain::GetInstance().Update(buffer);
				break;
			case STATE_MENU:
				
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
		aff->draw(Terrain::GetInstance());
		/////////////////////////////////////////
		current = t->getElapsedMs();
		buffer += current - previous;
	}
	return 0;
}