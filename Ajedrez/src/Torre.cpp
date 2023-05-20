#include "Torre.h"
#include"freeglut.h"

Torre::Torre(Color col, int f, int c) {
	setColor(col);
	setTipo(TORRE);
	fila = f;
	columna = c;
	movIni = 0;
}

bool Torre::mover(int nx, int ny) {
	if ((nx < 0) || (nx > 7) || (nx < 0) || (ny > 7))
		return false;
	else
	{
		if (((columna == nx) && (fila != ny)) || ((columna != nx) && (fila == ny)))
		{
			movIni = 1;
			return true;
		}
		else return false;
	}
	/*else
	{
		//Movimiento arriba 
		if (nx == columna && ny - fila <= 7) {
			return true;
			movIni = 1;
		}

		//Movimiento abajo 
		else if (nx == columna && ny + fila <= 7) {
			return true;
			movIni = 1;
		}

		//Movimiento derecha
		else if (nx - columna <= 7 && ny == fila) {
			return true;
			movIni = 1;
		}

		//Movimiento izquierda 
		else if (nx + columna <= 7 && ny == fila) {
			return true;
			movIni = 1;
		}

		else return false;
	}*/
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