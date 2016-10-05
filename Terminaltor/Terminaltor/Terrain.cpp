#include "Terrain.h"
#include <stdlib.h>
#include <time.h>

Terrain Terrain::s_instance;

Terrain::Terrain() :
m_width( 0 ),
m_height( 0 ),
m_columnOffset( 0 ),
m_distance( 0 )
{
}

Terrain::~Terrain()
{
	FreeTiles();
}

void Terrain::FreeTiles() {
	for ( int w = 0; w < m_width*2; ++w ) {
		delete[] m_tiles[w];
	}
	delete[] m_tiles;
}

void Terrain::ResizeInstance( int width, int height ) {
	if ( s_instance.Width() == 0 || s_instance.Height() == 0 ) {
		srand(time(NULL));
		s_instance.FreeTiles();
		s_instance.m_width = width;
		s_instance.m_height = height;
		s_instance.m_columnOffset = 0;
		s_instance.m_distance = 0;
		s_instance.m_lastGroundHeight = ((MIN_HEIGHT + MAX_HEIGHT) / 2);
		s_instance.m_tiles = new int*[width*2];
		for ( int w = 0; w < width*2; ++w ){
			s_instance.m_tiles[w] = new int[height];
		}
		s_instance.Generate(width);
	}
}

Terrain& Terrain::GetInstance() {
	return s_instance;
}

void Terrain::Slide( const int distance ) {
	m_columnOffset += distance;
	if ( m_columnOffset > m_width )
		m_columnOffset -= m_width;
	m_distance += distance * 100;
	Generate( distance );
}

int Terrain::GetTile( const int x, const int y ) {
	int column_index = ( ( x - m_distance ) / 100 ) + m_columnOffset;
	return m_tiles[column_index][y / 100];
}

void Terrain::Generate( const int distance ) {
	for ( int i = m_width - distance + m_columnOffset; i < m_width + m_columnOffset; ++i ) {
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