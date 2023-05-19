#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:

	Reina(Color color, int fila, int columna);
	//virtual ~Rey();

	//Métodos públicos
	void dibuja(float ix, float iy);
	//bool mover(int nc, int nf);
	bool mover(Color col, int nc, int nf); //solo para usar su formato virtual referido a los peones
	//bool comer(int nc, int nf) { return mover(nc, nf); }
	bool comer(Color col, int nc, int nf) { return mover(col, nc, nf); }; //solo para poder usar su formato virtual en Pieza y para poder definir comer en los peones
	bool getMovIniLargo() { return 0; } //solo para poder usar su formato virtual en Pieza y para poder comer al paso en los peones
};
