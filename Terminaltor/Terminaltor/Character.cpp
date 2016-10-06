#include "Character.h"
#include "Terrain.h"

Character::Character( int x, int y, int width, int height, int health ) :
GameObject( x, y, width, height ),
m_xSpeed( 0 ),
m_ySpeed( 0 ),
m_health( health )
{
}

Character::~Character()
{
}

void Character::Move( int direction ) {
	if (direction < 0) {
		if (m_x > Terrain::GetInstance().Distance() + 1)
			m_xSpeed = -WALK_SPEED;
	}
	else if (direction > 0) {
		m_xSpeed = WALK_SPEED;
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

void Character::Update( long delta_ms ) {
	Terrain& terrain = Terrain::GetInstance();
	
	int testX = (m_xSpeed > 0) ? m_x + m_width : m_x;
	if ( terrain.GetTile(testX, m_y) != 0 ) {
		if ( terrain.GetTile(testX, m_y + 100) != 0 ) {
			m_x /= 100;
			m_x *= 100;
			m_xSpeed = 0;
		}
		else {
			m_y += 100;
		}
	}
	
	int testY = (m_ySpeed > 0) ? m_y + m_height : m_y;
	if ( terrain.GetTile( m_x, testY ) != 0 ) {
		m_y /= 100;
		m_y *= 100;
		if ( m_ySpeed <= 0 )
			m_onFLoor = true;
		m_ySpeed = 0;
	}
	if (!m_onFLoor) {
		m_y += ( m_ySpeed * delta_ms ) / 1000;
		m_ySpeed -= ( 981 * delta_ms ) / 1000;
	}
}