#include <iostream>
#include <windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "Affichage.h"
#include "NYTimer.h"

int main(int argc, char *argv[])
{
	NYTimer *t = new NYTimer();
	t->start();
	int previous = 0;
	int current = 0;
	int buffer = 0;
	// Boucle affichage
	while (true)
	{
		current = t->getElapsedMs();
		/////////////////////////////////////////
		// Gauche droite saut
		// GetAsyncKeyState -> Windows api
		/////////////////////////////////////////
		// Update goes here
		/////////////////////////////////////////
		if (buffer > 1000)
		{
			buffer -= 1000;

		}
		system("pause");
		/////////////////////////////////////////

		previous = t->getElapsedMs();
		std::cout << previous-current << std::endl;
		buffer += previous - current;
	}
	return 0;
}