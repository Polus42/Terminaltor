#include "GameObject.h"

GameObject::GameObject() :
m_x( 0 ),
m_y( 0 ),
m_width( 0 ),
m_height( 0 ),
m_sprite()
{
}

GameObject::GameObject( float x, float y, int width, int height ) :
m_x( x ),
m_y( y ),
m_width( width ),
m_height( height ),
m_sprite()
{
}

GameObject::~GameObject()
{
}
