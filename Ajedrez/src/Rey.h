#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(Color color, int fila,int columna);
	//virtual ~Rey();

	//M�todos p�blicos
	void Dibuja();
	bool mRey(float nf, float nc);
	
	

};

