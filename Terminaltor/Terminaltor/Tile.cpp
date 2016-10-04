#include "Tile.h"

Tile::Tile() :
m_type(219),
m_colors(0x0F)
{
}

Tile::Tile( char type, WORD colors ) :
m_type(type),
m_colors(colors)
{
}

Tile::~Tile()
{
}

void Tile::setAttributes(char type, WORD colors) {
	m_type = type;
	m_colors = colors;
}