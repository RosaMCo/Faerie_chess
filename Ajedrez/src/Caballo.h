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
	bool comer(int nc, int nf) { return mover(nc, nf); }
	void dibuja(float ix, float iy);
	bool getMovIniLargo() { return 0; } //solo para poder usar su formato virtual en Pieza y para poder comer al paso en los peones
	bool getMovIni() { return 0; } //no usado, sólo para incluirlo en el virtual de Pieza y aplicarlo en el enroque
};

