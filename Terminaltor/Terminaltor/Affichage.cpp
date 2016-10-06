#include "Affichage.h"
#include "iostream"
#include "Terrain.h"
#include <string>

Affichage::Affichage()
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
	// Borders
	tile->Attributes = BACKGROUND_GREEN;
	tile->Char.UnicodeChar = 0x20;
	tileMap.insert(std::pair<const int, CHAR_INFO>(2, *tile));
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
	// Drawing paralax
	int offset = 10;

	int tile = -1;
	for (int x = 0; x < t.Width(); x++)
	{
		for (int y = 0; y < t.Height(); y++)
		{
			if (x == 0 || y == 0 || y==t.Height()-1|| x==t.Width()-1)
			{
				buffer[t.Height() - y - 1][x] = tileMap.at(2);
			}
			else
			{
				buffer[t.Height() - y - 1][x] = tileMap.at(t.GetTile(x * 100 + t.Distance(), y * 100));
			}
		}
	}
	
	drawHud(t);
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

void Affichage::drawHud(Terrain& t)
{
	int dist = t.Distance()/100;
	std::string str = std::to_string(dist)+" METERS";
	for (int i = 0; i < str.length(); i++)
	{
		buffer[1][i+1].Char.UnicodeChar = str[i];
		buffer[1][i+1].Attributes = 0x0005 | BACKGROUND_BLUE;
	}

	int life = t.GetCharacter().GetHealth();
	str = "LIFE : " + std::to_string(life);
	for (int i = 0; i < str.length(); i++)
	{
		buffer[1][t.Width()+i-str.length()-1].Char.UnicodeChar = str[i];
		buffer[1][t.Width() + i-str.length()-1].Attributes = 0x0005 | BACKGROUND_BLUE;
	}
}