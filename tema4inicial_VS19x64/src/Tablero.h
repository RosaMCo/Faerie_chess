#pragma once
#include "Vector2D.h"

class Tablero
{
private:
	Vector2D casilla[8][8];
	bool ocupado[8][8];//hacerlo m�s limpio? cambiar Vector2D a otra clase que almacene posici�n y estado casilla?
public:
	Tablero();
};

