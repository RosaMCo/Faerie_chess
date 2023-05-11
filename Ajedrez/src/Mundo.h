#pragma once
#include "freeglut.h"
#include <math.h>

#include "ETSIDI.h"
#include "Tablero.h"
#define HOME -10
class Mundo
{
private:
	Tablero tablero;
	//Casilla origen{ HOME, HOME };	//Casilla de origen para la implementación del movimeinto por ratón
	//Casilla destino{ HOME, HOME };	//Casilla de destsino para la implementación del movimiento por ratón
	int turno = 0;					//gestión del turno

public: 

	Mundo();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void inicializa();
	//void rotarOjo();
	void mueve();
	
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;

	int jugada(int button, int state, int x, int y);
	//Casilla getCasilla(int x, int y);
	bool validarTurno(int color);
};
