#include "Pieza.h"

Pieza::Pieza()
{
	//constructor de posicion
	color = indefinido;
	tipo = INDEFINIDO;
	ocupada = false;
	next = false;

}

Pieza::~Pieza() {

}

void Pieza::Dibuja()
{

}

void Pieza::setColor(Color c)
{
	color = c;
}

void Pieza::setPosicion(int nx, int ny) {
	columna = nx;
	fila = ny;
}

void Pieza::setTipo(Tipo t)
{
	tipo = t;
}
/*Pieza(int _x, int _y, int _tipo, bool color);
virtual ~Pieza();
void Dibuja();


void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
void setNext();

int getPosicion();
bool getOcupado();
bool getNext();
*/


