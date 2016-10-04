#pragma once
#include "GameObject.h"

#define JUMP_SPEED 200

class Character :
	public GameObject
{
public:
	Character( int x, int y, int width, int height, int health );
	~Character();

	virtual void Update( long delta_ms ) override;

	void Jump();

protected:
	int m_health;
	int m_xSpeed;
	int m_ySpeed;
};

