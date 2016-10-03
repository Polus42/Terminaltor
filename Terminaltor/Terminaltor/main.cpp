#include <iostream>
#include <windows.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

int main(int argc, char *argv[])
{

	int i = 0;
	while(i<1000)
	{
		int const SCREEN_WIDTH = 100;
		int const SCREEN_HEIGHT = 100;
		HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

		COORD dwBufferSize = { SCREEN_WIDTH, SCREEN_HEIGHT };
		COORD dwBufferCoord = { 0, 0 };
		SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

		CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

		ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);

		buffer[5][10].Char.AsciiChar = 'H';
		buffer[5][10].Attributes = 0x0E;
		buffer[5][11].Char.AsciiChar = 'i';
		buffer[5][11].Attributes = 0x0B;
		buffer[5][12].Char.AsciiChar = '!';
		buffer[5][12].Attributes = 0x0A;

		for (int i = 0; i < 100;i++)
		{
			for (int y = 0; y < 100; y++)
			{
				int a = rand();
				char r1 = (unsigned char)a;
				buffer[i][y].Char.AsciiChar = r1;
			}
		}

		WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
			dwBufferCoord, &rcRegion);
		i++;
	}
	return 0;
}