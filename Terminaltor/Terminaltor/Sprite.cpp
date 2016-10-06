#include "Sprite.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

Sprite::Sprite() :
m_width(0),
m_height(0),
m_data(nullptr)
{
}

Sprite::Sprite(int width, int height, Tile *data) :
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

void Sprite::LoadSprite(const char* path, Sprite& dest) {
	std::ifstream is(path, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char * buffer = new char[length];

		std::cout << "Reading " << length << " characters... " << std::endl;
		// read data as a block:
		is.read(buffer, length);

		if (is)
			std::cout << "all characters read successfully." << std::endl;
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		is.close();

		char width = buffer[0];
		char height = buffer[1];

		Tile *data = new Tile[width*height];

		for (int i = 0; i < width*height; ++i) {
			int t = i * 2 + 2;
			int colors = buffer[t];
			data[i].setAttributes(buffer[t + 1], colors);
		}
		delete dest.m_data;

		dest.m_width = width;
		dest.m_height = height;
		dest.m_data = data;

		delete[] buffer;
	}
}