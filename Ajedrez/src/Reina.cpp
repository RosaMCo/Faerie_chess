#include "Reina.h"
#include "freeglut.h"

Reina::Reina(bool col, int f, int c)
{
	color = col;
	fila = f;
	columna = c;
}

void Reina:: Dibuja()
{
	if (color == 1)
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D); //Falta modificar para poner la imagen
	else
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);//Falta modificar para poner la imagen del rey negro

}

bool Reina::mReina(float nf, float nc)
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