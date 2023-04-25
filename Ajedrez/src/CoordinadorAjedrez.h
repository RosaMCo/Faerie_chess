#pragma once
#include "Mundo.h"
#include "Tienda.h"

class CoordinadorAjedrez
{
public:
	CoordinadorAjedrez();
	virtual ~CoordinadorAjedrez() {};

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	Tienda tienda;
	enum Estado { INICIO, JUEGO, TIENDA, REGLAS};
	Estado estado;

};

