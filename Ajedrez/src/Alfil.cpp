#include "Alfil.h"
#include"freeglut.h"


//Para las piezas de tipo alfil, torre y reina, quiza fuera más conveniente sacar la posición actual(con fila y columna)
//y la posición a la que se desea mover (Quiza haciendo uso del raton) para sacar la casilla de destino

Alfil::Alfil(Color col, int f, int c) {
	setColor(col);
	setTipo(ALFIL);
	fila = f;
	columna = c;
}

bool Alfil::mover(int nx, int ny) {
	//El afil se mueve hacia arriba 
	
	if (ny - fila <= 7) {
		//Se mueve hacia la derecha
		if(nx - columna<=7)
			return true;
		//Se mueve hacia la izquierda 
		if (nx + columna <= 7)
			return true;
	}

	//El alfil se mueve hacia abajo
	else if (ny + fila <= 7) {
		//Se mueve hacia la derecha
		if (nx - columna <= 7)
			return true;
		//Se mueve hacia la izquierda 
		if (nx + columna <= 7)
			return true;
	}

	//falta comprobar que en caso de que la casilla final sea la misma que otra ficha, comemos esa ficha 
	else return false;
}
