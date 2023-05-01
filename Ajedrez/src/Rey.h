#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(Color color, int fila,int columna);
	//virtual ~Rey();

	//Métodos públicos
	void Dibuja();
	bool mRey(float nf, float nc);
	
	

};

