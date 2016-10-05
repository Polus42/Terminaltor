#pragma once
#include "Terrain.h"
#include <windows.h>
#include <map>

typedef struct cezcv {

} lenomdemastruct;

class Affichage
{
public:
	Affichage(int width, int height);
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
	void draw(Terrain& t);
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

	//std::map<const int, CHAR_INFO> mymap = {
	//	{ 0, CHAR_INFO((0x0860), (0x0B)) },
	//	{ 1, buffer[0][0] },
	//	{ 2, buffer[0][0] } };

};

