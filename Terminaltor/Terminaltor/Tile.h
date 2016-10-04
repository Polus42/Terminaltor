#pragma once

#include <windows.h>

class Tile
{
public:
	Tile();
	Tile( char type, WORD colors );
	~Tile();

	void setAttributes( char type, WORD colors );

	inline char Type() { return m_type; }
	inline WORD Colors() { return m_colors; }

private:
	char m_type;
	WORD m_colors;
};

