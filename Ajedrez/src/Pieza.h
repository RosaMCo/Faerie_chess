#pragma once
#include "Vector2D.h"
enum Color {indefinido, blanco, negro};
enum Tipo { PEON, TORRE, ALFIL, CABALLO, REINA, REY, INDEFINIDO };
class Pieza
{
protected:
	//Posición en el tablero (matriz)
	int fila;
	int columna;
	//Movimientos
	bool next;
	bool ocupada;
	//Colores
	Color color;//1 para blancas, 0 para negras
	Tipo tipo;


public:
	//Constructor y destructor 
	Pieza();
	virtual ~Pieza();
	//Dibujar pieza
	void Dibuja();
	bool getColor() { return color; }
	//set
	void setPosicion(int nx, int ny);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
	void setNext();
	void setColor(Color c);
	void setTipo(Tipo t);
	//get
	int getPosicionX();
	int getPosicionY();
	bool getOcupado();
	bool getNext();
	//mover y comer virtuales
	//revisar si está bien hecho
	virtual bool mover(int nx, int ny) = 0;
	virtual bool comer(int nx, int ny) = 0;

};

