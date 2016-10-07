#include "PhysicsObject.h"

PhysicsObject::PhysicsObject() :
m_x( 0 ),
m_y( 0 ),
m_xSpeed( 0 ),
m_ySpeed( 0 ),
m_pendingDelete( false ),
GameObject()
{
}

PhysicsObject::PhysicsObject( float x, float y, int width, int height ) :
m_x( x ),
m_y( y ),
m_xSpeed( 0 ),
m_ySpeed( 0 ),
m_pendingDelete( false ),
GameObject( width, height )
{
}

PhysicsObject::~PhysicsObject()
{
}
