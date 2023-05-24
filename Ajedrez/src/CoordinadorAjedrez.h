#pragma once
#include "Mundo.h"
#include "Tienda.h"
#include "freeglut.h"
#include"Reglas.h"


class CoordinadorAjedrez
{
public:
	float x_ojo, y_ojo, z_ojo;
	CoordinadorAjedrez();
	virtual ~CoordinadorAjedrez() {};
	bool cursor;

	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void jugada(int button, int state, int x, int y);
	void dibuja();
	void jaque();
	void cambiaTurno();
protected:
	Mundo mundo;
	Tienda tienda;
	Reglas reglas;
	enum Estado { INICIO, JUEGO, TIENDA, REGLAS, GAMEOVER, FIN, JAQUEBLANCO, JAQUENEGRO };
	Estado estado;
	Intercambio intercambio;//para el intercambio de piezas
	//Variables de jaque desactivadas
	bool JaqueBlanco = false;
	bool JaqueNegro = false;

};

