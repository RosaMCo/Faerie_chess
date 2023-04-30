#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:

	Reina(bool color, int fila, int columna);
	//virtual ~Rey();

	//Métodos públicos
	void Dibuja();
	bool mReina(float nf, float nc);



};
