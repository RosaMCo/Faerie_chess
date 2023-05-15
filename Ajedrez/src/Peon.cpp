#include "Peon.h"

Peon::Peon(Color col, int f, int c) {
	setColor(col);
	setTipo(PEON);
	fila = f;
	columna = c;
	mov_ini = 1;
	movIniLargo = 0;
}

bool Peon::mover(int nc, int nf) {
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
		return false;
	else
	{
		if (mov_ini == 1) {
			if (nc == columna && nf - fila <= 2) {
				movIniLargo = 1;
				mov_ini = 0;
				return true;
			}
			return false;
		}

		else {
			if (nc == columna && nf - fila == 1) {
				mov_ini = 0;
				movIniLargo = 0; //si se mueve una segunda vez después de haberse desplazado dos la primera vez
				return true;
			}

			return false;
		}
		return false;
	}
}

bool Peon::comer(int nc, int nf) {
	if ((nc - columna == 1 || nc - columna == -1) && (fila == 1 )) {
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

		
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Pawn.png").id);

	}
	//Tengo que hacer el lugar donde se va a situar cada pieza, para ello hago un polígono

	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(ix, iy, 0.1);
	glTexCoord2d(1, 1); glVertex3f(ix + 20.0/8, iy, 0.1);
	glTexCoord2d(1, 0); glVertex3f(ix + 20.0/8, iy + 20.0/8, 0.1);
	glTexCoord2d(0, 0); glVertex3f(ix, iy + 20.0/8, 0.1);
	glEnd();
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	
}