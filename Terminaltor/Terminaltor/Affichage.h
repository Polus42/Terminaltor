#pragma once
#include <windows.h>
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
	void draw();
private:
	// Taille de l'écran
	const static int SCREEN_WIDTH = 200;
	const static int SCREEN_HEIGHT = 200;
	// Output (console)
	HANDLE hOutput;

	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion;

	CHAR_INFO buffer[SCREEN_WIDTH][SCREEN_HEIGHT];
};

