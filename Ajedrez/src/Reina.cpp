#include "Reina.h"
#include "freeglut.h"


Reina::Reina(Color col, int f, int c)
{
	setColor(col);
	setTipo(REINA);
	fila = f;
	columna = c;
}

void Reina::dibuja(float ix, float iy)
{
	if (color == blanco)
	{
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/W-Queen.png").id);
		glDisable(GL_LIGHTING);
	}
	else if(color==negro)
	{
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/Fichas/B-Queen.png").id);
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

bool Reina::mover(int nf, int nc)
{
	//La reina utiliza los movimientos de la torre y del alfil 
	//Para la torre: La reina debe moverse hacia la derecha "O" a la izquierda:
	if ((nf == fila) && (nc == columna))
		return false; //No se puede mover distinta fila y columna
	else if ((nf == fila) || (nc == columna))
		return true;//Se puede mover de arriba a abajo o de derecha a izquierda

	//Para el alfil:: La reina se mueve en diagonales
	//Lo dividimos en dos diagonales como una "x"
		//Siel destino de la pieza es
	else if (((nf < fila) && (nc < columna)) || ((nf > fila) && (nc > columna)))//Describí el lugar del movimiento del alfil. 
		if (((nc - nf) == (columna - fila))|| ((nf + nc) == (columna + fila)))//Con este moimiento bajan o suben dependiendo de la posición del alfil
			return true;
		else
			return false; 
		//Si el destino de la pieza es
	else if (((nf < fila) && (nc > columna)) || ((nf > fila) && (nc < columna))) //Descripción del destino de los alfiles  
		if (((nf + nc) == (columna + fila))|| ((nf + nc) == (columna + fila))) //movimiento de subida o bajada dependiendo de la posición del alfil.
			return true;
		else
			return false;
	//Como se puede observar, las posiciones de las columnas y filas deben ser iguales para que cumpla la función del movimiento alfil en la reina
	else
		return false;
	
}