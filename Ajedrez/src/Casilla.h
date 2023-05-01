#pragma once
//EN cada una de las casillas se encuantran las piezas
#include "Pieza.h"
#include "freeglut.h"

class Casilla {

	//Atributos privados
private:

	//Puntero a pieza
	Pieza* pieza;
	//Colores
	unsigned char rojo, verde, azul;
public:

	
	Casilla() {};
	virtual ~Casilla() {};

	void setPieza(Pieza* pieza);
	Pieza* getPieza();
	
	void dibuja();
	void Iluminati();
	void setColor(unsigned char r, unsigned char v, unsigned char a);




};