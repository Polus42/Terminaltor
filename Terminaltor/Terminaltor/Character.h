#pragma once
#include "GameObject.h"

#define JUMP_SPEED 25000
#define WALK_SPEED 15000

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
	
	int GetHealth();

	inline bool IsOnFloor() { return m_onFLoor; };
	inline int XSpeed() { return m_xSpeed; };
	inline int YSpeed() { return m_ySpeed; };

protected:

	bool m_onFLoor;

	int m_health;
	int m_xSpeed;
	int m_ySpeed;
};

