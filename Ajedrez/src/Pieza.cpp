#include "Pieza.h"

Pieza::Pieza()
{
	//constructor de posicion
	color = blanco;
	tipo = INDEFINIDO;
	fila = columna=0;
	posicion.setPosicion(columna, fila);


}

Pieza::~Pieza() {

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
* 
void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
void setNext();

bool getOcupado();
bool getNext();
*/


