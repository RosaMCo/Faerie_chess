#include "Vector2D.h"
Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}
Vector2D::~Vector2D()
{

}
Vector2D::Vector2D(float ix, float iy)
{
	x = ix;
	y = iy;
}

void Vector2D::setPosicion(float ix, float iy) {
	x = ix;
	y = iy;
}
