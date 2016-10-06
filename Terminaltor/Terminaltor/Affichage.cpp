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
	//Tile to draw
	CHAR_INFO *tile= new CHAR_INFO();
	///////////////////////////////////////////////////////////////////////////
	// Defining tile properties
	///////////////////////////////////////////////////////////////////////////
	// Ground
	tile->Attributes = FOREGROUND_BLUE;
	tile->Char.UnicodeChar = 0xdb;
	tileMap.insert(std::pair<const int, CHAR_INFO>(0,*tile));
	// Air
	tile->Char.UnicodeChar = 0x20;
	tileMap.insert(std::pair<const int, CHAR_INFO>(1, *tile));
	///////////////////////////////////////////////////////////////////////////
	delete tile;
}


Affichage::~Affichage()
{
}

void Affichage::draw( Terrain& t )
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
			//buffer[t.Height()-y-1][x].Char.UnicodeChar = t.GetTile(x * 100 + t.Distance(), y * 100) ? 0x20 : 0xdb;
			buffer[t.Height() - y - 1][x] = tileMap.at(t.GetTile(x * 100 + t.Distance(), y * 100));
		}
	}

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}
