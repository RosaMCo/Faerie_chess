#include "Tablero.h"

Tablero::Tablero() {
	for (int fila = 0; fila <= 7; fila++) {
		for (int columna = 0; columna <= 7; columna++) {
			casilla[fila][columna].setPosicion(fila*10.0f,columna*10.0f);
			id[fila][columna] = 0;//punteros nulos, no apuntan a nada
		}
	}

	turno = 0;
}

bool Tablero::selPieza(int forigen, int corigen) {
	auto& iden = id[forigen][corigen];//es muy largo de escribir, así que referencia/alias
	if (iden) {//comprobar puntero no nulo (casilla no vacía)
		if (iden->getColor() == turno) {
			return true;
		}
		return false;
	}
	return false;
}

bool Tablero::mover(int fdestino, int cdestino) {
	auto& destino = id[fdestino][cdestino];
	if (destino) {//casilla vacía
		//llamar a mover de la pieza seleccionada
	}

	else {//casilla ocupada
		//llamar a comer de la pieza seleccionada
	}
	return false;
}
