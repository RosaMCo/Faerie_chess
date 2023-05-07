#pragma once
#include "Mundo.h"
#include "Tienda.h"
#include "freeglut.h"

class CoordinadorAjedrez
{
public:
	float x_ojo, y_ojo, z_ojo;
	CoordinadorAjedrez();
	virtual ~CoordinadorAjedrez() {};

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve(int button, int state, int x, int y);
	void dibuja();
protected:
	Mundo mundo;
	Tienda tienda;
	enum Estado { INICIO, JUEGO, TIENDA, REGLAS, GAMEOVER, FIN};
	Estado estado;

};

