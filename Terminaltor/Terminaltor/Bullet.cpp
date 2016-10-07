#include "Bullet.h"

Bullet::Bullet( float x, float y ) :
PhysicsObject( x, y, 50, 50 )
//,
//m_ySpeed( 0 ),
//m_xSpeed( 0 )
{
	m_x = 1;
}

Bullet::~Bullet()
{
}

void Bullet::Update(float delta_ms) {}