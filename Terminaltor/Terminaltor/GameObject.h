#pragma once
#include "Sprite.h"

class GameObject
{
public:
	GameObject();
	GameObject( int x, int y, int width, int height );
	~GameObject();

	inline int X() { return m_x; }
	inline int Y() { return m_y; }
	inline int Width() { return m_width; }
	inline int Height() { return m_height; }
	inline Sprite& GetSprite() { return m_sprite; }
	inline void SetSprite(Sprite& sprite) { m_sprite = sprite; }

	virtual void Update( long delta_ms ) {};

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

	Sprite m_sprite;
};