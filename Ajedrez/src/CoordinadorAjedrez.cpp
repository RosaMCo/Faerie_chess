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
	else if(estado == JAQUEBLANCO)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("JAQUE AL REY BLANCO!!!", -5, 8);

	}
	else if (estado == JAQUENEGRO)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("JAQUE AL REY NEGRO!!!", -5, 8);

	}
	else if (estado == GAMEOVER)
	{
		Color col = mundo.getTurno();
		mundo.dibuja();
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
		switch (col)
		{
		case indefinido:
			break;
		case blanco:
			ETSIDI::printxy("PIERDEN LAS BLANCAS", -3, 8);
			ETSIDI::printxy("ENHORABUENA, JUGADOR NEGRO, HAS GANADO!!!!", -8, 5);
			break;
		case negro:
			ETSIDI::printxy("PIERDEN LAS NEGRAS", -3, 8);
			ETSIDI::printxy("ENHORABUENA, JUGADOR BLANCO, HAS GANADO!!!!", -8, 5);
			break;
		default:
			break;
		}
		ETSIDI::printxy("PULSA -C- PARA CONTINUAR", -5, 3);
		//estado = FIN;
	}
	
	else if (estado == TIENDA)
	{
		tienda.dibuja();
	}
	else if (estado == REGLAS)
	{
		

		

		
	}
}
void CoordinadorAjedrez::cambiaTurno()
{
	mundo.cambiaTurno();
}

void CoordinadorAjedrez::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == '1')
		{
			mundo.inicializa();
			estado = JUEGO;
			cursor = 1;
		}

		else if (key == '2')
		{
			estado = TIENDA;
			cursor = 1;
			if (key == 'c')
				estado = INICIO;
		}
		else if (key == '3')
		{
			reglas.Inicializa();

			estado = REGLAS;
			if (key == 'c')
				estado = INICIO;

		}

		else if (key == '4')
		{
			exit(0);
		}

	}
	else if (estado == JUEGO) {
		mundo.tecla(key);
	}
	else if (estado == TIENDA) {
		mundo.intercambio(tienda.tecla(key));
		if (key == 'c') estado = INICIO;
	}
	else if (estado == GAMEOVER)
	{
		mundo.inicializa();
		JaqueBlanco = JaqueNegro = 0;
		
		if (key == 'c')
			estado = INICIO;
		
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
				//std::cout << "Seleccion de cursor: c=" << ficha_sel[1]+1 << " f=" << ficha_sel[0]+1 << "\n";
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
			if (mundo.tablero.casillaVacia(ficha_selecionada[1], ficha_selecionada[0]))
			{
				ficha_selecionada = NULL;
				action_click = false;
				std::cout << "\nNo hay ninguna pieza en esta casilla. REALICE UNA SELECCION VALIDA:" << "\n";
			}
				
			else
			{
				std::cout << "Voy a mover:" << "\n";
				mundo.tablero.imprimirId(ficha_selecionada[1], ficha_selecionada[0]);
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
		if (mundo.jaque() == 'J')
		{
			mundo.getTurno();
			if (mundo.getTurno() == blanco)
			{
				estado = JAQUEBLANCO;
				JaqueBlanco = true;
			}
			else if (mundo.getTurno() == negro)
			{
				estado = JAQUENEGRO;
				JaqueNegro = true;
			}

		}
		else if (mundo.jaque() == 'M')
		{
			mundo.getTurno();
			estado = GAMEOVER;
			JaqueNegro = JaqueBlanco = false;

		}
		else estado = JUEGO;

	}
	else if (estado == JAQUEBLANCO || estado == JAQUENEGRO)
	{
		if (mundo.jaque()=='N')
		{
			JaqueNegro = false;
			JaqueBlanco = false;
			estado = JUEGO;
		}
	}
		
}

