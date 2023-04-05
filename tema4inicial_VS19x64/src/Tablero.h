#pragma once
#include "Vector2D.h"

class Tablero
{
private:
	Vector2D casilla[8][8];
	bool ocupado[8][8];//hacerlo más limpio? cambiar Vector2D a otra clase que almacene posición y estado casilla?
public:
	Tablero();
};

