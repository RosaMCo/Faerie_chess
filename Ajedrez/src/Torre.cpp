#include "Torre.h"
#include"freeglut.h"

Torre::Torre(Color col, int f, int c) {
	setColor(col);
	setTipo(TORRE);
	fila = f;
	columna = c;
}

bool Torre::mover(int nx, int ny) {
	//Movimiento arriba 
	if (nx == columna && ny - fila <= 7) {
		return true;
	}

	//Movimiento abajo 
	else if (nx == columna && ny + fila <= 7) {
		return true;
	}

	//Movimiento derecha
	else if (nx - columna <= 7 && ny == fila) {
		return true;
	}

	//Movimiento izquierda 
	else if (nx + columna <= 7 && ny == fila) {
		return true;
	}

	else return false;

	//falta comprobar que en caso de que la casilla final sea la misma que otra ficha, comemos esa ficha 
}