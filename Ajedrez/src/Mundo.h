#pragma once
#include "freeglut.h"
#include <math.h>
#pragma once
#include "ETSIDI.h"
class Mundo
{
public: 

	Mundo();
	void tecla(unsigned char key);
	void inicializa();
	//void rotarOjo();
	void mueve();
	
	void dibuja();

	float x_ojo;
	float y_ojo;
	float z_ojo;
	//Estados de la máquina:
	enum ESTADO {Inicio, tienda, juego };
	ESTADO estado;
};
