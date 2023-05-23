#pragma once
#include "Pieza.h"
class Obelisco :
    public Pieza
{
    Obelisco(Color col, int f, int c);
    bool mover(int nc, int nf);//true si el movimiento es permitido; nx y ny son los nuevos valores de x e y
    bool comer(int nc, int nf) { return mover(nc, nf); }
    void dibuja(float ix, float iy);
};

