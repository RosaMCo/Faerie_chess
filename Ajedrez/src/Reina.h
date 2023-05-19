#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:

	Reina(Color color, int fila, int columna);
	//virtual ~Rey();

	//Métodos públicos
	void dibuja(float ix, float iy);
	bool mover(int nc, int nf);
	bool comer(int nc, int nf) { return mover(nc, nf); }
	bool getMovIniLargo() { return 0; } //solo para poder usar su formato virtual en Pieza y para poder comer al paso en los peones
};
