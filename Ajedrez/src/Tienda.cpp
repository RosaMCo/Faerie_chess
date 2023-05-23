#include "Tienda.h"

Tienda::Tienda()
{
	puntos_blanco = 10;
	puntos_negro = 10;
	comprador = NO_SEL;
}
void Tienda::inicializa()
{

}

void Tienda::dibuja()
{
	gluLookAt(0, 7.5, 30, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0) 
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y) 

	//A�adir fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo4.png").id);
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


	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("TIENDA", -5, 12);
	ETSIDI::setTextColor(0, 1, 1);//graphic design is my passion
	ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 14);
	ETSIDI::printxy("Bienvenido/a a la tienda", -5, 10);
	if (comprador==NO_SEL) {
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("�Eres blanco o negro?", -5, 9);
		ETSIDI::printxy("-1- Blanco		-2- Negro", -5, 8);
	}
	else {
		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("bin/fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("Elige la pieza que quieres sustituir ", -5, 9);
		ETSIDI::printxy("(mira la consola para ver tus puntos)", -5, 8);
		ETSIDI::printxy("-1- Peon	-2- Torre	-3- Alfil	-4- Rey", -5, 7);
		
	}
	ETSIDI::printxy("CHESS WINX", 2, 1);
}

void Tienda::compra(int precio)
{
	if (comprador == BLANCO) {
		if (puntos_blanco >= precio) {
			puntos_blanco -= precio;
			std::cout << "Puntos blanco: " << puntos_blanco << std::endl;
		}
		else {
			std::cout << "No tienes dinero para comprar eso!" << std::endl;
		}
	}
	else if (comprador == NEGRO) {
		if (puntos_negro >= precio) {
			puntos_negro -= precio;
			std::cout << "Puntos negro: " << puntos_negro << std::endl;
		}
		else {
			std::cout << "No tienes dinero para comprar eso!" << std::endl;
		}
	}
}

void Tienda::tecla(unsigned char key) {
	if (comprador==NO_SEL) {
		switch (key) {
		case '1':
			comprador = BLANCO;
			std::cout << "Puntos blanco: " << puntos_blanco << std::endl;
			break;
		case '2':
			comprador = NEGRO;
			std::cout << "Puntos negro: " << puntos_negro << std::endl;
			break;
		}
	}
	else {
		switch (key) {
		case '1':
			compra(2);
			break;
		case '2':
			compra(3);
			break;
		case '3':
			compra(3);
			break;
		case '4':
			compra(5);
			break;
		case 'c':
			comprador = NO_SEL;
			break;
		}
		
	}
	
}