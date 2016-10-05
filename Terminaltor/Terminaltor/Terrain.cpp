#include "Terrain.h"
#include <stdlib.h>
#include <time.h>

Terrain Terrain::s_instance;

Terrain::Terrain() :
m_width( 0 ),
m_height( 0 ),
m_slideOffset( 0 )
{
}

Terrain::Terrain( const int width, const int height ) :
m_width( width ),
m_height( height ),
m_slideOffset( 0 ),
m_lastGroundHeight( ( MIN_HEIGHT + MAX_HEIGHT) / 2 )
{
	m_tiles = new int*[width];
	for (int w = 0; w < width; w++){
		int* column = new int[height];
		m_tiles[w] = column;
	}
	Generate( width );
}

Terrain::~Terrain()
{
	for (int w = 0; w < m_width; w++){
		int* column = m_tiles[w];
		delete[] column;
	}
	delete[] m_tiles;
}

void Terrain::CreateInstance(int width, int height) {
	if ( s_instance.Width() == 0 || s_instance.Height() == 0 ) {
		srand(time(NULL));
		s_instance = Terrain(width, height);
	}
}

Terrain& Terrain::GetInstance() {
	return s_instance;
}

void Terrain::Slide( const int distance) {
	m_slideOffset += distance;
	if ( m_slideOffset > m_width )
		m_slideOffset -= m_width;
	m_distance += distance * 100;
	Generate( distance );
}

int Terrain::GetTile(const int x, const int y) {
	int tmp = ( x - m_distance ) / 100;
	int column_index = x + m_slideOffset;
	if ( column_index > m_width )
		column_index -= m_width;
	return m_tiles[y / 100][column_index];
}

void Terrain::Generate( const int distance ) {
	for ( int i = m_width - distance - m_slideOffset; i < m_width; i++ ) {
		m_lastGroundHeight += rand()%3 - 1;
		if ( m_lastGroundHeight > MAX_HEIGHT )
			m_lastGroundHeight = MAX_HEIGHT;
		if ( m_lastGroundHeight < MIN_HEIGHT )
			m_lastGroundHeight = MIN_HEIGHT;
		for ( int j = 0; j < m_height; j++ ) {
			m_tiles[i][j] = j < m_lastGroundHeight ? 1 : 0;
		}
	}
}