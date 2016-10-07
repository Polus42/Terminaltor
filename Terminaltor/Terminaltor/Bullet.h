#pragma once
#include "PhysicsObject.h"

#define BULLET_SPEED 300.0f

class Bullet :
	public PhysicsObject
{
public:
	Bullet( float x, float y );
	~Bullet();

	void Update(float delta_ms) override;
};

