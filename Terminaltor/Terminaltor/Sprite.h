#pragma once

#include "Tile.h"

class Sprite
{
public:
	Sprite();
	Sprite(int width, int height, Tile *data);
	~Sprite();

	void draw();

	inline int Width() { return m_width; }
	inline int Height() { return m_height; }
	inline Tile* Data() { return m_data; }

	static void LoadSprite(const char* path, Sprite& dest);

private:

	int m_width;
	int m_height;
	Tile *m_data;
};

