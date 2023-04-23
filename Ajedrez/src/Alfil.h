#pragma once
#include"Pieza.h"

class Alfil :public Pieza
{
public:

    Alfil(bool color, int fila, int columna);

    //true si el movimiento es permitido; nx y ny son los nuevos valores de x e y
    bool mover(int nx, int ny);


};
