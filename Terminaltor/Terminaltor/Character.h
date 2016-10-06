#pragma once
#include "GameObject.h"

#define JUMP_SPEED 200
#define WALK_SPEED 500

class Character :
	public GameObject
{
public:
	Character();
	Character( int x, int y, int width, int height, int health );
	~Character();

	void Update( long delta_ms ) override;

	void Move( int direction );
	void Jump();

	inline bool IsOnFloor() { return m_onFLoor; };

protected:

	bool m_onFLoor;

	int m_health;
	int m_xSpeed;
	int m_ySpeed;
};

