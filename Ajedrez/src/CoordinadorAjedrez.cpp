#include "CoordinadorAjedrez.h"
#include "ETSIDI.h"
using namespace ETSIDI;
CoordinadorAjedrez::CoordinadorAjedrez()
{
	estado = INICIO;
}

void CoordinadorAjedrez::dibuja()
{
	if (estado == INICIO)
	{
											//Dibuja la pantalla de inicio
			
			gluLookAt(0, 7.5, 30, // posicion del ojo
				0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
				0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

			//Añadir fondo
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/FONDO.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex2f(-10, 0);
			glTexCoord2d(1, 1); glVertex2f(10, 0);
			glTexCoord2d(1, 0); glVertex2f(10, 15);
			glTexCoord2d(0, 0); glVertex2f(-10, 15);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			//Hay que mirar lo de las letras
			
			setTextColor(1, 1, 0);
			setFont("fuentes/Bitwise.ttf", 16);
			printxy("EL AJEDREZ", -5, 8);
			setTextColor(1, 1, 1);
			setFont("fuentes/Bitwise.ttf", 12);
			printxy("PULSE LA TECLA -1- PARA EMPEZAR", -5, 7);
			printxy("PULSE LA TECLA -2- PARA TIENDA", -5, 6);
			printxy("PULSE LA TECLA -3- PARA REGLAS", -5, 5);
			printxy("PULSE LA TECLA -4- PARA SALIR", -5, 4);
			printxy("CHESS WINX", 2, 1);
		
	}
	else if (estado == JUEGO)
	{
		mundo.dibuja();
	}
	else if (estado == TIENDA)
	{
		tienda.dibuja();
	}
	else if (estado == REGLAS)
	{
		//PONER INSTRUCCIONES EN UN TXT?
	}
}

void CoordinadorAjedrez::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (estado == INICIO)
		{
			if (key == '1')
			{
				mundo.inicializa();
				estado = JUEGO;
			}

			else if (key == '2')
			{
				tienda.inicializa();
				estado = TIENDA;
			}

			else if (key == '4')
			{
				exit(0);
			}
			
		}
		else if (estado == JUEGO)
		{
			mundo.tecla(key);
		}
		else if (estado == GAMEOVER)
		{
			if (key == 'c')
				estado = INICIO;
		}
		else if (estado == FIN)
		{
			if (key == 'c')
				estado = INICIO;
		}
	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
	}
}

void CoordinadorAjedrez::teclaEspecial(unsigned char key) //Moverse por el menu presionando una tecla
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}
void CoordinadorAjedrez::mueve()
{
	if (estado == JUEGO)
		mundo.mueve();
}

