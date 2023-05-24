#pragma once
#include"Pieza.h"
#include <stdlib.h>
#include<iostream>
using namespace std;
class Cortesana:public Pieza
{
public:

	Cortesana(Color color, int fila, int columna);


	//Métodos públicos
	void dibuja(float ix, float iy);
	bool mover(int nc, int nf);
	bool comer(int nc, int nf) { return mover(nc, nf); }
	bool getMovIniLargo() { return 0; }
	bool getMovIni() { return 0; } //no usado, sólo para incluirlo en el virtual de Pieza y aplicarlo en el enroque
	void setMovIni(bool nuevo) {} //no usado, sólo para incluirlo en el virtual de Pieza y aplicarlo en el enroque
};

