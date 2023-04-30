#pragma once
#include "Vector2D.h"
#include "Pieza.h"

class Tablero
{
private:
	Vector2D casilla[8][8];
	Pieza* id[8][8];//puntero que contiene las direcciones de memoria de las piezas (para identificarlas)
	bool turno;//turno de blancas o negras (convención de pieza)
	
public:
	Tablero();
	bool selPieza(int forigen, int corigen);//fila y columna (casilla) de origen para seleccionar la pieza
	bool mover(int fdestino, int cdestino, int forigen, int corigen);//casilla destino para comprobar y realizar el movimiento
	void dibuja();
	//validar enroque
	//comer al paso
	
	// jaque
	//validar movimiento
	
	//Inicializar posición inicial
	//color, necesitamos sber qué color es la pieza con la que se trabaj dentro del ajedrez

	

};

