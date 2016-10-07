#pragma once
#include "Character.h"
#include <list>

#define MIN_HEIGHT 3
#define MAX_HEIGHT 13

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

	void Update( float delta_ms ) override;

	void Slide( const float distance );
	inline float Distance() { return m_distance; }
	inline void SetCharacter(Character* character) { m_character = character; }
	inline Character* GetCharacter() { return m_character; }
	inline void AddEnnemy(PhysicsObject* object) { m_objects.push_back(object); }
	inline std::list<PhysicsObject*>& GetObjects() { return m_objects; }

	int GetTile( const int x, const int y );//function must be called with a positive value inferior to terrain width

	inline Terrain& operator<<(PhysicsObject* object) { m_objects.push_back(object); return *this; };

protected:
	static Terrain s_instance;

	void FreeTiles();
	void Generate( const int offset );

	int** m_tiles;
	float m_columnOffset;
	float m_distance;
	int m_lastGroundHeight;

	Character* m_character;
	std::list<PhysicsObject*> m_objects;
};