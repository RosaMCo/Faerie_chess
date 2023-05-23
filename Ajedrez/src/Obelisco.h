#pragma once
#include "Pieza.h"
class Obelisco :
    public Pieza
{
private:
    bool movIni;
public:
    Obelisco(Color col, int f, int c);
    bool mover(int nc, int nf);//true si el movimiento es permitido; nx y ny son los nuevos valores de x e y
    bool comer(int nc, int nf) { return mover(nc, nf); }
    void dibuja(float ix, float iy);
    bool getMovIni() { return movIni; }
    void setMovIni(bool nuevo) { movIni = nuevo; }
    bool getMovIniLargo() { return 0; } //solo para poder usar su formato virtual en Pieza y para poder comer al paso en los peones
};

