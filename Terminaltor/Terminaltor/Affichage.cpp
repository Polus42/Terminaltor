﻿#include "Affichage.h"
#include "iostream"
#include "Terrain.h"
#include "GameState.h"
#include <string>
#include <fstream>

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
	// Air
	tile->Attributes = FOREGROUND_BLUE;
	tile->Char.UnicodeChar = 0xdb;
	tileMap.insert(std::pair<const int, CHAR_INFO>(0, *tile));
	tile->Attributes = 0;
	// Ground
	tile->Char.UnicodeChar = 0x20;
	tileMap.insert(std::pair<const int, CHAR_INFO>(1, *tile));
	// Borders
	tile->Attributes = BACKGROUND_GREEN;
	tile->Char.UnicodeChar = 0x20;
	tileMap.insert(std::pair<const int, CHAR_INFO>(2, *tile));
	// Character
	tile->Attributes = BACKGROUND_RED;
	tile->Char.UnicodeChar = 0x20;
	tileMap.insert(std::pair<const int, CHAR_INFO>(3, *tile));
	// Background
	tile->Attributes = 0;
	tile->Char.UnicodeChar = 178;
	tileMap.insert(std::pair<const int, CHAR_INFO>(4, *tile));
	///////////////////////////////////////////////////////////////////////////
	// Loading background
	LoadBackground("Sprites/background.txt");
	delete tile;
}


Affichage::~Affichage()
{
}

void Affichage::draw()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);

	if (GameState::State() == STATE_MENU) {
		drawMenu(*GameState::MainMenu());
		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);
		return;
	}

	Terrain& t = Terrain::GetInstance();
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
	drawCharacter(t.GetCharacter());
	drawBackground();
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize, 
		dwBufferCoord, &rcRegion);
}

void Affichage::drawHud(Terrain& t)
{
	int dist = t.Distance()/100;
	std::string str = std::to_string(dist) + " METERS";
	drawText(1, 1, str, 0x0005 | BACKGROUND_BLUE);

	int life = t.GetCharacter()->GetHealth();
	str = "LIFE : " + std::to_string(life);
	drawText(1, t.Width() - str.length() - 1, str, 0x0005 | BACKGROUND_BLUE);

	int x = t.GetCharacter()->X();
	str = "CX : " + std::to_string(x);
	drawText(2, t.Width() - str.length() - 1, str, 0x0005 | BACKGROUND_BLUE);
	//*
	int fps = GameState::Fps();
	str = "fps : " + std::to_string(fps);
	drawText(3, t.Width() - str.length() - 1, str, 0x0005 | BACKGROUND_BLUE);
}

void Affichage::drawText( int y, int x, const std::string& str, WORD attributes )
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		buffer[y][i + x].Char.UnicodeChar = str[i];
		buffer[y][i + x].Attributes = attributes;
	}//*/
}

void Affichage::drawMenu(Menu& m)
{
	CHAR_INFO *tile = new CHAR_INFO();
	tile->Attributes = 0x00;
	tile->Char.UnicodeChar = 0x20;
	for (int x = 0; x < SCREEN_WIDTH; ++x)
		for (int y = 0; y < SCREEN_HEIGHT; ++y)
			buffer[y][x] = *tile;

	int xOffset = SCREEN_WIDTH / 2 - m.ButtonsWidth() / 2;
	int gap = (SCREEN_HEIGHT / m.Buttons().size() ) / 2 - 1;
	int yOffset = gap;
	int i = 0;
	for (auto button : m.Buttons()) {
		int highlight = m.Index() == i++;
		tile->Attributes = 0x0f;
		tile->Char.UnicodeChar = highlight ? 0xc9 : 0xda;//top left corner
		buffer[yOffset][xOffset] = *tile;
		tile->Char.UnicodeChar = highlight ? 0xbb : 0xbf;//top right corner
		buffer[yOffset][xOffset + m.ButtonsWidth() - 1] = *tile;

		tile->Char.UnicodeChar = highlight ? 0xcd : 0xc4;//top and bottom sides
		for ( int x = 1; x < m.ButtonsWidth() - 1; ++x ) {
			buffer[yOffset  ][xOffset + x] = *tile;
			buffer[yOffset+2][xOffset + x] = *tile;
		}
		tile->Char.UnicodeChar = highlight ? 0xba : 0xb3;//left and right sides
		{
			buffer[++yOffset][xOffset] = *tile;
			buffer[yOffset  ][xOffset + m.ButtonsWidth() - 1] = *tile;
		}

		drawText(yOffset, SCREEN_WIDTH / 2 - button->Text().size() / 2, button->Text(), 0x0f);

		tile->Char.UnicodeChar = highlight ? 0xc8 : 0xc0;//bottom left corner
		buffer[++yOffset][xOffset] = *tile;
		tile->Char.UnicodeChar = highlight ? 0xbc : 0xd9;//bottom right corner
		buffer[yOffset][xOffset + m.ButtonsWidth() - 1] = *tile;

		yOffset += gap * 2;
	}
	delete tile;
}

void Affichage::drawCharacter(Character* c)
{
	/*int tmp = c.X() - Terrain::GetInstance().Distance();
	tmp -= tmp % 100;
	tmp += Terrain::GetInstance().Distance() % 100;
	tmp /= 100;*/
	buffer[Terrain::GetInstance().Height() - 1 - (int)(c->Y() / 100)      ][(int)(c->X() - Terrain::GetInstance().Distance()) / 100] = tileMap.at(3);
	buffer[Terrain::GetInstance().Height() - 1 - (int)(c->Y() + 100) / 100][(int)(c->X() - Terrain::GetInstance().Distance()) / 100] = tileMap.at(3);
}

void Affichage::LoadBackground(const char* path) {
	std::ifstream infile(path);
	std::string line;
	int length = 0;
	while (std::getline(infile, line))
	{
		for (int i = 0; i < line.size(); i++)
		{
			background[length][i] = line.at(i);
		}
		length++;
	}
	
}

void Affichage::drawBackground()
{
	int dist = Terrain::GetInstance().Distance();
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			// If buffer contains air, then make it background
			if (buffer[y][(x - dist / 100/2)%SCREEN_WIDTH].Attributes == FOREGROUND_BLUE && background[y][x] == 'X')
			{
				buffer[y][(x - dist / 100/2)%SCREEN_WIDTH] = tileMap.at(4);
			}
		}
	}
}