#pragma once
#include <vector>

enum tile_t {
	Air,
	Ground
};

class Terrain
{
public:
	static void CreateInstance( int width, int height );
	inline static Terrain& GetInstance() { return s_instance; };

	void Slide( const int distance );
	void Generate( const int distance );

	inline int Width() { return m_width; }
	inline int Height() { return m_height; }
	inline int Distance() { return m_distance; }

	int GetTile( const int x, const int y );//function must be called with a positive value inferior to terrain width

private:
	Terrain( int width, int height );
	~Terrain();

	static Terrain s_instance;

	int m_width;
	int m_height;
	int** m_tiles;
	int m_slideOffset;

	int m_distance;

	int m_lastGroundHeight;
};