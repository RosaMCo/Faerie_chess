#include "Obelisco.h"

Obelisco::Obelisco(Color col, int f, int c) {
	setColor(col);
	setTipo(OBELISCO);
	fila = f;
	columna = c;
	movIni = 0;
}

bool Obelisco::mover(int nc, int nf) {
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
		return false;
	else
	{
		if (((columna == nc) && (fila != nf)) || ((columna != nc) && (fila == nf)))
		{
			movIni = 1;
			return true;
		}
		else if ((nc == columna + 1 || nc == columna - 1) && (nf == fila + 1 || nf == fila - 1)) {
			movIni = 1;
			return true;
		}
		else return false;
	}
	return false;
}

void Obelisco::dibuja(float ix, float iy) {
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Tower.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Tower.png").id);
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