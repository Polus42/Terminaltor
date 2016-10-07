#include "Bullet.h"
#include "Terrain.h"

Bullet::Bullet( float x, float y ) :
PhysicsObject( x, y, 50, 50 )
{
	m_xSpeed = BULLET_SPEED;
	m_ySpeed = 0;
}

Bullet::~Bullet()
{
}

void Bullet::Update( float delta_ms ) {
	float dT = delta_ms * 10.0f;
	float oldX = m_x;
	m_x += (m_xSpeed * dT) / 1000;
	if (Terrain::GetInstance().CheckHit( this, oldX )) {
		m_pendingDelete = true;
	}
}