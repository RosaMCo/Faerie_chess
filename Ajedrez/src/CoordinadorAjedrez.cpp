#include "CoordinadorAjedrez.h"
#include "ETSIDI.h"
#include <iostream>
#include "Tablero.h"
#include "Mundo.h"

using namespace ETSIDI;
bool action_click = false; //Esta variable indica en false si estamos selecionando una pieza, en true si estamos moviendo una pieza
int* ficha_selecionada = NULL; 

CoordinadorAjedrez::CoordinadorAjedrez()
{
	estado = INICIO;
	cursor = 0;
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
			setFont("bin/fuentes/Bitwise.ttf", 16);
			printxy("EL AJEDREZ", -5, 8);
			setTextColor(1, 1, 1);
			setFont("bin/fuentes/Bitwise.ttf", 12);
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
void CoordinadorAjedrez::cambiaTurno()
{
	mundo.cambiaTurno();
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
				cursor = 1;
			}

			else if (key == '2')
			{
				tienda.inicializa();
				estado = TIENDA;
				cursor = 1;
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

void CoordinadorAjedrez::jugada(int button, int state, int x, int y)
{
	if (cursor == 1) {
		//std::cout << "turno en coordinador: ";
		//mundo.tablero.imprimirTurno();
		if (action_click == false) {//al ser false estamos seleccionando ficha 
			int* ficha_sel = mundo.SeleccionarFicha(button, state, x, y);
			if (ficha_sel) {
				//std::cout << "mover ficha;sel" << ficha_sel[0] << "\n";
				//std::cout << "mover ficha;sel" << ficha_sel[1] << "\n";
				std::cout << "Seleccion de cursor: c=" << ficha_sel[0]+1 << " f=" << ficha_sel[1]+1 << "\n";
				action_click = true;
				ficha_selecionada = ficha_sel;
			}
			else
			{
				std::cout << "Ninguna ficha seleccionada\n\n";
				ficha_selecionada = NULL;
				action_click = false;
			}

		}

		else { //moviendo ficha 
			//std::cout << "mover ficha;" << ficha_selecionada[0] << "\n";
			//std::cout << "mover ficha;" << ficha_selecionada[1] << "\n";
			int* movimiento = mundo.ValidarClick(x, y);
			//std::cout << "mover ficha;movimiento" << movimiento[0] << "\n";
			//std::cout << "mover ficha;movimiento" << movimiento[1] << "\n";
			std::cout << "Voy a mover:"<< "\n";
			mundo.tablero.imprimirId(ficha_selecionada[0], ficha_selecionada[1]);
			std::cout << "\nAl destino:" << "\n";
			mundo.tablero.imprimirId(movimiento[1], movimiento[0]);
			if (mundo.tablero.mover(movimiento[0], movimiento[1], ficha_selecionada[0], ficha_selecionada[1]))
			{
				//std::cout << "Desde Coordinador he movido y voy a cambiar el turno:" << "\n";
				mundo.cambiaTurno();
			}
			ficha_selecionada = NULL;
			action_click = false;
		}
	}
	//mundo.cambiaTurno();


	

/*/if (estado == JUEGO) {
		mundo.SeleccionarFicha(button, state, x, y);
	}if (estado == JAQUE0 || estado == JAQUE1) {
		mundo.SeleccionarFicha(button, state, x, y);
	}*/
}

void CoordinadorAjedrez::jaque()
{
	//Si estamos jugando a la partida de ajedrez
	if (estado == JUEGO)
	{
		if (mundo.jaque() == 1)
		{
			estado == JAQUEBLANCO;
			JaqueBlanco = true;
		}
		else if (mundo.jaque() == 2)
		{
			estado = JAQUEBLANCO;
			JaqueNegro = true;
		}
		else if (mundo.jaque() == 3 || mundo.jaque() == 4)
		{
			estado = FIN;
		}
		
	}
	//Cuando deja de haber jaque entonces se reanuda el juego
	else if (estado == JAQUEBLANCO || estado == JAQUENEGRO)
	{
		if (mundo.jaque() == 0)
		{
			JaqueBlanco = false;
			JaqueNegro = false;
			estado = JUEGO;
		}
	}
}

