#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"
#include <iostream>
#include "Tablero.h"
#include "Mundo.h"
enum Comprador { BLANCO, NEGRO, NO_SEL };

class Tienda
{
private:
	int puntos_blanco;
	int puntos_negro;
	Comprador comprador;
public:

	Tienda();
	virtual ~Tienda() {};
	void dibuja();
	Comprador compra(int precio);//comprueba si el jugador tiene puntos para comprar una pieza y, en caso afirmativo, realiza el cobro y retorna true
	Intercambio tecla(unsigned char key);

};

