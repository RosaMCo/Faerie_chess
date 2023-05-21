#pragma once
#include"Pieza.h"
#include<iostream>

class Campesino: public Pieza
{
private:
    bool mov_ini;//true si es el primer movimiento de la pieza en la partida
    bool movIniLargo;
public:
	Campesino(Color col, int f, int c);
    bool mover(int nc, int nf);
    void dibuja(float ix, float iy);
    bool comer(int nc, int nf);
    bool getMovIniLargo() { return 0; } //solo para poder usar su formato virtual en Pieza y para poder comer al paso en los peones
    bool getMovIni() { return 0; } //no usado, sólo para incluirlo en el virtual de Pieza y aplicarlo en el enroque
    void setMovIni(bool nuevo) {} //no usado, sólo para incluirlo en el virtual de Pieza y aplicarlo en el enroque
};

