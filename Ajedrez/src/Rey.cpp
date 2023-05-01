#include "Rey.h"
#include"freeglut.h"
Rey::Rey(Color col, int f, int c)
{
	setColor(col);
	setTipo(REY);
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

bool Rey::mRey(float nf, float nc)
{
	//El rey se mueve uno para arriba
	if (nc == fila + 1)
		//El rey se mueve uno para arriba y uno a la izq, es decir,
		//diagonal
		if (nf == columna - 1)
			return true;
		else if (nf == columna + 1)//Diagonal derecha
			return true;
		else if (nf == columna)//No hay mov izq o der
			return true;
		else
			return false;

	//Lo mismo que la anterior pero hacia abajo
	else if (nc == fila - 1)
		//El rey se mueve uno para arriba y uno a la izq, es decir,
		//diagonal
		if (nf == columna - 1)
			return true;
		else if (nf == columna + 1)//Diagonal derecha
			return true;
		else if (nf == columna)//No hay mov izq o der
			return true;
		else
			return false;

	//Se queda en la misma posición
	else if (nc == fila)
		//Mov a la izquierda
		if (nf == columna - 1)
			return true;
		//Mov a la derecha
		else if (nf == columna + 1)
			return true;
		else
			return false;



}