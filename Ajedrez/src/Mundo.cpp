#include "Mundo.h"

//Estado inicial del mundo
 
Mundo::Mundo()
{
	estado = Inicio;

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
	if (estado == Inicio) {											//Dibuja la pantalla de inicio
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);
		//Añadir fondo
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo2.png").id);
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

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 16);
		ETSIDI::printxy("Ajedrez", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/fuente2.otf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -L- PARA CARGAR LA ULTIMA PARTIDA GUARDADA", -5, 5);
	}
	
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=20;
}

void Mundo::tecla(unsigned char key)
{

}
