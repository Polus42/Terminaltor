#pragma once
class GameObject
{
public:
	GameObject( int x, int y, int width, int height );
	~GameObject();

	inline int X() { return m_x; }
	inline int Y() { return m_y; }
	inline int Width() { return m_width; }
	inline int Height() { return m_height; }

	virtual void Update( long delta_ms ) {};

protected:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};