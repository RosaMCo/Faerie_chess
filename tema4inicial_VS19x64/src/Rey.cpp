#include "Rey.h"
#include"freeglut.h"
Rey::Rey(bool col, int f, int c)
{
	color = col;
	fila = f;
	columna = c;
 }

//Rey ::~Rey()
//{

//}
void Rey:: Dibuja()
{
	if (color== 1)
		//Imagen de pieza blanca
		glEnable(GL_TEXTURE_2D); //Falta modificar para poner la imagen
	else
		//Imagen de pieza negra
		glEnable(GL_TEXTURE_2D);//Falta modificar para poner la imagen del rey negro
}

bool Rey::mRey(float nx, float ny)
{
	//El rey se mueve uno para arriba
	if (ny == fila + 1)
		//El rey se mueve uno para arriba y uno a la izq, es decir,
		//diagonal
		if (nx == columna - 1)
			return true;
		else if (nx == columna + 1)//Diagonal derecha
			return true;
		else if (nx == columna)//No hay mov izq o der
			return true;
		else
			return false;

	//Lo mismo que la anterior pero hacia abajo
	else if (ny == fila - 1)
		//El rey se mueve uno para arriba y uno a la izq, es decir,
		//diagonal
		if (nx == columna - 1)
			return true;
		else if (nx == columna + 1)//Diagonal derecha
			return true;
		else if (nx == columna)//No hay mov izq o der
			return true;
		else
			return false;

	//Se queda en la misma posición
	else if (ny == fila)
		//Mov a la izquierda
		if (nx == columna - 1)
			return true;
		//Mov a la derecha
		else if (nx == columna + 1)
			return true;
		else
			return false;



}