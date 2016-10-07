#include "Character.h"
#include "Terrain.h"
#include "Bullet.h"

Character::Character() :
PhysicsObject(),
m_health( 0 )
{
}

Character::Character( float x, float y, int width, int height, int health ) :
PhysicsObject( x, y, width, height ),
m_health( health )
{
}

Character::~Character()
{
}

void Character::Move( int direction ) {
	if (direction < 0) {
		if ( m_x > Terrain::GetInstance().Distance() + 100 )
			m_xSpeed -= WALK_SPEED;
		else
			m_xSpeed = 0;
	}
	else if (direction > 0) {
		m_xSpeed += WALK_SPEED;
	}
	else{
		m_xSpeed = 0;
	}
}

void Character::Jump() {
	if ( !m_onFLoor )
		return;
	m_ySpeed = JUMP_SPEED;
	m_y++;
	m_onFLoor = false;
}

void Character::Shoot() {
	Terrain::GetInstance() << new Bullet(X() + Width() + 30, Y() + Height() - 25);
}

void Character::Update( float delta_ms ) {
	Terrain& terrain = Terrain::GetInstance();
	float dT = delta_ms * 10.0f;
	
	int testX = (m_xSpeed > 0.0f) ? m_x + m_width : m_x;
	if ( terrain.GetTile(testX, m_y) != 0 ) {
		if ( terrain.GetTile(testX, m_y + 100.0f) != 0 ) {
			m_x /= 100.0f;
			m_x *= 100.0f;
			m_xSpeed = 0.0f;
		}
		else {
			m_y += 100.0f;
		}
	}
	{
		m_x += ( m_xSpeed * dT ) / 1000;
	}
	{
		Terrain& terrain = Terrain::GetInstance();
		int dX = terrain.Distance() + ((terrain.Width()*100.0f) / 3);
		//*
		if (m_x >= dX)
			terrain.Slide(m_x - dX);//*/
	}
	
	int testY = (m_ySpeed > 0.0f) ? m_y + m_height : m_y - 100.0f;
	if ( terrain.GetTile( m_x, testY ) != 0 ) {
		m_y /= 100.0f;
		m_y *= 100.0f;
		if (m_ySpeed <= 0.0f) {
			m_onFLoor = true;//*
			if ( terrain.GetTile( m_x, m_y ) != 0 )
				m_y += 100;//*/
		}
		m_ySpeed = 0.0f;
	}
	else {
		if (m_ySpeed <= 0.0f)
			m_onFLoor = false;
	}
	if (!m_onFLoor) {
		float oldY = m_y;
		m_y += (m_ySpeed * dT) / 1000.0f;
		if ( m_ySpeed <= 0 ) {
			for (float y = oldY; y > m_y; y-=50.f)
				if (terrain.GetTile(m_x, y) != 0) {
					m_y = y;
					break;
				}
		}
		m_ySpeed -= ( GRAVITY * dT ) / 1000.0f;
	}

	m_xSpeed = 0.0f;
}

int Character::GetHealth()
{
	return m_health;
}