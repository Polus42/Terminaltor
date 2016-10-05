#include <iostream>
#include <windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "Affichage.h"
#include "NYTimer.h"
#include "Terrain.h"

int main(int argc, char *argv[])
{
	Affichage *aff = new Affichage(200,200);
	NYTimer *t = new NYTimer();
	t->start();
	int previous = 0;
	int current = t->getElapsedMs();
	int buffer = 0;
	
	//Creation terrrain
	Terrain::CreateInstance(200, 200);


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
		if (buffer > 1000)
		{
			buffer -= 1000;
			aff->draw(Terrain::GetInstance());
			//std::cout << "update" << std::endl;
		}
		//system("pause");
		/////////////////////////////////////////
		current = t->getElapsedMs();
		buffer += current - previous;
	}
	return 0;
}