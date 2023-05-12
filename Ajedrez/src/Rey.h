#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(Color color, int fila,int columna);
	//virtual ~Rey();

	//Métodos públicos
	void dibuja(float ix, float iy);
	bool mover(int nf, int nc);
	bool comer(int nf, int nc) { return mover(nf, nc); }
	

};

