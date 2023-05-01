#pragma once
#include "freeglut.h"
#include <math.h>
#pragma once
#include "ETSIDI.h"
#include "Tablero.h"
class Mundo
{
private:
	Tablero tablero;
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
	
};
