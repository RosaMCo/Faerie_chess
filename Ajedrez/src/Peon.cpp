#include "Peon.h"
#include <iostream>

Peon::Peon(Color col, int f, int c) {
	setColor(col);
	setTipo(PEON);
	fila = f;
	columna = c;
	mov_ini = 1;
	movIniLargo = 0;

}

bool Peon::mover(int nc, int nf) {
	std::cout << "Entro en mover de peon\n";
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
		return false;
	else
	{
		int incrementoInicial = (color == blanco) ? 2 : -2;
		int incremento = (color == blanco) ? 1 : -1;
		if ((nc == columna))
		{

			if ((mov_ini) && (nf-fila==incrementoInicial))
			{
				mov_ini = 0;
				movIniLargo = 1;
				return true;
			}
			else if (nf-fila==incremento)
			{
				mov_ini = 0;
				movIniLargo = 0;
				return true;
			}
			else return false;

		}
		else return false;

		/*if (color == blanco)
		{
			if (mov_ini == 1) {
				if ((nc == columna) && (nf - fila == 2)) 
				{
					movIniLargo = 1;
					mov_ini = 0;
					return true;
				}
				else if ((nc == columna) && (nf - fila == 1)) {
					movIniLargo = 0;
					mov_ini = 0;
					return true;
				}
			}

			else {
				if ((nc == columna) &&(( nf - fila) == 1)) 
				{
					mov_ini = 0;
					movIniLargo = 0; //si se mueve una segunda vez después de haberse desplazado dos la primera vez
					return true;
				}

				else return false;
			}
		}
		else if (color == negro)
		{
			if (mov_ini == 1) {
				if ((nc == columna) && ((nf - fila) == -2)) 
				{
					movIniLargo = 1;
					mov_ini = 0;
					return true;
				}
				else if ((nc == columna) && (nf - fila == -1)) {
					movIniLargo = 0;
					mov_ini = 0;
					return true;
				}
			}

			else {
				if ((nc == columna) && ((nf - fila) == -1)) 
				{
					mov_ini = 0;
					movIniLargo = 0; //si se mueve una segunda vez después de haberse desplazado dos la primera vez
					return true;
				}

				else return false;
			}
		}
		else
		{
			std::cout << "color de peon no definido\n";
			return false;
		}
		/*if (mov_ini == 1) {
			if (nc == columna && nf - fila <= 2) {
				movIniLargo = 1;
				mov_ini = 0;
				return true;
			}
			else return false;
		}

		else {
			if (nc == columna && nf - fila == 1) {
				mov_ini = 0;
				movIniLargo = 0; //si se mueve una segunda vez después de haberse desplazado dos la primera vez
				return true;
			}

			else return false;
		}
		//return false;*/
	}
}

bool Peon::comer(int nc, int nf) {
	std::cout << "Entro en comer de peon\n";
	bool comer = false;
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
	{
		std::cout << "sale del tablero\n"; comer = false;
		return false;
	}
	else
	{
		int incremento = (color == blanco) ? 1 : -1;
		if ((abs(nc - columna) == abs(nf - fila)) && (nf - fila == incremento))
			return true;
		else
			return false;

		/*std::cout << "no sale del tablero\n";
		//std::cout << "color = "<<color<<"\n";
		if (color == blanco)
		{
			//std::cout << "color de peon que se mueve es blanco\n";
			//std::cout << "columna= " << columna << " fila=" << fila << "\n";
			if(((nc-columna) == 1)|| (nc - columna))
			{
				//std::cout << "distancia en x de +-1\n";
				if (nf == (fila - 1))
				{
					//std::cout << "sentido en y de +1, correcto\n";
					std::cout << "Desde peon, la puedo comer \n "; 
					return true;
				}
			}
			else { 
				std::cout << "Desde peon, NO la puedo comer \n ";
				return false;  }
		}
		else if (color == negro)
		{
			if (((nc - columna) == 1) || (nc - columna))
			{
				//std::cout << "distancia en x de +-1\n";
				if (nf == (fila + 1))
				{
					//std::cout << "sentido en y de +1, correcto\n";
					std::cout << "Desde peon, la puedo comer \n "; 
					return true;
				}
			}
			else {
				std::cout << "Desde peon, NO la puedo comer \n ";
				return false;
			}
		}
		else
		{
			std::cout << "color del peon indefinido\n"; comer = false;
			return false;
		}*/
	}
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