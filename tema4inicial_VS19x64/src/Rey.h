#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(bool color, Vector2D m);
	//virtual ~Rey();

	//M�todos p�blicos
	void Dibuja();
	bool mVal(int dx, int dy, bool color);
	
	

};

