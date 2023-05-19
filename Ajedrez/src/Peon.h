#pragma once
#include "Pieza.h"
class Peon :
    public Pieza //heredamos todas las variables y m�todos terrenales de Pieza (public mantiene los niveles de acceso)
{
private:
    bool mov_ini;//true si es el primer movimiento de la pieza en la partida
    bool movIniLargo;
public:
    Peon(Color col, int f, int c);
    bool mover(int nc, int nf);//true si el movimiento es permitido; nx y ny son los nuevos valores de x e y
    bool comer(int nc, int nf);
    //en-passant (forma especial de comer, si me apa�o)
    void dibuja(float ix, float iy);
    bool getMovIniLargo() { return movIniLargo; }
};

