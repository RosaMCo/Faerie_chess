#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:

	Reina(Color color, int fila, int columna);
	//virtual ~Rey();

	//M�todos p�blicos
	void dibuja(float ix, float iy);
	bool mover(int nc, int nf);
	bool comer(int nc, int nf) { return mover(nc, nf); }
};
