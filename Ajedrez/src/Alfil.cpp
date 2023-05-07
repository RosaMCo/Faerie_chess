#include "Alfil.h"
#include"freeglut.h"


//Para las piezas de tipo alfil, torre y reina, quiza fuera más conveniente sacar la posición actual(con fila y columna)
//y la posición a la que se desea mover (Quiza haciendo uso del raton) para sacar la casilla de destino

Alfil::Alfil(Color col, int f, int c) {
	setColor(col);
	setTipo(ALFIL);
	fila = f;
	columna = c;
}

bool Alfil::mover(int nx, int ny) {
	//El afil se mueve hacia arriba 
	
	if (ny - fila <= 7) {
		//Se mueve hacia la derecha
		if(nx - columna<=7)
			return true;
		//Se mueve hacia la izquierda 
		if (nx + columna <= 7)
			return true;
	}

	//El alfil se mueve hacia abajo
	else if (ny + fila <= 7) {
		//Se mueve hacia la derecha
		if (nx - columna <= 7)
			return true;
		//Se mueve hacia la izquierda 
		if (nx + columna <= 7)
			return true;
	}

	//falta comprobar que en caso de que la casilla final sea la misma que otra ficha, comemos esa ficha 
	else return false;
}

void Alfil::Dibuja()
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Fichas/W-Pontiff.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Fichas/B-Pontiff.png").id);
		glDisable(GL_LIGHTING);
	}
	//Tengo que hacer el lugar donde se va a situar cada pieza, para ello hago un polígono
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(posicion.getX(), posicion.getY(), 0.01);
	glTexCoord2d(1, 1); glVertex3f(posicion.getX(), posicion.getY(), 0.01);
	glTexCoord2d(1, 0); glVertex3f(posicion.getX(), posicion.getY(), 0.01);
	glTexCoord2d(0, 0); glVertex3f(posicion.getX(), posicion.getY(), 0.01);
	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}