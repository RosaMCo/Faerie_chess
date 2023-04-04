#include "Pieza.h"

Pieza::Pieza()
{
	x = y = 0;
	rojo = verde = azul = 1;
	ocupada = false;
	next = false;
	tipo = 0;

}


Pieza::Pieza(int _x, int _y, bool blanco)
{
	x = _x;
	y = _y;
	tipo = 0;
	if (blanco == 0)
	{
		rojo = verde = azul = 0;

	}
	else {
		rojo = verde = azul = 255;

	}

}

void Pieza::Dibuja()
{

}


Pieza(int _x, int _y, int _tipo, bool color);
virtual ~Pieza();
void Dibuja();

void setPosicion(float ix, float iy);
void setColor(unsigned char r, unsigned char v, unsigned char a);
void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
void setNext();

int getPosicion();
bool getOcupado();
bool getNext();



