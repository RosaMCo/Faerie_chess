#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Pieza.h"
class Tienda
{
private:

public:

	int dinero_inicial;
	int costo;
	int numero_piezas_max;
	int numero_piezas;

	Tienda();
	virtual ~Tienda() {};
	void dibuja();
	void compra();
	void inicializa();

};

