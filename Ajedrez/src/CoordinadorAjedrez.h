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
	void jugada(int button, int state, int x, int y);
	void dibuja();
protected:
	Mundo mundo;
	Tienda tienda;
	enum Estado { INICIO, JUEGO, TIENDA, REGLAS, GAMEOVER, FIN,JAQUEBLANCO, JAQUENEGRO};
	Estado estado;

};

