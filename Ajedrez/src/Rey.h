#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(Color color, int fila,int columna);
	//virtual ~Rey();

	//M�todos p�blicos
	void dibuja(float ix, float iy);
	bool mover(int nc, int nf);
	bool comer(int nc, int nf) { return mover(nc, nf); }
	

};

