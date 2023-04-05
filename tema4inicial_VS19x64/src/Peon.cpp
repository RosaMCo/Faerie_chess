#include "Peon.h"

bool Peon::moverPeon(float nx, float ny) {
	if (mov_ini == 0) {
		if (nx == posicion.getX() && ny - posicion.getY() <= 2 * 10.0f) {
			return true;
		}
		return false;
	}

	else {
		if (nx == posicion.getX() && ny - posicion.getY() == 1 * 10.0f) {
			return true;
		}

		return false;
	}
	return false;
}

bool Peon::comerPeon(float nx, float ny) {
	if ((nx - posicion.getX() == 1 * 10.0f || nx - posicion.getX() == -1 * 10.0f) && (posicion.getY() == 1 * 10.0f)) {
		return true;
	}
	return false;
}