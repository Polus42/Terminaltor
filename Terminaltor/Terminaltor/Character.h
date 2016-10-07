#pragma once
#include "GameObject.h"

#define JUMP_SPEED 25000
#define WALK_SPEED 15000

class Character :
	public GameObject
{
public:
	Character();
	Character( float x, float y, int width, int height, int health );
	~Character();

	void Update( float delta_ms ) override;

	void Move( int direction );
	void Jump();
	
	int GetHealth();

	inline bool IsOnFloor() { return m_onFLoor; };
	inline float XSpeed() { return m_xSpeed; };
	inline float YSpeed() { return m_ySpeed; };

protected:

	bool m_onFLoor;

	int m_health;
	float m_xSpeed;
	float m_ySpeed;
};

