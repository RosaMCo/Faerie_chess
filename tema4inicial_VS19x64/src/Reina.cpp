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

bool Reina::mReina(float nx, float ny)
{
	//La reina utiliza los movimientos de la torre y del alfil 
	//Para la torre
	

	//Para el alfil

	return true;
}