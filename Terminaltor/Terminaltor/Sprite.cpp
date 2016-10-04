#include "Sprite.h"
#include <iostream>

Sprite::Sprite( int width, int height, Tile *data ) :
m_width(width),
m_height(height),
m_data(data)
{
}

Sprite::~Sprite()
{
	delete[] m_data;
}

void Sprite::draw() {
	HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	WORD colors = 0x00;
	for (int h = 0; h < m_height; ++h) {
		for (int w = 0; w < m_width; ++w) {
			Tile tile = m_data[h*m_width + w];
			if (tile.Colors() != colors) {
				colors = tile.Colors();
				SetConsoleTextAttribute(hstdout, colors);
			}
			std::cout << tile.Type();
		}
		std::cout << std::endl;
	}
	FlushConsoleInputBuffer(hstdin);

	// Keep users happy
	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}