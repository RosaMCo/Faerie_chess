#include "Mundo.h"

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
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0, -5.0f);
	glVertex3f(-5.0f, 0, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0, 5.0f);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
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

bool Mundo::validarTurno(int color) {

	if (turno % 2 == 0 && color == 0) { return true; }		//Turno par -> piezas blancas
	else if (turno % 2 != 0 && color == 1) { return true; }	//Turno impar -> piezas negras
	else { return false; }

}

int Mundo::jugada(int button, int state, int x, int y)
{ //Implementación de una jugada
	return 0;
	/////////////////////////////////////////Funciones del ratón/////////////////////////////////////////////77
}