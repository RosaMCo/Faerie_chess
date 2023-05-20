#pragma once
#include"Pieza.h"

class Alfil :public Pieza
{
public:

    Alfil(Color color, int fila, int columna);

    //true si el movimiento es permitido; nx y ny son los nuevos valores de x e y
    bool mover(int nc, int nf);
    void dibuja(float ix, float iy);
    bool comer(int nc, int nf) { return mover(nc, nf); }
    bool getMovIniLargo() { return 0; } //solo para poder usar su formato virtual en Pieza y para poder comer al paso en los peones
    bool getMovIni() { return 0; } //no usado, sólo para incluirlo en el virtual de Pieza y aplicarlo en el enroque
};
