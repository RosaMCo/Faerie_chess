#include "Obelisco.h"

Obelisco::Obelisco(Color col, int f, int c) {
	setColor(col);
	setTipo(OBELISCO);
	fila = f;
	columna = c;
}

bool Obelisco::mover(int nc, int nf) {
	return false;
}

void Obelisco::dibuja(float ix, float iy) {

}