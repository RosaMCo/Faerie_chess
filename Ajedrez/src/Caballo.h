#pragma once
#include "Pieza.h"

class Caballo :
	public Pieza //heredamos todas las variables y m�todos terrenales de Pieza (public mantiene los niveles de acceso)
{
public:
	//constructor y destructor
	Caballo(Color col, int f, int c);
	~Caballo() {};
	bool movOK(int nc, int nf);

};
