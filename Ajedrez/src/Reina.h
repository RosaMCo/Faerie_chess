#pragma once
#include "Pieza.h"
class Reina:public Pieza
{
public:

	Reina(bool color, int fila, int columna);
	//virtual ~Rey();

	//M�todos p�blicos
	void Dibuja();
	bool mReina(float nf, float nc);



};
