#include "Terrain.h"

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
m_slideOffset( 0 )
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
	if ( s_instance.Width() == 0 || s_instance.Height() == 0 )
		s_instance = Terrain(width, height);
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

}