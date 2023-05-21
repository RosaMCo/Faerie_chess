#pragma once
#include <stdio.h>// Todas las funciones como fread, fwrite, fopen, fclose y printf
#include <stdlib.h>// EXIT_FAILURE y EXIT_SUCCESS
#include <iostream>

using namespace std;
#define TAMANIO_BUFER 16 // Cuántos bytes leer en cada iteración
using namespace std;


class Reglas
{
public:
	
	virtual ~Reglas() {};
	char opcion;
	void Inicializa();
	
};

