#pragma once
#include "GameObject.h"

#define JUMP_SPEED 750
#define WALK_SPEED 150
#define GRAVITY    491.0f

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

