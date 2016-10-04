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
	int i = 0;
	int elapsed = t->getElapsedMs();
	// Boucle affichage
	while (i<1000)
	{
		elapsed = t->getElapsedMs() - elapsed;
		std::cout << elapsed << std::endl;
		i++;
	}
	/*Affichage *a = new Affichage(100,100);
	int i = 0;
	while(i<1000)
	{
		a->draw();
		i++;
	}*/
	system("pause");
	return 0;
}