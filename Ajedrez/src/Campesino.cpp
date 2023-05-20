#include "Campesino.h"

Campesino::Campesino(Color col, int f, int c) {
	setColor(col);
	setTipo(CAMPESINO);
	fila = f;
	columna = c;
	mov_ini = 1;
	movIniLargo = 0;
}

bool Campesino::mover(int nc, int nf) {
	std::cout << "Entro en mover de campesino\n";
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
		return false;

	else {
		if (color == blanco) {
			if (mov_ini == 1) {
				if ((nc - columna == 2 || nc - columna == -2) && nf - fila == 2) {
					movIniLargo = 1;
					mov_ini = 0;
					return true;
				}
				else if ((nc - columna == 1 || nc - columna == -1) && nf - fila == 1) {
					movIniLargo = 0;
					mov_ini = 0;
					return true;
				}
			}

			else {
				if ((nc - columna == 1 || nc - columna == -1) && nf - fila == 1) {
					mov_ini = 0;
					movIniLargo = 0; //si se mueve una segunda vez después de haberse desplazado dos la primera vez
					return true;
				}

				return false;
			}
		}
		else if (color == negro) {
			if (mov_ini == 1) {
				if ((nc - columna == 2 || nc - columna == -2) && nf - fila == -2) {
					movIniLargo = 1;
					mov_ini = 0;
					return true;
				}
				else if ((nc - columna == 1 || nc - columna == -1) && nf - fila == -1) {
					movIniLargo = 0;
					mov_ini = 0;
					return true;
				}
			}

			else {
				if ((nc - columna == 1 || nc - columna == -1) && nf - fila == -1) {
					mov_ini = 0;
					movIniLargo = 0; //si se mueve una segunda vez después de haberse desplazado dos la primera vez
					return true;
				}

				return false;
			}
		}
		else {
			std::cout << "color de campesino no definido\n";
			return false;
		}
	}
}

bool Campesino::comer(int nc, int nf) {
	std::cout << "Entro en comer de campesino\n";

	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7)) {
		std::cout << "sale del tablero\n";
		return false;
	}
	else {
		std::cout << "no sale del tablero\n";
		if (color == blanco) {
			if (nc == columna && nc - fila == 1) {
				std::cout << "Desde campesino, la puedo comer \n ";
				return true;
			}
			else {
				std::cout << "Desde peon, NO la puedo comer \n ";
				return false;
			}
		}
		
		else if (color == negro) {
			if (nc == columna && nc - fila == -1) {
				std::cout << "Desde campesino, la puedo comer \n ";
				return true;
			}
			else {
				std::cout << "Desde peon, NO la puedo comer \n ";
				return false;
			}
		}

		else
		{
			std::cout << "color del campesino indefinido\n";
			return false;
		}
	}
	return false;
}

void Campesino::dibuja(float ix, float iy)
{
	if (color == blanco)
	{
		//Imagen de pieza blanca

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Peasant.png").id);


	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Peasant.png").id);

	}
	//Tengo que hacer el lugar donde se va a situar cada pieza, para ello hago un polígono

	glDisable(GL_LIGHTING);
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