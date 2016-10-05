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

void Character::Jump() {
	m_ySpeed = JUMP_SPEED;
	m_y++;
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
	
	bool onFloor = false;
	int testY = (m_ySpeed > 0) ? m_y + m_height : m_y;
	if ( terrain.GetTile( m_x, testY ) != 0 ) {
		m_y /= 100;
		m_y *= 100;
		if ( m_ySpeed < 0 )
			onFloor = true;
		m_ySpeed = 0;
	}
	if (!onFloor) {
		m_ySpeed -= 981000 / delta_ms;
	}
}