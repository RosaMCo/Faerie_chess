#pragma once
#include "Vector2D.h"

class Pieza
{
protected:
	//Posición en el tablero (matriz)
	int fila;
	int columna;
	//Movimientos
	bool next;
	bool ocupada;
	//Colores
	bool color;//1 para blancas, 0 para negras

	

	int tipo;
public:
	//Constructor y destructor 
	Pieza();
	virtual ~Pieza();
	//Dibujar pieza
	void Dibuja();
	bool getColor() { return color; }
	//set
	void setPosicion(float ix, float iy);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
	void setNext();
	void setColor();


	//get
	int getPosicionX();
	int getPosicionY();
	bool getOcupado();
	bool getNext();



};

