#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:

	Reina(Color color, int fila, int columna);
	//virtual ~Rey();

	//M�todos p�blicos
	void dibuja(float ix, float iy);
	bool mover(int nf, int nc);
	bool comer(int nf, int nc) { return mover(nf, nc); }
};
