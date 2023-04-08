#include "Rey.h"
#include"freeglut.h"
Rey::Rey(bool color, Vector2D m)
{
	Color = color;
	posicion = m;
 }

//Rey ::~Rey()
//{

//}
void Rey:: Dibuja()
{
	if (Color== blanco)
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D); //Falta modificar para poner la imagen
	else
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);//Falta modificar para poner la imagen del rey negro
}

bool Rey::mRey(float nx, float ny)
{
	//El rey se mueve uno para arriba
	if (ny == getPosicionY() + 1)
		//El rey se mueve uno para arriba y uno a la izq, es decir,
		//diagonal
		if (nx == getPosicionX() - 1)
			return true;
		else if (nx == getPosicionX() + 1)//Diagonal derecha
			return true;
		else if (nx == getPosicionX())//No hay mov izq o der
			return true;
		else
			return false;

	//Lo mismo que la anterior pero hacia abajo
	else if (ny == getPosicionY() - 1)
		//El rey se mueve uno para arriba y uno a la izq, es decir,
		//diagonal
		if (nx == getPosicionX() - 1)
			return true;
		else if (nx == getPosicionX() + 1)//Diagonal derecha
			return true;
		else if (nx == getPosicionX())//No hay mov izq o der
			return true;
		else
			return false;

	//Se queda en la misma posición
	else if (ny == getPosicionY())
		//Mov a la izquierda
		if (nx == getPosicionX() - 1)
			return true;
		//Mov a la derecha
		else if (nx == getPosicionX() + 1)
			return true;
		else
			return false;



}