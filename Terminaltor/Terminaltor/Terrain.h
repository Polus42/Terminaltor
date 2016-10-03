#pragma once
#include <vector>

enum tile_t {
	Air,
	Ground
};

class Terrain
{
public:
	Terrain( int width, int height );
	~Terrain();

	void Slide( const int distance );
	void Generate( const int distance );

	inline int Width() { return m_width; }
	inline int Height() { return m_height; }
	inline int Distance() { return m_distance; }

	int* GetColumn( const int index );//function must be called with a positive value inferior to terrain width

private:
	int m_width;
	int m_height;
	int** m_tiles;
	int m_slideOffset;

	int m_distance;

	int m_lastHeight;
};