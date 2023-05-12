#include "Tablero.h"

Tablero::Tablero() {
	for (int fila = 0; fila <= 7; fila++) {
		for (int columna = 0; columna <= 7; columna++) {
			casilla[fila][columna].setPosicion(columna * 20.0/8 - 10, fila * 20.0/8 - 2.5);//valores aleatorios de las casillas, cambiar a los concretos
			id[fila][columna] = 0;//punteros nulos, no apuntan a nada
		}
	}

	for (int i = 0; i < 32; i++) {
		lista[i] = 0;
	}

	//los números mágicos son offsets para colocar las piezas en el tablero
	for (int i = 0; i < 16; i++) {//creación de peones

		if (i < 8) {//blancos
			Peon* p = new Peon(blanco, 1, i);//fila 1, todas las columnas
			lista[i] = p;
			id[1][i] = lista[i];

		}

		else {//negros
			Peon* p = new Peon(negro, 6, i - 8);//fila 6, todas las columnas (-8 porque i empieza en 8 y las columnas en 0)
			lista[i] = p;
			id[6][i - 8] = lista[i - 8];
		}
	}

	for (int i = 16; i < 20; i++) {//creación de torres
		if (i < 18) {//blancas
			Torre* t = new Torre(blanco, 0, (i - 16) * 7);//fila 0, columnas 0 y 7
			lista[i] = t;
			id[0][(i - 16) * 7];
		}
		else {//negras
			Torre* t = new Torre(negro, 7, (i - 18) * 7);//fila 7, columnas 0 y 7
			lista[i] = t;
			id[7][(i - 18) * 7];
		}
	}

	for (int i = 20; i < 24; i++) {//creación de caballos
		if (i < 22) {//blancos
			Caballo* c = new Caballo(blanco, 0, (i - 20) * 5 + 1);//fila 0,  columnas 1 y 6
			lista[i] = c;
			id[0][(i - 20) * 5 + 1];
		}

		else {
			Caballo* c = new Caballo(negro, 7, (i - 22) * 5 + 1);//fila 7, columnas 1 y 6
			lista[i] = c;//negros
			id[0][(i - 22) * 5 + 1];
		}
	}

	for (int i = 24; i < 28; i++) {//creación de alfiles
		if (i < 26) {//blancos
			Alfil* a = new Alfil(blanco, 0, (i - 24) * 3 + 2);
			lista[i] = a;
			id[0][(i - 24) * 3 + 2];
		}

		else {//negros
			Alfil* a = new Alfil(negro, 7, (i - 26) * 3 + 2);
			lista[i] = a;
			id[0][(i - 26) * 3 + 2];
		}
	
	}

	for (int i = 28; i < 30; i++) {
		if (i < 29) {
			Reina* r = new Reina(blanco, 0, i - 25);
			lista[i] = r;
			id[0][i - 25];
		}
		else {
			Reina* r = new Reina(negro, 7, i - 26);
			lista[i] = r;
			id[7][i - 26];
		}
	}

	for (int i = 30; i < 32; i++) {
		if (i < 31) {
			Rey* r = new Rey(blanco, 0, i - 26);
			lista[i] = r;
			id[0][i - 26];
		}

		else {
			Rey* r = new Rey(negro, 7, i - 27);
			lista[i] = r;
			id[7][i - 27];
		}
		
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