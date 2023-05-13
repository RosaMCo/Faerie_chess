#include "Torre.h"
#include"freeglut.h"

Torre::Torre(Color col, int f, int c) {
	setColor(col);
	setTipo(TORRE);
	fila = f;
	columna = c;
}

bool Torre::mover(int nx, int ny) {
	//Movimiento arriba 
	if (nx == columna && ny - fila <= 7) {
		return true;
	}

	//Movimiento abajo 
	else if (nx == columna && ny + fila <= 7) {
		return true;
	}

	//Movimiento derecha
	else if (nx - columna <= 7 && ny == fila) {
		return true;
	}

	//Movimiento izquierda 
	else if (nx + columna <= 7 && ny == fila) {
		return true;
	}

	else return false;

	//falta comprobar que en caso de que la casilla final sea la misma que otra ficha, comemos esa ficha 
}

void Torre::dibuja(float ix, float iy)
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Rook.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Rook.png").id);
		glDisable(GL_LIGHTING);
	}
	//Tengo que hacer el lugar donde se va a situar cada pieza, para ello hago un polígono
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(ix, iy, 0.1);
	glTexCoord2d(1, 1); glVertex3f(ix + 20.0 / 8, iy, 0.1);
	glTexCoord2d(1, 0); glVertex3f(ix + 20.0 / 8, iy + 20.0 / 8, 0.1);
	glTexCoord2d(0, 0); glVertex3f(ix, iy + 20.0 / 8, 0.1);
	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}