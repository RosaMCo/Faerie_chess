#include "Peon.h"

Peon::Peon(Color col, int f, int c) {
	setColor(col);
	setTipo(PEON);
	fila = f;
	columna = c;
	mov_ini = 1;
}

bool Peon::mover(int nx, int ny) {
	if (mov_ini == 1) {
		if (nx == columna && ny - fila <=2) {
			return true;
		}
		return false;
	}

	else {
		if (nx == columna && ny - fila == 1) {
			return true;
		}

		return false;
	}
	return false;
}

bool Peon::comer(int nx, int ny) {
	if ((nx - columna == 1 || nx - columna == -1) && (fila == 1 )) {
		return true;
	}
	return false;
}

void Peon::dibuja(float ix, float iy)
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Pawn.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Pawn.png").id);
		glDisable(GL_LIGHTING);
	}
	//Tengo que hacer el lugar donde se va a situar cada pieza, para ello hago un polígono
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(ix, iy, 0.1);
	glTexCoord2d(1, 1); glVertex3f(ix, iy, 0.1);
	glTexCoord2d(1, 0); glVertex3f(ix, iy, 0.1);
	glTexCoord2d(0, 0); glVertex3f(ix, iy, 0.1);
	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}