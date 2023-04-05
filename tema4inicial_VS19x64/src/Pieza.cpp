#include "Pieza.h"

Pieza::Pieza()
{
	//constructor de posicion
	
	ocupada = false;
	next = false;
	tipo = 0;

}

Pieza::~Pieza() {

}

void Pieza::Dibuja()
{

}

void Pieza::setColor()
{

}

/*Pieza(int _x, int _y, int _tipo, bool color);
virtual ~Pieza();
void Dibuja();

void setPosicion(float ix, float iy);
void setColor(unsigned char r, unsigned char v, unsigned char a);
void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
void setNext();

int getPosicion();
bool getOcupado();
bool getNext();
*/


