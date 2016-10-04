#pragma once

#include "Tile.h"

class Sprite
{
public:
	Sprite( int width, int height, Tile *data );
	~Sprite();

	void draw();

	inline int Width() { return m_width; }
	inline int Height() { return m_height; }

private:
	int m_width;
	int m_height;
	Tile *m_data;
};

