#include "Regente.h"

Regente::Regente(Color col, int f, int c)
{
	setColor(col);
	setTipo(REGENTE);
	fila = f;
	columna = c;
	
}

void Regente::dibuja(float ix, float iy)
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Regent.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Regent.png").id);
		glDisable(GL_LIGHTING);
	}
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
bool Regente::mover(int nc, int nf)
{
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
		return false;

	if (((abs(columna - nc) == 2) || (abs(fila - nf) == 2)))
	{
			
		return true;
	}
	else if (((abs(nf - fila) == 2) && (abs(nc - columna) == 2)) || ((abs(nf - fila) == 2) && (abs(nc - columna) == 2)))
	{
		return true;
	}
	else { return false; std::cout << "movimiento del regente NO permitido\n"; }
}