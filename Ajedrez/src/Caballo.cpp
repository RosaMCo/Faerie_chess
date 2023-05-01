#include "Caballo.h"

Caballo::Caballo(Color col, int f, int c) {
	setColor(col);
	fila = f;
	columna = c;
	setTipo(CABALLO);
}
bool Caballo::movOK(int nc, int nf)
	{
		if (nc < 0 || nf < 0 || nc > 8 || nf > 8)
		{
			return false;
		}
		if (((nc = columna - 1) && (nf = fila - 2)) || ((nc = columna + 1) && (nf = fila - 2)) || ((nc = columna + 2) && (nf = fila - 1)) || ((nc = columna + 2) && (nf = fila + 1)) || ((nc = columna + 1) && (nf = fila + 2)) || ((nc = columna - 1) && (nf = fila + 2)) || ((nc = columna - 2) && (nf = fila + 1)) || ((nc = columna - 2) && (nf = fila + 1)))
		{
			return true;
		}
		else return false;
}
