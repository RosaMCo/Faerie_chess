#include "Peon.h"

Peon::Peon(Color col, int f, int c) {
	setColor(col);
	setTipo(PEON);
	fila = f;
	columna = c;
	mov_ini = 1;
}

bool Peon::mover(int nx, int ny) {
	if (mov_ini == 1) {
		if (nx == columna && ny - fila <=2) {
			return true;
		}
		return false;
	}

	else {
		if (nx == columna && ny - fila == 1) {
			return true;
		}

		return false;
	}
	return false;
}

bool Peon::comer(int nx, int ny) {
	if ((nx - columna == 1 || nx - columna == -1) && (fila == 1 )) {
		return true;
	}
	return false;
}