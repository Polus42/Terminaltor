#pragma once
#include "PhysicsObject.h"

#define BULLET_SPEED

class Bullet :
	public PhysicsObject
{
public:
	Bullet( float x, float y );
	~Bullet();

	void Update(float delta_ms) override;
};

