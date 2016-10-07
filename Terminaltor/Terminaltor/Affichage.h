#pragma once
#include "Terrain.h"
#include "Menu.h"
#include <windows.h>
#include <map>
#include <string>

class Affichage
{
public:
	Affichage();
	~Affichage();
	/*Prends un buffer en param
	Un buffer est une structure :

	typedef struct _CHAR_INFO {
	union {
	WCHAR UnicodeChar;
	CHAR  AsciiChar;
	} Char;
	WORD  Attributes;
	} CHAR_INFO, *PCHAR_INFO;

	*/
	void draw();
	void drawMenu(Menu& m);
	void drawHud(Terrain& t);
	void drawCharacter(Character* c);
	void drawText( int y, int x, const std::string& str, WORD attributes );
	void drawBackground();
private:
	// Taille de l'écran
	const static int SCREEN_WIDTH = 80;
	const static int SCREEN_HEIGHT = 25;
	// Output (console)
	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	std::map<const int, CHAR_INFO> tileMap;

	void LoadBackground(const char* path);

	char background[SCREEN_HEIGHT][SCREEN_WIDTH];

};

