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
#include"Regente.h"
#include "Cortesana.h"
#include "Campesino.h"
#include "Obelisco.h"

//enum Color {indefinido, blanco, negro};
enum Intercambio {
	NADA, PEON_CAMPESINO_B, PEON_CAMPESINO_N, TORRE_OBELISCO_B, TORRE_OBELISCO_N,
	ALFIL_CORTESANA_B, ALFIL_CORTESANA_N, REY_REGENTE_B, REY_REGENTE_N
};

class Tablero
{
private:
	Vector2D casilla[8][8];
	Pieza* id[8][8];//matriz de punteros que contienen las direcciones de memoria de las piezas (para identificarlas)
	Pieza* lista[32];//lista de piezas (puede o no contener punteros nulos), el máximo es el nº total de piezas permitidas (32)
	Color turno;//turno de blancas o negras 
	int numero;
	Pieza* _id[8][8]; //copia de la id para poder anticiparse a movimientos
	char estado_jaque;//para informar a mundo (y por tanto al coordinador) de si hay jaque, jaque mate o nada
	
public:
	Tablero();
	//void eliminarPieza(int index);
	void eliminarPieza(int c, int f);
	bool selPieza(int forigen, int corigen);//fila y columna (casilla) de origen para seleccionar la pieza
	bool mover(int fdestino, int cdestino, int forigen, int corigen);//casilla destino para comprobar y realizar el movimiento
	void dibuja();
	Color getTurno() { return turno; }
	void setTurno(Color tur) {turno = tur;}
	char getEstadoJaque() { return estado_jaque; }
	//Pieza* getPieza(int c, int f) { return id[f][c]; }
	//validar enroque
	//comer al paso
	bool colorDistinto(Pieza& pieza, Pieza& pieza2);
	bool casillaVacia(int c, int f,int NoJaqueMate=1);
	bool piezaEnMedio(int fdestino, int cdestino, int forigen, int corigen, int NojaqueMate = 1);
	//void actualizarId(int fdestino, int cdestino, int forigen, int corigen);

	bool amenaza(Pieza& pieza, int NojaqueMate = 1); //true si pieza puede ser comida, no incluye comer al paso

	bool enroque(Pieza& torre, Pieza& rey, char tipo);
	bool enroque(int fdestino, int cdestino, int forigen, int corigen);

	//bool jaque(Rey& rey);
	Pieza* jaque(Color turn);
	char jaqueMate(Color turn);

	bool comerAlPaso(int fdestino, int cdestino, int forigen, int corigen);
	void validarPromocion();//se encarga de llamar a la función de promoción del peón si se validan las condiciones
	void promocionPeon(int fpieza, int cpieza, int nlista, Color color);//se graduan las piezas antes que nosotros ;_;
	void intercambioPieza(Intercambio tipo);

	bool actualizarId(int fdestino, int cdestino, int forigen, int corigen,int impedirJaque=0);
	void imprimirId(int i, int j,int NojaqueMate=1);
	void imprimirLista(int i, int j);
	void imprimirLista();
	void imprimirTurno();
	void imprimirTipo(Tipo tip);
	void imprimirColor(Color col);
	void comprobarAsignaciones();
	Pieza* dameCopiaId(int c, int f);

};

