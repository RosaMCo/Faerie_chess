#include "Caballo.h"

Caballo::Caballo(Color col, int f, int c) {
	setColor(col);
	fila = f;
	columna = c;
	setTipo(CABALLO);
}
bool Caballo::mover(int nc, int nf)
	{
		if (nc < 0 || nf < 0 || nc > 7 || nf > 7)
		{
			return false;
		}
		if (((nc = columna - 1) && (nf = fila - 2)) || ((nc = columna + 1) && (nf = fila - 2)) || ((nc = columna + 2) && (nf = fila - 1)) || ((nc = columna + 2) && (nf = fila + 1)) || ((nc = columna + 1) && (nf = fila + 2)) || ((nc = columna - 1) && (nf = fila + 2)) || ((nc = columna - 2) && (nf = fila + 1)) || ((nc = columna - 2) && (nf = fila + 1)))
		{
			return true;
		}
		else return false;
}

void Caballo::dibuja(float ix, float iy)
{
	if (color == negro)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Knight.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == blanco)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Knight.png").id);
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