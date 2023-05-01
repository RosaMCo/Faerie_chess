#include "Tablero.h"

Tablero::Tablero() {
	for (int fila = 0; fila <= 7; fila++) {
		for (int columna = 0; columna <= 7; columna++) {
			casilla[fila][columna].setPosicion(fila*10.0f,columna*10.0f);//valores aleatorios de las casillas, cambiar a los concretos
			id[fila][columna] = 0;//punteros nulos, no apuntan a nada
		}
	}

	for (int i = 0; i < 32; i++) {
		lista[i] = 0;
	}

	turno = (Color)blanco;//inician blancas
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
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fichas/tablero.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-10, -2.5);
	glTexCoord2d(1, 1); glVertex2f(10, -2.5);
	glTexCoord2d(1, 0); glVertex2f(10, 17.5);
	glTexCoord2d(0, 0); glVertex2f(-10, 17.5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//llamada a dibujado piezas
	for (int i = 0; i < 32; i++) {
		int tempf, tempc;
		if (lista[i]) {//no llamar a dibujado si puntero vacío
			//var. temporales para pasar las coordenadas correspondientes a la pieza
			tempf = lista[i]->getFila();
			tempc = lista[i]->getColumna();
			//pasamos las coordenadas correspondientes a la pieza para que se dibuje
			lista[i]->dibuja(casilla[tempf][tempc].getX(), casilla[tempf][tempc].getY());
		}
	}
}