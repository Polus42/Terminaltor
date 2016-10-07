#pragma once
#include "GameObject.h"
class PhysicsObject :
	public GameObject
{
public:
	PhysicsObject();
	PhysicsObject( float x, float y, int width, int height );
	~PhysicsObject();

	inline float X() { return m_x; }
	inline float Y() { return m_y; }
	inline float XSpeed() { return m_xSpeed; };
	inline float YSpeed() { return m_ySpeed; };
	inline bool IsPendingDelete() { return m_pendingDelete; };

protected:
	float m_x;
	float m_y;
	float m_xSpeed;
	float m_ySpeed;
	bool m_pendingDelete;
};

