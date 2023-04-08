#pragma once
#include "Pieza.h"
class Rey:public Pieza
{
public:

	Rey(bool color, Vector2D m);
	//virtual ~Rey();

	//Métodos públicos
	void Dibuja();
	bool mRey(float nx, float ny);
	
	

};

