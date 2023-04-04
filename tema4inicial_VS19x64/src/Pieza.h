#pragma once


class Pieza
{
private:
	//Posición
	float x;
	float y;
	//Movimientos
	bool next;
	bool ocupada;
	//Colores
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	int tipo;
public:
	Pieza();
	Pieza(int _x, int _y, bool blanco);//Constructor de peones
	Pieza(int _x, int _y, int _tipo, bool blanco);
	//virtual ~Pieza();
	void Dibuja();

	//set
	void setPosicion(float ix, float iy);
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void toggleOcupado(); //Cambia si la casilla del tablero está ocupada o no.
	void setNext();
	void setColor();


	//
	int getColor();
	int getPosicion();
	bool getOcupado();
	bool getNext();



};

