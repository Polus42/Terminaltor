#pragma once
#include "Sprite.h"

class GameObject
{
public:
	GameObject();
	GameObject( int width, int height );
	~GameObject();

	inline int Width() { return m_width; }
	inline int Height() { return m_height; }
	inline Sprite& GetSprite() { return m_sprite; }
	inline void SetSprite(Sprite& sprite) { m_sprite = sprite; }

	virtual void Update( float delta_ms ) {};

protected:
	int m_width;
	int m_height;

	Sprite m_sprite;
};