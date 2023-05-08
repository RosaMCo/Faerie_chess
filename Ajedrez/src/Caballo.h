#pragma once
#include "Pieza.h"

class Caballo :
	public Pieza //heredamos todas las variables y métodos terrenales de Pieza (public mantiene los niveles de acceso)
{
public:
	//constructor y destructor
	Caballo(Color col, int f, int c);
	~Caballo() {};
	bool mover(int nc, int nf);
	bool comer(int nx, int ny) { return mover(nx, ny); }
	void dibuja(float ix, float iy);

};

