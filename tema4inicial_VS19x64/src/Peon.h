#pragma once
#include "Pieza.h"
class Peon :
    public Pieza //heredamos todas las variables y métodos terrenales de Pieza (public mantiene los niveles de acceso)
{
private:
    bool mov_ini;//true si es el primer movimiento de la pieza en la partida
public:
    //movimiento (comprobar si primer mov. pieza)
    bool moverPeon(float nx, float ny);//true si el movimiento es permitido; nx y ny son los nuevos valores de x e y
    //comer (diagonal)
    bool comerPeon(float nx, float ny);//true si se puede comer
    //en-passant (forma especial de comer, si me apaño)
};

