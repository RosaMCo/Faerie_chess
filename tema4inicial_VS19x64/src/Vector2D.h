#pragma once
class Vector2D
{
private:
	//Coords
	float x;
	float y;

public:
	//Constructor y destructor
	Vector2D();
	virtual ~Vector2D();
	Vector2D(float ix, float iy);
	void setPosicion(float ix, float iy);
	float getX() { return x; }
	float getY() { return y; }
};

