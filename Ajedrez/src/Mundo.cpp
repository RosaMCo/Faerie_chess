#include "Mundo.h"
#include <math.h>
#include <iostream>

//Estado inicial del mundo
 
Mundo::Mundo()
{
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;

}
/*void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
void Mundo::dibuja()
{
	//Aquí va el juego del ajedrez clásico

	gluLookAt(0, 7.5, 30,  // posicion del ojo
		0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
	tablero.dibuja();
//dibujo del suelo
	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0, -5.0f);
	glVertex3f(-5.0f, 0, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);*/
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{

}

/*
Casilla Mundo::getCasilla(int x, int y) { //Devuelve la casilla en función de las coordenadas x,y del ratón
	Casilla casilla;
	casilla.c = floor((x - 125) / 69);		//Obtenido experimentalmente para el tamaño de ventana del juego
	casilla.f = 7 - floor((y - 25) / 69);	//Si se cambia el tamaño de ventana, esto no vale
	return casilla;
}
*/

/*bool Mundo::validarTurno(int color) {

	if (turno == 0 && color == 0) { return true; }		//Turno par -> piezas blancas
	else if (turno % 2 != 0 && color == 1) { return true; }	//Turno impar -> piezas negras
	else { return false; }

}*/
/*bool Mundo::validarTurno(Color turn) {

	if (tablero.getTurno() == blanco && turn == blanco) { return true; }		//Turno par -> piezas blancas
	else if (tablero.getTurno() == negro && turn == negro) { return true; }	//Turno impar -> piezas negras
	else { return false; }

}*/


int* Mundo::SeleccionarFicha(int button, int state, int x, int y)
{//Implementación de una jugada
		//NO BORRAR COSAS EN PRUEBAS
	std::cout << "\tEntro en mundo::seleccionar ficha" << "\n";
	//std::cout << "En mundo, el turno es: ";
	//tablero.imprimirTurno();
	int window_height = glutGet(GLUT_WINDOW_HEIGHT) * 0.92; //cantidad de pixeles de alto 
	int window_width = glutGet(GLUT_WINDOW_WIDTH) * 0.7; //cantidad de pixeles de ancho

	float range_height = window_height / 8; //8 es el numero de filas
	float range_width = window_width / 8;

	int calculate_fila = (y - glutGet(GLUT_WINDOW_HEIGHT) * 0.04) / range_height;
	int calculate_columna = (x - glutGet(GLUT_WINDOW_WIDTH) * 0.15) / range_width;



	int* position = new int[2];

	if (tablero.selPieza(calculate_fila, calculate_columna)) {

		position[0] = 7 - calculate_fila;
		position[1] = calculate_columna;
		std::cout << "Seleccionada la pieza de c="<<position[0]+1<<" y f="<<position[1]+1 << "\n";

		return position;
	}
	
	else {
		std::cout << "Pero no reconozco seleccion" << "\n";
		return NULL;
	}

}
void Mundo::cambiaTurno()
{
	if (tablero.getTurno() == blanco)
	{
		tablero.setTurno(negro);
	}
	else tablero.setTurno(blanco);
	//std::cout << "desde Mundo, turno cambiado a: "; tablero.imprimirTurno();
}

int Mundo::jaque()
{
	return tablero.jaque(tablero.getTurno());
}

int* Mundo::ValidarClick( int x, int y)
{ 
	//NO BORRAR COSAS EN PRUEBAS
	/*std::cout << "coordenada x : " << x << "coordenada y : " << y << "\n";
	std::cout << glutGet(GLUT_WINDOW_HEIGHT) * 0.92 << " maximo de altura\n";
	std::cout << glutGet(GLUT_WINDOW_WIDTH) * 0.7 << " maximo de ancho\n";*/

	int window_height = glutGet(GLUT_WINDOW_HEIGHT) * 0.92; //cantidad de pixeles de alto 
	int window_width = glutGet(GLUT_WINDOW_WIDTH) * 0.7; //cantidad de pixeles de ancho

	float range_height = window_height / 8; //8 es el numero de filas
	float range_width = window_width / 8;

	int calculate_fila = (y - glutGet(GLUT_WINDOW_HEIGHT) * 0.04) / range_height;
	int calculate_columna = (x - glutGet(GLUT_WINDOW_WIDTH) * 0.15) / range_width;

	int* position=new int [2];

	position[0] = 7-calculate_fila;
	position[1] = calculate_columna;

	return position;

}