#include "Affichage.h"
#include "iostream"
#include "Terrain.h"


Affichage::Affichage(int width , int height)
{
	//SCREEN_WIDTH = width;
	//SCREEN_HEIGHT = height;
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH , SCREEN_HEIGHT };

}


Affichage::~Affichage()
{
}

void Affichage::draw(Terrain& t )
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
	// Change buffer here

	int tile = -1;
	for (int x = 0; x < t.Width(); x++)
	{
		for (int y = 0; y < t.Height(); y++)
		{
			//buffer[x][y] = mymap.at(t.GetTile(x, y));
			buffer[x][y].Char.AsciiChar = t.GetTile(x, y)?'█':' ';
		}
	}

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}
