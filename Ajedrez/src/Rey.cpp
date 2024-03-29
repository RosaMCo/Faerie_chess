#include "Rey.h"
#include "freeglut.h"
#include <iostream>

Rey::Rey(Color col, int f, int c)
{
	setColor(col);
	setTipo(REY);
	fila = f;
	columna = c;
	movIni = 0;
 }

//Rey ::~Rey()
//{

//}
void Rey::dibuja(float ix, float iy)
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-King.png").id);
		glDisable(GL_LIGHTING);
	}
	else if (color == negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-King.png").id);
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

bool Rey::mover(int nc, int nf)
{
	if ((nc < 0) || (nc > 7) || (nf < 0) || (nf > 7))
		return false;
	else
	{
		if (((abs(columna - nc) == 1) && (abs(fila - nf) == 1))||((columna==nc)&&(abs(fila-nf)==1))||((fila == nf)&&(abs(columna-nc)==1)))
		{
			//std::cout << "movimiento de rey permitido\n";
			movIni = 1;
			return true;
		}
		else { return false; }//std::cout << "movimiento de rey NO permitido\n"; }
		//El rey se mueve uno para arriba
		/*if (nc == fila + 1)
			//El rey se mueve uno para arriba y uno a la izq, es decir,
			//diagonal
			if (nf == columna - 1)
			{
				movIni = 1;
				return true;
			}
			else if (nf == columna + 1)//Diagonal derecha
			{
				movIni = 1;
				return true;
			}
			else if (nf == columna)//No hay mov izq o der
			{
				movIni = 1;
				return true;
			}
			else
				return false;

		//Lo mismo que la anterior pero hacia abajo
		else if (nc == fila - 1)
			//El rey se mueve uno para arriba y uno a la izq, es decir,
			//diagonal
			if (nf == columna - 1)
			{
				movIni = 1;
				return true;
			}
			else if (nf == columna + 1)//Diagonal derecha
			{
				movIni = 1;
				return true;
			}
			else if (nf == columna)//No hay mov izq o der
			{
				movIni = 1;
				return true;
			}
			else
				return false;

		//Se queda en la misma posici�n
		else if (nc == fila)
			//Mov a la izquierda
			if (nf == columna - 1)
			{
				movIni = 1;
				return true;
			}
		//Mov a la derecha
			else if (nf == columna + 1)
			{
				movIni = 1;
				return true;
			}
			else
				return false;*/

	}

}