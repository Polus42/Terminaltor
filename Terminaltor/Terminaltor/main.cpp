#include <iostream>
#include <windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "Affichage.h"
#include "NYTimer.h"
#include "Terrain.h"

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


	// Boucle affichage
	while (true)
	{
		previous = current;
		/////////////////////////////////////////
		// Gauche droite saut
		// GetAsyncKeyState -> Windows api
		/////////////////////////////////////////
		// Update goes here
		/////////////////////////////////////////
		if (buffer > delay)
		{
			buffer = buffer % delay;
			aff->draw(Terrain::GetInstance());
			if (keysMask & RIGHT_KEY) {
				Terrain::GetInstance().Slide(1);
				keysMask &= ~RIGHT_KEY;
			}
			//std::cout << "update" << std::endl;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		if (GetAsyncKeyState(VK_RIGHT))
			keysMask |= RIGHT_KEY;
		//system("pause");
		/////////////////////////////////////////
		current = t->getElapsedMs();
		buffer += current - previous;
	}
	return 0;
}