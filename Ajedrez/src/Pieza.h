#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
enum Color {indefinido,blanco,negro};
enum Tipo { PEON, TORRE, ALFIL, CABALLO, REINA, REY, INDEFINIDO, CAMPESINO };
class Pieza
{
protected:
	//Posición en el tablero (matriz)
	int fila;
	int columna;
	//Movimientos
	//bool next;
	//bool ocupada;
	//Colores
	//Color color;
	Color color;
	Tipo tipo;
	Vector2D posicion;


public:
	//Constructor y destructor 
	Pieza();
	virtual ~Pieza();
	//Dibujar pieza
	virtual void dibuja(float ix, float iy) = 0;
	//set
	void setPosicion(int nx, int ny);
	void toggleOcupado() {}; //Cambia si la casilla del tablero está ocupada o no.
	void setNext() {};
	void setColor(Color c);//poner inline
	void setTipo(Tipo t);//poner inline
	//get
	Color getColor() { return color; }
	Tipo getTipo() { return tipo; }
	int getFila() { return fila; }
	int getColumna() { return columna; }
	//bool getOcupado();
	//bool getNext();
	//mover y comer virtuales
	//revisar si está bien hecho
	virtual bool mover(int nx, int ny) = 0;
	virtual bool comer(int nx, int ny) = 0;
	virtual bool getMovIniLargo() = 0;
	virtual bool getMovIni() = 0;
	virtual void setMovIni(bool nuevo) = 0;

};

