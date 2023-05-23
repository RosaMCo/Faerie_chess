#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"
#include <iostream>

class Tienda
{
private:
	int puntos_blanco;
	int puntos_negro;
	enum Comprador { BLANCO, NEGRO, NO_SEL };
	Comprador comprador;
public:

	Tienda();
	virtual ~Tienda() {};
	void dibuja();
	void compra();
	void inicializa();
	void tecla(unsigned char key);

};

