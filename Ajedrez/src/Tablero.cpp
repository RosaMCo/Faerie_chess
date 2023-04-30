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

bool Tablero::selPieza(int forigen, int corigen) {//selección de pieza a mover [pasar como const?]
	auto& iden = id[forigen][corigen];//es muy largo de escribir, así que referencia/alias
	if (iden) {//comprobar puntero no nulo (casilla no vacía)
		if (iden->getColor() == turno) {//comprobar que coinciden el color de la pieza y el del turno
			return true;
		}
		return false;
	}
	return false;
}

bool Tablero::mover(int fdestino, int cdestino, int forigen, int corigen) {//selección de destino (una vez seleccionada pieza a mover)
	auto& destino = id[fdestino][cdestino];
	auto& origen = id[forigen][corigen];
	if (destino) {//casilla ocupada
		if (destino->getColor() != turno) {//comprobar pieza color distinto
			
			if (origen->comer(cdestino, fdestino)) {//llamar a comer de la pieza seleccionada
				//llamar a destructor de la pieza destino (delete)
				
				//realizar el movimiento
				origen->setPosicion(cdestino, fdestino);//actualizar posición de la pieza
				destino = origen;//copia de dir. de memoria para que apunten ambos a la misma pieza
				origen = 0;//casilla origen ahora vacía (no apunta a la pieza)
			}
			return false;
		}
		return false;
	}

	else {//casilla vacía
		if (origen->mover(cdestino, fdestino)) {//llamar a mover de la pieza seleccionada
			//realizar el movimiento
			origen->setPosicion(cdestino, fdestino);//actualizar posición de la pieza
			destino = origen;//copia de dir. de memoria para que apunten ambos a la misma pieza
			origen = 0;//casilla origen ahora vacía (no apunta a la pieza)
		}
		return false;
	}
	return false;
}

void Tablero::dibuja() {
	//dibujado tablero
	
	//llamada a dibujado piezas
}