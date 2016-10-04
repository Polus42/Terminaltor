#include "Affichage.h"
#include "iostream"

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

void Affichage::draw()
{
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
	unsigned short r = 0x0860;
	buffer[5][100].Char.UnicodeChar = r;
	buffer[5][100].Attributes = BACKGROUND_GREEN;
	buffer[5][101].Char.UnicodeChar = r;
	buffer[5][101].Attributes = 0x0B;
	buffer[5][102].Char.UnicodeChar = r;
	buffer[5][102].Attributes = 0x0A;

	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}
