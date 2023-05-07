#include "Caballo.h"

Caballo::Caballo(Color col, int f, int c) {
	setColor(col);
	fila = f;
	columna = c;
	setTipo(CABALLO);
}
bool Caballo::movOK(int nc, int nf)
	{
		if (nc < 0 || nf < 0 || nc > 8 || nf > 8)
		{
			return false;
		}
		if (((nc = columna - 1) && (nf = fila - 2)) || ((nc = columna + 1) && (nf = fila - 2)) || ((nc = columna + 2) && (nf = fila - 1)) || ((nc = columna + 2) && (nf = fila + 1)) || ((nc = columna + 1) && (nf = fila + 2)) || ((nc = columna - 1) && (nf = fila + 2)) || ((nc = columna - 2) && (nf = fila + 1)) || ((nc = columna - 2) && (nf = fila + 1)))
		{
			return true;
		}
		else return false;
}

void Caballo::Dibuja()
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Fichas/W-Knight.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/Fichas/B-Knight.png").id);
		glDisable(GL_LIGHTING);
	}
	//Tengo que hacer el lugar donde se va a situar cada pieza, para ello hago un pol�gono
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