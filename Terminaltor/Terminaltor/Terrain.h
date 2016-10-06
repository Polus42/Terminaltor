#pragma once
#include "Character.h"
#include <list>

#define MIN_HEIGHT 2
#define MAX_HEIGHT 4

class Terrain :
	public GameObject
{
private:
	Terrain();
	Terrain( int width, int height );
	~Terrain();

public:
	static void ResizeInstance( int width, int height );
	static Terrain& GetInstance();

	void Update(long delta_ms) override;

	void Slide( const int distance );
	inline int Distance() { return m_distance; }
	inline void SetCharacter(Character& character) { m_character = character; }
	inline Character& GetCharacter() { return m_character; }
	inline void AddEnnemy(Character& character) { m_ennemies.push_back(character); }
	inline std::list<Character>& GetEnnemies() { return m_ennemies; }

	int GetTile( const int x, const int y );//function must be called with a positive value inferior to terrain width

protected:
	static Terrain s_instance;

	void FreeTiles();
	void Generate( const int offset );

	int** m_tiles;
	int m_columnOffset;
	int m_distance;
	int m_lastGroundHeight;

	Character m_character;
	std::list<Character> m_ennemies;
};