#pragma once

#define MIN_HEIGHT 5
#define MAX_HEIGHT 15

class Terrain
{
private:
	Terrain();
	Terrain( int width, int height );
	~Terrain();

public:
	static void ResizeInstance( int width, int height );
	static Terrain& GetInstance();

	void Slide( const int distance );

	inline int Width() { return m_width; }
	inline int Height() { return m_height; }
	inline int Distance() { return m_distance; }

	int GetTile( const int x, const int y );//function must be called with a positive value inferior to terrain width

protected:
	static Terrain s_instance;

	void FreeTiles();
	void Generate( const int offset );

	int m_width;
	int m_height;
	int** m_tiles;
	int m_columnOffset;

	int m_distance;

	int m_lastGroundHeight;
};