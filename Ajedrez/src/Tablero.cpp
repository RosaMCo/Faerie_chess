#include "Tablero.h"

Tablero::Tablero() {
	for (int fila = 0; fila <= 7; fila++) {
		for (int columna = 0; columna <= 7; columna++) {
			casilla[fila][columna].setPosicion(fila*10.0f,columna*10.0f);//valores aleatorios de las casillas, cambiar a los concretos
			id[fila][columna] = 0;//punteros nulos, no apuntan a nada
		}
	}

	turno = 1;//inician blancas
}

bool Tablero::selPieza(int forigen, int corigen) {//selección de pieza a mover
	auto& iden = id[forigen][corigen];//es muy largo de escribir, así que referencia/alias
	if (iden) {//comprobar puntero no nulo (casilla no vacía)
		if (iden->getColor() == turno) {//comprobar que coinciden el color de la pieza y el del turno
			return true;
		}
		return false;
	}
	return false;
}

bool Tablero::mover(int fdestino, int cdestino) {//selección de destino (una vez seleccionada pieza a mover)
	auto& destino = id[fdestino][cdestino];
	if (destino) {//casilla vacía
		//llamar a mover de la pieza seleccionada
	}

	else {//casilla ocupada
		//llamar a comer de la pieza seleccionada
	}
	return false;
}
