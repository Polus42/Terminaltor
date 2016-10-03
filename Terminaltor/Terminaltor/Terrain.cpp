#include "Terrain.h"

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
		free( column );
	}
	free( m_tiles );
}

void Terrain::Slide( const int distance) {
	m_slideOffset += distance;
	if ( m_slideOffset > m_width )
		m_slideOffset -= m_width;
	Generate(distance);
}

int* Terrain::GetColumn( const int index) {
	int column_index = index + m_slideOffset;
	if ( column_index > m_width )
		column_index -= m_width;
	return m_tiles[column_index];
}

void Terrain::Generate(const int distance) {

}