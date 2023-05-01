#include "Casilla.h"


void Casilla::setPieza(Pieza* pieza)
{
	//Esta función se utiliza para poner la pieza.
	this->pieza = pieza;
}

Pieza* Casilla::getPieza()
{
	//Cogemos una pieza de la casilla y retorna el valor de pieza
	return pieza;
}


void Casilla::dibuja() {

	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	//Posición de la pieza en cada fila y cada columna + un poco de la pieza para recalcar el área
	glVertex2f(pieza->getFila() + 1.0, pieza->getColumna() + 1.0);
	glVertex2f(pieza->getFila() + 1.0, pieza->getColumna() - 1.0);
	glVertex2f(pieza->getFila() - 1.0, pieza->getColumna() - 1.0);
	glVertex2f(pieza->getFila() - 1.0, pieza->getColumna() + 1.0);
	glEnd();
	glEnable(GL_LIGHTING);
}


void Casilla:: Iluminati()	
{
	//Se ilumina la la casilla en color rojo
	rojo = 255;
	azul = 0;
	verde = 0;
}


void Casilla::setColor(unsigned char r, unsigned char v, unsigned char a) { //pone el color
	rojo = r;
	verde = v;
	azul = a;
}

