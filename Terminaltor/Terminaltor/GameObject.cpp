#include "GameObject.h"

GameObject::GameObject() :
m_width( 0 ),
m_height( 0 ),
m_sprite()
{
}

GameObject::GameObject( int width, int height ) :
m_width( width ),
m_height( height ),
m_sprite()
{
}

GameObject::~GameObject()
{
}
