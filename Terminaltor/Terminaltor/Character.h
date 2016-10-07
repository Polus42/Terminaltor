#pragma once
#include "PhysicsObject.h"

#define JUMP_SPEED 750.0f
#define WALK_SPEED 150.0f
#define GRAVITY    491.0f

class Character :
	public PhysicsObject
{
public:
	Character();
	Character( float x, float y, int width, int height, int health );
	~Character();

	void Update( float delta_ms ) override;

	void Move( int direction );
	void Shoot();
	void Jump();
	
	int GetHealth();

	inline bool IsOnFloor() { return m_onFLoor; };

protected:
	bool m_onFLoor;

	int m_health;
};

