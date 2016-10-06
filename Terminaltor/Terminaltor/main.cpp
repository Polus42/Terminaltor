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
#include "GameState.h"

#define RIGHT_KEY 0x0001

int main(int argc, char *argv[])
{
	Affichage *aff = new Affichage(80, 25);
	NYTimer *t = new NYTimer();
	t->start();
	int previous = 0;
	int current = t->getElapsedMs();
	int buffer = 0;
	int delay = 33;
	int keysMask = 0;
	
	//Creation terrrain
	Terrain::ResizeInstance(80, 25);
	//Creation gamestate
	GameState *gs = new GameState();
	//Creation character
	Character *c = new Character(0, 0, 50, 180, 100);
	//Creation input handler
	InputHandler *input = new InputHandler(Terrain::GetInstance(),*c);
	// Assigning each key a command
	input->setEscape(new QuitCommand(gs));
	input->setKeyRight(new GoRightCommand(c, &Terrain::GetInstance()));

	// Boucle affichage
	while (gs->State())
	{
		previous = current;

		if (buffer > delay)
		{
			buffer = buffer % delay;
			/////////////////////////////////////////
			// Update physics and input here
			/////////////////////////////////////////
			input->handleInput();
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