#pragma once
#include "Pieza.h"
#include <stdlib.h>
#include<iostream>
using namespace std;
class Regente:public Pieza
{
	Regente(Color color, int fila, int columna);
	

	//Métodos públicos
	void dibuja(float ix, float iy);
	bool mover(int nc, int nf);
	bool comer(int nc, int nf) { return mover(nc, nf); }

};

