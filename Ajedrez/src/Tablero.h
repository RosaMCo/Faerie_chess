#pragma once
#include "Vector2D.h"
#include "Pieza.h"
#include "ETSIDI.h"
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
//enum Color {indefinido, blanco, negro};

class Tablero
{
private:
	Vector2D casilla[8][8];
	Pieza* id[8][8];//matriz de punteros que contienen las direcciones de memoria de las piezas (para identificarlas)
	Pieza* lista[32];//lista de piezas (puede o no contener punteros nulos), el máximo es el nº total de piezas permitidas (32)
	Color turno;//turno de blancas o negras 
	//int numBlancas;
	//int numNegras;
	int numero;
	
public:
	Tablero();
	//void eliminarPieza(int index);
	void eliminarPieza(int c, int f);
	bool selPieza(int forigen, int corigen);//fila y columna (casilla) de origen para seleccionar la pieza
	bool mover(int fdestino, int cdestino, int forigen, int corigen);//casilla destino para comprobar y realizar el movimiento
	void dibuja();
	Color getTurno() { return turno; }
	void setTurno(Color tur) {turno = tur;}
	//Pieza* getPieza(int c, int f) { return id[f][c]; }
	//validar enroque
	//comer al paso
	bool colorDistinto(Pieza& pieza, Pieza& pieza2);
	bool casillaVacia(int c, int f);
	bool piezaEnMedio(int fdestino, int cdestino, int forigen, int corigen);
	//void actualizarId(int fdestino, int cdestino, int forigen, int corigen);

	bool amenaza(Pieza& pieza); //true si pieza puede ser comida, no incluye comer al paso

	bool enroque(Pieza& torre, Pieza& rey, char tipo);
	//bool enroqueCorto(Pieza& torre, Pieza& rey);
	bool enroque(int fdestino, int cdestino, int forigen, int corigen);

	//bool jaque(Rey& rey);
	bool jaque(Color turno);
	bool jaqueMate(Rey& rey);

	bool comerAlPaso(int fdestino, int cdestino, int forigen, int corigen);

	bool actualizarId(int fdestino, int cdestino, int forigen, int corigen);
	void imprimirId(int i, int j);
	void imprimirLista(int i, int j);
	void imprimirLista();
	void imprimirTurno();
	void imprimirTipo(Tipo tip);
	void imprimirColor(Color col);
	void comprobarAsignaciones();

};

