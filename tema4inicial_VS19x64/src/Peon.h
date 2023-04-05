#pragma once
#include "Pieza.h"
class Peon :
    public Pieza //heredamos todas las variables y métodos terrenales de Pieza (public mantiene los niveles de acceso)
{
private:
    bool mov_ini;//true si es el primer movimiento de la pieza en la partida
public:
    //movimiento (comprobar si primer mov. pieza)
    bool moverPeon();//true si el movimiento es permitido
    //comer (diagonal)
    bool comerPeon();//llamada por mover, true si se puede comer
    //en-passant (forma especial de comer, si me apaño)
};

