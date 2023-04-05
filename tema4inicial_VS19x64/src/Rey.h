#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(bool color, Vector2D m);
	//virtual ~Rey();

	//Métodos públicos
	void Dibuja();
	bool mVal(int dx, int dy, bool color);
	
	

};

