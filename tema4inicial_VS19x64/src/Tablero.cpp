#include "Tablero.h"

Tablero::Tablero() {
	for (int fila = 0; fila <= 7; fila++) {
		for (int columna = 0; columna <= 7; columna++) {
			casilla[fila][columna].setPosicion(fila*10.0f,columna*10.0f);
			ocupado[fila][columna] = 0;
		}
	}
}

