#pragma once
#include "Vector2D.h"

class Pieza
{
private:
	//Posición
	Vector2D posicion;
	//Movimientos
	bool next;
	bool ocupada;
	//Colores, 
	

	int tipo;
public:
	//Constructor y destructor 
	Pieza();
	virtual ~Pieza();
	//Dibujar pieza
	void Dibuja();

	//set
	void setPosicion(float ix, float iy);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
	void setNext();
	void setColor();


	//get
	int getColor();
	int getPosicionX();
	int getPosicionY();
	bool getOcupado();
	bool getNext();



};

