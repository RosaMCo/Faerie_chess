#pragma once
#include "freeglut.h"
#include <math.h>
#include "ETSIDI.h"
#include "Tablero.h"

#define HOME -10
class Mundo
{
private:
	
	//Casilla origen{ HOME, HOME };	//Casilla de origen para la implementaci�n del movimeinto por rat�n
	//Casilla destino{ HOME, HOME };	//Casilla de destsino para la implementaci�n del movimiento por rat�n
	int turno = 0;					//gesti�n del turno

public: 
	Tablero tablero;
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

	int* SeleccionarFicha(int button, int state, int x, int y);
	int* ValidarClick(int x, int y);
	//Casilla getCasilla(int x, int y);
	bool validarTurno(int color);
	int jaque();
};
