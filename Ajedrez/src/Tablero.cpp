#include "Tablero.h"
#include <iostream>
#include <string>

Tablero::Tablero() {
	setTurno(Color::blanco);//inician blancas
	std::cout << "Incializo turno en: "<< turno; imprimirTurno();
	
	for (int fila = 0; fila <8; fila++) {
		for (int columna = 0; columna <8; columna++) {
			casilla[fila][columna].setPosicion(columna * 20.0/8 - 10, fila * 20.0/8 - 2.5);//valores aleatorios de las casillas, cambiar a los concretos
			id[fila][columna] = nullptr;
			_id[fila][columna] = nullptr;
		}
	}

	

	//los números mágicos son offsets para colocar las piezas en el tablero
	for (int i = 0; i < 16; i++) {//creación de peones

		if (i < 8) {//blancos
			Peon* p = new Peon(blanco, 1, i);//fila 1, todas las columnas
			lista[i] = p;
			id[1][i] = lista[i];

		}
		
		else {//negros
			Peon* p = new Peon(negro, 6, i - 8);//fila 6, todas las columnas (-8 porque i empieza en 8 y las columnas en 0)
			lista[i] = p;
			id[6][i - 8] = lista[i];
		}
		
	}

	for (int i = 16; i < 20; i++) {//creación de torres
		if (i < 18) {//blancas
			Torre* t = new Torre(blanco, 0, (i - 16) * 7);//fila 0, columnas 0 y 7
			lista[i] = t;
			id[0][(i - 16) * 7] = lista[i];
		}
		else {//negras
			Torre* t = new Torre(negro, 7, (i - 18) * 7);//fila 7, columnas 0 y 7
			lista[i] = t;
			id[7][(i - 18) * 7] = lista[i];
		}
	}

	for (int i = 20; i < 24; i++) {//creación de caballos
		if (i < 22) {//0s
			Caballo* c = new Caballo(blanco, 0, (i - 20) * 5 + 1);//fila 0,  columnas 1 y 6
			lista[i] = c;
			id[0][(i - 20) * 5 + 1] = lista[i];
		}

		else {
			Caballo* c = new Caballo(negro, 7, (i - 22) * 5 + 1);//fila 7, columnas 1 y 6
			lista[i] = c;//negras
			id[7][(i - 22) * 5 + 1] = lista[i]; 
		}
	}

	for (int i = 24; i < 28; i++) {//creación de alfiles
		if (i < 26) {//blancas
			Alfil* a = new Alfil(blanco, 0, (i - 24) * 3 + 2);//fila 0, columnas 2 y 5
			lista[i] = a;
			id[0][(i - 24) * 3 + 2] = lista[i];
		}

		else {//negras
			Alfil* a = new Alfil(negro, 7, (i - 26) * 3 + 2);//fila 7, columnas 2 y 5
			lista[i] = a;
			id[7][(i - 26) * 3 + 2] = lista[i]; 
		}
	
	}

	for (int i = 28; i < 30; i++) {
		if (i < 29) {
			Reina* r = new Reina(blanco, 0, i - 25);//fila 0, columna 3
			lista[i] = r;
			id[0][i - 25] = lista[i];
		}
		else {
			Reina* r = new Reina(negro, 7, i - 26);//fila 7, columna 3
			lista[i] = r;
			id[7][i - 26] = lista[i];
		}
	}

	for (int i = 30; i < 32; i++) {
		if (i < 31) {
			Rey* r = new Rey(blanco, 0, i - 26);//fila 0, columna 4
			lista[i] = r;
			id[0][i - 26] = lista[i];
		}

		else {
			Rey* r = new Rey(negro, 7, i - 27);//fila 7, columna 4
			lista[i] = r;
			id[7][i - 27]=lista[i];
		}
		
	}
	numero = 32;
	//comprobarAsignaciones();
	//imprimirLista();
}


void Tablero::eliminarPieza(int c, int f)
{
	for (int i = 0; i < numero; i++)
	{
		if ((i < 0) || (i >= numero))
			return;
		if ((lista[i]->getColumna() == c) && (lista[i])->getFila() == f)
		{
			int eliminadaX = lista[i]->getColumna();
			int eliminadaY = lista[i]->getFila();
			//std::cout << "-----------Quiero eliminar:-------------\n"; imprimirId(eliminadaX, eliminadaY); imprimirLista(eliminadaX, eliminadaY);
			delete lista[i];
			std::cout << "Eliminada!!!!!!!!!!!!!!!!!!!!!!\nNueva ID:";
			id[eliminadaY][eliminadaX] = nullptr;
			numero--;
			for (int j = i; j < numero; j++)
			{
				lista[j] = lista[j + 1];
			}
			return;
		}
	}
}

bool Tablero::selPieza(int forigen, int corigen) {//selección de pieza a mover [pasar como const?]
	//std::cout << "\tEntro en Tablero::seleccionar Pieza" << "\n";
	std::cout << "El turno en tablero es:"; imprimirTurno();
	auto& iden = id[forigen][corigen];//es muy largo de escribir, así que referencia/alias
	if (iden) {//comprobar puntero no nulo (casilla no vacía)
		if (iden->getColor() == turno) {//comprobar que coinciden el color de la pieza y el del turno
			//std::cout << "Coinciden color y turno; hay una pieza de color" << iden->getColor() << "\n";
			return true;
		}
		else {
			return false;
			std::cout << "La pieza es de color " << iden->getColor() << "y el turno es "; imprimirTurno();std::cout << "por lo que no muevo" << "\n";
		}
	}
	else { return false; std::cout << "La id no contiene nada. Casilla vacía" << "\n"; }
}


bool Tablero::mover(int fdestino, int cdestino, int forigen, int corigen) {//selección de destino (una vez seleccionada pieza a mover)
	std::cout << "\n->Entro en mover de tablero\n";
	auto& destino = id[fdestino][cdestino];
	auto& origen = id[forigen][corigen];
	bool coincidentes = 0;
	if ((fdestino == forigen) && (cdestino == corigen))
	{
		coincidentes = 1; std::cout << "Elige un destino valido.\n <>VUELVE A SELECCIONAR LA PIEZA QUE DESEA MOVER: " << "\n"; 
		return false;
	}
	if ((piezaEnMedio(fdestino, cdestino, forigen, corigen))||coincidentes)
		return false;
	else
	{
		if (!origen) //si no hay una pieza en origen
		{
			std::cout << "Intentas mover una pieza? Selecciona una casilla donde halla una. \n ";
			return false;

		}
		else
		{
			if (destino)  //casilla ocupada
			{
				std::cout << "\ncasilla ocupada ";
				if (destino->getColor() != turno) {//comprobar pieza color distinto
					std::cout << "por pieza de distinto color \n ";
					if (origen->comer(cdestino, fdestino))//llamar a comer de la pieza seleccionada
					{
						std::cout << "La puedo comer!! \n ";
						eliminarPieza(cdestino, fdestino);
						/*if (actualizarId(fdestino, cdestino, forigen, corigen, 1))//si cuando actualizo la id no voy a dejar el rey en jaque
							return(actualizarId(fdestino, cdestino, forigen, corigen));	//actualizo la id
						else false;*/
						return(actualizarId(fdestino, cdestino, forigen, corigen));
					}
					else { return false; std::cout << "No la puedo comer :( \n "; }
				}
				else 
				{
					if (enroque(fdestino, cdestino, forigen, corigen))
					{
						std::cout << "Piezas del mismo color y enroque HECHO :) \n ";
						return true;
					}
					else
					{
						return false; std::cout << "Piezas del mismo color y enroque no valido \n ";
					}
						 
				}
			}

			else //casilla vacía
			{
				std::cout << "La casilla destino esta vacia \n ";
				if (comerAlPaso(fdestino, cdestino, forigen, corigen))
				{
					return true;
				}
				else //llamar a mover de la pieza seleccionada
				{
					if (origen->mover(cdestino, fdestino))//realizar el movimiento
					{
						std::cout << "Me muevo a  \n ";
						imprimirId(cdestino, fdestino);
						/*if (actualizarId(fdestino, cdestino, forigen, corigen, 1))//si cuando voy a actualizar la id no dejo el rey en jaque
							return actualizarId(fdestino, cdestino, forigen, corigen); //actualizo Id
						else
							return false;*/
						return actualizarId(fdestino, cdestino, forigen, corigen);
					}
					else { return false; std::cout << "No me puedo mover... \n "; }
				}
				
			}
		}
	}
}
bool Tablero::actualizarId(int fdestino,int cdestino,int forigen,int corigen, int impedirJaque)
{
	std::cout << "\nestoy actualizando la id...";
	/*if (impedirJaque)
	{
		Pieza* _rey = nullptr;
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				_id[j][i] = dameCopiaId(i, j);
				if(_id[j][i])
					if (((_id[j][i]->getTipo()) == REY) && (_id[j][i]->getColor() == turno))
					{
						_rey = _id[j][i]; imprimirId(j, i, 0);
					}
			}
		}
		std::cout << "Tras copia de la id, he identificado el rey del color del turno como"; imprimirId(_rey->getColumna(), _rey->getFila(), 0);
		if (_id[forigen][corigen])
		{
			if (_id[forigen][corigen]->getTipo() == REY && _id[forigen][corigen]->getColor() == turno)
			{
				_id[forigen][corigen]->setPosicion(cdestino, fdestino);//actualizar posición de la pieza 
				_id[fdestino][cdestino] = _id[forigen][corigen];//copia de dir. de memoria para que apunten ambos a la misma pieza
				_id[forigen][corigen] = nullptr;//casilla origen ahora vacía (no apunta a la pieza)
				std::cout << "->He movido la id para estudiar el posible movimiento del rey a x=" << cdestino + 1 << " y=" << fdestino + 1 << "\n";
				if (amenaza(*(_id[fdestino][cdestino]), 0))
				{
					std::cout << "Movimiento no permitido, rey quedaría en jaque\n";
					for (int j = 0; j < 8; j++)
						for (int i = 0; i < 8; i++)
							_id[j][i] = dameCopiaId(i, j);
					return false; 
				}
				else
				{
					for (int j = 0; j < 8; j++)
						for (int i = 0; i < 8; i++)
							_id[j][i] = dameCopiaId(i, j);
					return true;
				}
			}
			else
			{
				_id[forigen][corigen]->setPosicion(cdestino, fdestino);//actualizar posición de la pieza 
				_id[fdestino][cdestino] = _id[forigen][corigen];//copia de dir. de memoria para que apunten ambos a la misma pieza
				_id[forigen][corigen] = nullptr;//casilla origen ahora vacía (no apunta a la pieza)
				std::cout << "->He movido la id para estudiar el posible movimiento del rey a x=" << cdestino + 1 << " y=" << fdestino + 1 << "\n";
				if (amenaza(*_rey, 0))
				{
					std::cout << "Movimiento no permitido, rey quedaría en jaque\n";
					for (int j = 0; j < 8; j++)
						for (int i = 0; i < 8; i++)
							_id[j][i] = dameCopiaId(i, j);
					return false; 
				}
				else
				{
					for (int j = 0; j < 8; j++)
						for (int i = 0; i < 8; i++)
							_id[j][i] = dameCopiaId(i, j);
					return true;
				}

			}
			
			

		}
		else
		{
			std::cout << "Queria actualizar la id pero no había nada en origen";
			return false;
		}

	}
	else
	{*/
	//NUEVA PARTE PARA DESLIGARNOS DE LA IDEA DE COPIA ID:
	if (impedirJaque) //no hace nada si le pasamos el parámetro
	{
		std::cout << "\n";
	}
	else//valor por defecto, entra siempre.
	{
		if (id[forigen][corigen])//si hay pieza, id no nula
		{
			id[forigen][corigen]->setPosicion(cdestino, fdestino);//actualizar posición de la pieza 
			id[fdestino][cdestino] = id[forigen][corigen];//copia de dir. de memoria para que apunten ambos a la misma pieza
			id[forigen][corigen] = nullptr;//casilla origen ahora vacía (no apunta a la pieza)
			std::cout << "\nID ACTUALIZADA; Ahora nueva posicion:"; imprimirId(cdestino, fdestino); std::cout << "\t\tLa posicion anterior: "; imprimirId(corigen, forigen);
			//std::cout << "\nLISTA ACTUALIZADA: "; //imprimirLista(cdestino, fdestino);
			char _jaque = jaqueMate(turno);
			estado_jaque = _jaque;
			std::cout << "\n\n % %%%%%%%%%%%%%% ESTADO DE JAQUE : " << _jaque << "% %%%%%%%%%%%%%%\n";
			return true;

		}
		else
		{
			std::cout << "Queria actualizar la id pero no había nada en origen";
			return false;
		}
	}
	//}
	

}

void Tablero::dibuja() {
	//dibujado tablero
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fichas/tablero.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-10, -2.5);
	glTexCoord2d(1, 1); glVertex2f(10, -2.5);
	glTexCoord2d(1, 0); glVertex2f(10, 17.5);
	glTexCoord2d(0, 0); glVertex2f(-10, 17.5);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	

	//llamada a dibujado piezas
	for (int i = 0; i < 32; i++) {
		int tempf, tempc;
		if (lista[i]) {//no llamar a dibujado si puntero vacío
			//var. temporales para pasar las coordenadas correspondientes a la pieza
			tempf = lista[i]->getFila();
			tempc = lista[i]->getColumna();
			//pasamos las coordenadas correspondientes a la pieza para que se dibuje
			lista[i]->dibuja(casilla[tempf][tempc].getX(), casilla[tempf][tempc].getY());

		}
	}
}

bool Tablero::piezaEnMedio(int fdestino, int cdestino, int forigen, int corigen, int NojaqueMate) {//selección de destino (una vez seleccionada pieza a mover)
	if(NojaqueMate)
	{
		if ((id[forigen][corigen]->getTipo()) == CABALLO)
		{
			std::cout << "Es un caballo ->No se buscan piezas en medio e\n";
				return false;
		}
	}
	if (cdestino == 0 && fdestino == 3) { 
		std::cout << "\n"; }

		int difY = fdestino - forigen;
		int difX = cdestino - corigen;
		int incrementoY = 0;
		int incrementoX = 0;
		char tipoMov = 'M';
		if (difY) //...si hay variacion en las filas
			incrementoY = difY / abs(difY); //...calculo el incremento...
		else
			tipoMov = 'H'; //...si no la hay, el movimiento horizontal

		if (difX) //...si hay variacion en las columnas
			incrementoX = difX / abs(difX); //...calculo el incremento...
		else
			tipoMov = 'V'; //...si no la hay movimiento vertical: difX = 0; difY!=0;

		if (abs(difY) == abs(difX))
			tipoMov = 'D'; //movimiento diagonal

		if (tipoMov == 'H')
		{
			for (int _columna = (corigen + incrementoX); _columna != cdestino; _columna += incrementoX)
			{
				if (casillaVacia(_columna,forigen,NojaqueMate)==0)
				//if(id[forigen,_columna])
				{
					std::cout << "Mov horizontal -> Se encontró una pieza en medio en medio en: "; imprimirId(_columna, forigen);
					return true;
				}
			}
			return false;
		}
		else if (tipoMov == 'V')
		{
			for (int _fila = (forigen + incrementoY); _fila != fdestino; _fila+=incrementoY)
			{
				//std::cout << "\tColumna fija: " << corigen + 1 << "; buscando pieza en la fila: " << _fila +1 << "\n";
				if (casillaVacia(corigen,_fila,NojaqueMate)==0)
				{
					std::cout << "Mov vertical -> Se encontró una pieza en medio en: "; imprimirId(corigen, _fila);
					return true;
				}
			}
			return false;
		}
		else if (tipoMov == 'D') //movimiento diagonal
		{
			int _fila = forigen + incrementoY;
			int _columna = corigen + incrementoX;
			while ((_fila != fdestino) || (_columna != cdestino))
			{
				if (cdestino == 0 && fdestino == 3) 
				{ std::cout << "\n"; }
				if (casillaVacia(_columna, _fila,NojaqueMate) == 0)
				{
					if (cdestino == 0 && fdestino == 3)
					{
						std::cout << "\n";
					}
					//std::cout << "Mov diagonal -> Se encontro una pieza en medio en: "; //imprimirId(_columna, _fila);
					return true; //pieza en medio
				}
				_fila += incrementoY;
				_columna += incrementoX;

			}
			if (cdestino == 0 && fdestino == 3)
			{
				std::cout << "\n";
			}
			return false;//pieza en medio

		}
		else return false;
	//}
}

bool Tablero::casillaVacia(int c, int f,int NojaqueMate)
{
	auto& iden = NojaqueMate == 1 ? id[f][c] : _id[f][c];
	if (iden) 
	{
		return false; std::cout << "---Casilla no vacía---\n";
	}
	else 
	{
		return true; std::cout << "---Casilla vacía---\n";
	}
}

bool Tablero::colorDistinto(Pieza& pieza, Pieza& pieza2)
{
	if (pieza.getColor() != pieza2.getColor())
		return true;
	else return false;
}


bool Tablero::comerAlPaso(int fdestino, int cdestino, int forigen, int corigen)
{
	auto& origen = id[forigen][corigen];
	auto& destino = id[fdestino][cdestino];
	auto& izq = id[forigen][corigen - 1];
	auto& dcha = id[forigen][corigen + 1];
	int incremento = (origen->getColor()) == blanco ? -1 : 1; //si el origen es blanco, nos interesa el incremento del contrario, esto es el negro, que se mueve decrementando filas
	if (origen->getTipo() == PEON) {
		if (corigen - 1 >= 0 && izq) {//casilla a la izq existe y tiene algo dentro
			if (izq->getTipo() == PEON && izq->getColor() != origen->getColor()) {//la casilla contiene un peón del color contrario
				if (izq->getMovIniLargo()) {//si peón contrario vulnerable
					eliminarPieza(cdestino, (fdestino + incremento));
					if (actualizarId(fdestino, cdestino, forigen, corigen))
					{
						std::cout << "comida al paso!\n";
						return true;
					}
					else
					{
						std::cout << "comer al paso no completado\n";
						return false;
					}
				}
				return false;
				
			}
			return false;
		}
		else if (corigen + 1 <= 7 && dcha) {//casilla a la dcha existe y tiene algo dentro
			if (dcha->getTipo() == PEON && dcha->getColor() != origen->getColor()) {//la casilla contiene un peón del color contrario
				if (dcha->getMovIniLargo()) {//si peón contrario vulnerable
					eliminarPieza(cdestino, (fdestino + incremento));
					if (actualizarId(fdestino, cdestino, forigen, corigen))
					{
						std::cout << "comida al paso!\n";
						return true;
					}
					else
					{
						std::cout << "comer al paso no completado\n";
						return false;
					}
				}
				return false;

			}
			return false;
		}
		return false;
	}
	return false;
	/*
	int incremento = (origen->getColor()) == blanco ? -1 : 1; //si el origen es blanco, nos interesa el incremento del contrario, esto es el negro, que se mueve decrementando filas
	auto& peonAComer = id[fdestino + incremento][cdestino];
	if (peonAComer)
	{
		if (colorDistinto(*origen, *peonAComer))//si las piezas son de distinto color...
		{
			if ((origen->getTipo() == PEON) && (peonAComer->getTipo() == PEON))//...y son peones...
			{
				if (peonAComer->getMovIniLargo()) // si el peon a comer se ha movido dos casillas en el primer movimiento...
				{
					if ((forigen == (fdestino + incremento)) && (abs(corigen - cdestino) == 1))//...si ambos peones se encuentran en la misma fila y a una columna de diferencia...
					{
						if (casillaVacia(cdestino, fdestino)) //y la casilla que está detrás del peon que se pretende comer al paso está vacía...
						{
							eliminarPieza(cdestino, (fdestino + incremento));
							if (actualizarId(fdestino, cdestino, forigen, corigen))
							{
								std::cout << "comida al paso!\n";
								return true;
							}
							else
							{
								std::cout << "comer al paso no completado\n";
								return false;
							}

						}
						else return false;
					}
					else return false;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	else return false;
	*/
}

void Tablero::validarPromocion() {
	for (int i = 0; i < 8; i++) {
		if (id[0][i]) {
			if ((id[0][i]->getColor() == negro) && (id[0][i]->getTipo() == PEON)) {
				for (int j = 0; j < numero; j++) {
					if (lista[j] == id[0][i]) promocionPeon(0, i, j, negro);
				}
			}
		}
		if (id[7][i]) {
			if ((id[7][i]->getColor() == blanco) && (id[7][i]->getTipo() == PEON)) {
				for (int j = 0; j < numero; j++) {
					if (lista[j] == id[7][i]) promocionPeon(7, i, j, blanco);
				}
			}
		}
		
	}
}

void Tablero::promocionPeon(int fpieza, int cpieza, int nlista, Color color) {//meter la posicion de la pieza a promocionar
	string seleccion;
	cout << "Escribe el nombre de la pieza a la que quieres promocionar" << endl;
	cout << "Disponibles: reina, caballo, alfil, torre, campesino, cortesana y obelisco" << endl;
	cin >> seleccion;
	
	if (seleccion == "reina") {
		Reina* r = new Reina(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = r;
		id[fpieza][cpieza] = r;
	}
	else if (seleccion == "caballo") {
		Caballo* c = new Caballo(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = c;
		id[fpieza][cpieza] = c;
	}
	else if (seleccion == "alfil") {
		Alfil* a = new Alfil(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = a;
		id[fpieza][cpieza] = a;
	}
	else if (seleccion == "torre") {
		Torre* t = new Torre(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = t;
		id[fpieza][cpieza] = t;
	}
	else if (seleccion == "campesino") {
		Campesino* c = new Campesino(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = c;
		id[fpieza][cpieza] = c;
	}
	else if (seleccion == "cortesana") {
		Cortesana* c = new Cortesana(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = c;
		id[fpieza][cpieza] = c;
	}
	else if (seleccion == "obelisco") {
		Obelisco* o = new Obelisco(color, fpieza, cpieza);
		delete lista[nlista];
		lista[nlista] = o;
		id[fpieza][cpieza] = o;
	}
}

void Tablero::intercambioPieza(Intercambio tipo) {//es fea (mucho código repetido), pero funcional 

	//Peón a campesino
	if (tipo == PEON_CAMPESINO_B) {
		for (int i = 0; i < 8; i++) {
			if (id[1][i]->getTipo() == PEON) {
				Campesino* p = new Campesino(blanco, 1, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 1 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = p;
						id[1][i] = p;
						std::cout << "Campesino blanco listo" << endl;
						return;
					}
				}
			}
		}
	}
	else if (tipo == PEON_CAMPESINO_N) {
		for (int i = 0; i < 8; i++) {
			if (id[6][i]->getTipo() == PEON) {
				Campesino* p = new Campesino(negro, 6, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 6 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = p;
						id[6][i] = p;
						std::cout << "Campesino negro listo" << endl;
						return;
					}
				}
			}
		}
	}

	//Torre a obelisco
	else if (tipo == TORRE_OBELISCO_B) {
		for (int i = 0; i < 8; i++) {
			if (id[0][i]->getTipo() == TORRE) {
				Obelisco* o = new Obelisco(blanco, 0, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 0 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = o;
						id[0][i] = o;
						std::cout << "Obelisco blanco listo" << endl;
						return;
					}
				}
			}
		}
	}
	else if (tipo == TORRE_OBELISCO_N) {
		for (int i = 0; i < 8; i++) {
			if (id[7][i]->getTipo() == TORRE) {
				Obelisco* o = new Obelisco(negro, 7, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 7 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = o;
						id[7][i] = o;
						std::cout << "Obelisco negro listo" << endl;
						return;
					}
				}
			}
		}
	}

	//Alfil a cortesana
	else if (tipo == ALFIL_CORTESANA_B) {
		for (int i = 0; i < 8; i++) {
			if (id[0][i]->getTipo() == ALFIL) {
				Cortesana* c = new Cortesana(blanco, 0, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 0 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = c;
						id[0][i] = c;
						std::cout << "Cortesana blanca lista" << endl;
						return;
					}
				}
			}
		}
	}
	else if (tipo == ALFIL_CORTESANA_N) {
		for (int i = 0; i < 8; i++) {
			if (id[7][i]->getTipo() == ALFIL) {
				Cortesana* c = new Cortesana(negro, 7, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 7 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = c;
						id[7][i] = c;
						std::cout << "Cortesana negra lista" << endl;
						return;
					}
				}
			}
		}
	}

	//Rey a regente
	else if (tipo == REY_REGENTE_B) {
		for (int i = 0; i < 8; i++) {
			if (id[0][i]->getTipo() == REY) {
				Regente* r = new Regente(blanco, 0, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 0 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = r;
						id[0][i] = r;
						std::cout << "Regente blanco listo" << endl;
						return;
					}
				}
			}
		}
	}
	else if (tipo == REY_REGENTE_N) {
		for (int i = 0; i < 8; i++) {
			if (id[7][i]->getTipo() == REY) {
				Regente* r = new Regente(negro, 7, i);
				for (int j = 0; i < 32; j++) {
					if (lista[j]->getFila() == 7 && lista[j]->getColumna() == i) {
						delete lista[j];
						lista[j] = r;
						id[7][i] = r;
						std::cout << "Regente negro listo" << endl;
						return;
					}
				}
			}
		}
	}
}


bool Tablero::amenaza(Pieza& pieza, int NojaqueMate)//no aplicado a comer al paso
{
	
	int _columna = pieza.getColumna();
	int _fila = pieza.getFila();
	
	if(NojaqueMate)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (id[j][i])
				{
					if ((colorDistinto(*id[j][i], pieza)) && ((i != _columna) && (j != _fila)))
					{
						if (piezaEnMedio(j, i, _fila, _columna, 1) == 0)
						{

							if ((id[j][i]->comer(_columna, _fila)))
							{
								std::cout << "----Puede comer al rey el"; imprimirTipo(id[j][i]->getTipo()); imprimirColor(id[j][i]->getColor());
								std::cout << " de x= " << i + 1 << " y= " << j + 1 << "estando supuestamente el rey en x= " << _columna + 1 << " y= " << _fila + 1 << "\n";
								std::cout << "...Y Pieza en medio: " << piezaEnMedio(j, i, _fila, _columna, NojaqueMate) << "\n";
								return true; //amenaza no jaque
							}
						}
					}
				}
			}
		} return false;
	}
	else
	{
		for (int j = 0; j < 8; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				if (_id[j][i])
				{
					if ((colorDistinto(*_id[j][i], pieza)) && ((i != _columna) && (j != _fila)))
					{
						if (piezaEnMedio(j, i, _fila, _columna, 0) == 0)
						{
							//std::cout << "Estoy en amenaza despues de que el _rey se mueva a : \n"; imprimirId(_columna, _fila, 0);
							if (_id[j][i]->getTipo() == REINA)//Esto sólo es una prueba, lo borraré pero no influye
							{
								std::cout << "Se encuentra sin pieza en medio y de color distinto una: "; imprimirId(i, j, 0);
							}

							if ((_id[j][i]->comer(_columna, _fila)))
							{
								std::cout << "----Puede comer al rey el"; imprimirTipo(_id[j][i]->getTipo()); imprimirColor(_id[j][i]->getColor());
								std::cout << " de x= " << i + 1 << " y= " << j + 1 << "estando supuestamente el rey en x= " << _columna + 1 << " y= " << _fila + 1 << "\n";
								std::cout << "...Y Pieza en medio: " << piezaEnMedio(j, i, _fila, _columna, NojaqueMate) << "\n";
								return true; //amenaza jaque
							}
						}
					}
				}
				
			}
		} return false;
	}
			
}
Pieza* Tablero::jaque(Color turn)
{
	
	for (int fila = 0; fila < 8; fila++)
	{
		for (int columna = 0; columna < 8; columna++)
		{
			if (id[fila][columna])
			{
				if ((id[fila][columna]->getTipo() == REY) && (id[fila][columna]->getColor() != turn)) //si el rey del contrario...
				{
					if (amenaza(*id[fila][columna])) //....esta amenazado
					{
						std::cout << "JAQUE AL REY "; imprimirColor(id[fila][columna]->getColor());
						imprimirId(columna, fila);
						return id[fila][columna];
					}
				}
			}
		}
	}
	return nullptr;
}

char Tablero::jaqueMate(Color turn)
{
	Pieza* rey = jaque(turn);//si pueden hacer jaque al rey contrario
	{
		Color atacante = turn == blanco ? blanco : negro;
		int contador = 0;
		if (rey)//si el rey contrario está en jaque...
		{
			int reyX = rey->getColumna();
			int reyY = rey->getFila();
		    std::cout << "El rey que le llega al jaqueMate es: "; imprimirId(reyX, reyY);
			for (int j = 0; j < 8; j++)
			{
				for (int i = 0; i < 8; i++)
				{
					if (rey->mover(i, j))//...si el rey contrario se puede mover a un lugar donde hay pieza
					{
						if (casillaVacia(i, j) == 0)//..a un lugar donde hay pieza
						{
							if (id[j][i]->getColor() == atacante)//...del color de la atacante...
							{
								std::cout << "Estudio si el rey vuelve a quedar en jaque en x= " << i + 1 << " y=" << j + 1 << "\n";
								for (int y = 0; y < 8; y++)
									for (int x = 0; x < 8; x++)
										_id[y][x] = dameCopiaId(x, y);
								std::cout << "::::::::ACTUALIZANDO POSICION DE REY::::::\n";
								_id[reyY][reyX]->setPosicion(i, j);//Movemos el rey a la posición que podría moverse
								std::cout << "\t1. Seteo posición de x=" << reyX + 1 << " y=" << reyY + 1 << " a x=" << _id[reyX][reyY]->getColumna() +1 << " y=" << _id[reyX][reyY]->getFila() + 1 << "\n";imprimirId(reyX, reyY,0);
								std::cout << "\t2. Copio dirección del antiguo rey al nuevo\n\t\t antes la _id[j][i]:\n"; 
								imprimirId(i, j,0);
								_id[j][i] = _id[reyY][reyX];//copia de dir. de memoria para que apunten ambos a la misma pieza
								std::cout << "\t\t ahora la :id[j][i]:\n"; imprimirId(i, j, 0);
								std::cout << "\t\t3. Borro la antigua posicion del rey. Ahora:\n"; imprimirId(reyX, reyY,0);
								_id[reyY][reyX] = nullptr;//casilla origen ahora vacía (no apunta a la pieza)
								std::cout << "\nActualizo mov del rey para estudiar el supuesto, ahora:\n";
								imprimirId(i,j,0); imprimirId(reyX,reyY,0);
								if (amenaza(*_id[j][i], 0) == 0)//que no le hace quedar en jaque de nuevo
								{
									std::cout << "No es jaque mate porque el rey"; imprimirColor(_id[j][i]->getColor()); std::cout << "se puede mover a : x = " << i + 1 << " y = " << j + 1 << "y allí estará a salvo\n";
									contador++;
								}
							}
						}
						else//...o a una casilla vacía que no le hace quedar en amenaza de nuevo
						{
							std::cout << "Estudio si el rey vuelve a quedar en jaque en x= " << i + 1 << " y=" << j + 1 << "\n";
							std::cout << "\n";
							for (int y = 0; y < 8; y++)
								for (int x = 0; x < 8; x++)
								{
									_id[y][x] = dameCopiaId(x, y); //if(x==0&&y==3)imprimirId(x, y, 0);
								}
							std::cout << "::::::::ACTUALIZANDO POSICION DE REY::::::\n";
							_id[reyY][reyX]->setPosicion(i, j);//Movemos el rey a la posición que podría moverse
							_id[j][i] = _id[reyY][reyX];
							std::cout << "\t1. Seteo posición de x=" << reyX + 1 << " y=" << reyY + 1 << " a x=" << _id[reyX][reyY]->getColumna() + 1 << " y=" << _id[reyX][reyY]->getFila() + 1 << "\n";
							imprimirId(reyX, reyY, 0);
							std::cout << "\t2. Copio dirección del antiguo rey al nuevo\n\t\t antes la _id[j][i]:\n"; imprimirId(i, j, 0);
							_id[j][i] = _id[reyY][reyX];//copia de dir. de memoria para que apunten ambos a la misma pieza
							std::cout << "\t\t ahora la :id[j][i]:\n"; imprimirId(i, j, 0);
							std::cout << "\t\t3. Borro la antigua posicion del rey. Ahora:\n"; imprimirId(reyX, reyY,0);
							_id[reyY][reyX] = nullptr;//casilla origen ahora vacía (no apunta a la pieza)
							std::cout << "\nActualizo mov del rey para estudiar el supuesto, ahora:\n";
							imprimirId(i, j, 0); imprimirId(reyX, reyY, 0);
							if (amenaza((*_id[j][i]), 0))//que no le hace quedar en jaque de nuevo
							{
								std::cout << "Debería ser JAQUE MATE\n";
							}
							else
							{
								std::cout << "No es jaque mate porque el rey"; imprimirColor(_id[j][i]->getColor()); std::cout << "se puede mover a : x = " << i + 1 << " y = " << j + 1 << "y allí estará a salvo\n";
								contador++;
							}
						}
					}

				}
			}
			
			if (contador == 0) { std::cout << "JAQUE MATE DESDE TABLERO::JaqueMate\n"; estado_jaque = 'M'; return 'M'; }
			else { std::cout << "JAQUE MATE DESDE TABLERO::Jaque\n"; estado_jaque = 'J'; return 'J'; }
		}
		else { estado_jaque = 'N'; return 'N'; }
	}

}



bool Tablero::enroque(int fdestino, int cdestino, int forigen, int corigen)
{
	auto& origen = id[forigen][corigen];
	auto& destino = id[fdestino][cdestino];
	Pieza* rey;
	Pieza* torre;
	std::cout << "->Enroque general\n";
	if (origen && destino)
	{
		std::cout << "->Hay piezas en seleccion\n";
		std::cout << "->En origen: "; imprimirTipo(origen->getTipo());
		std::cout << "->En destino: "; imprimirTipo(destino->getTipo());
		if (((origen->getTipo() == REY) && (destino->getTipo() == TORRE)) || ((origen->getTipo() == TORRE) && (destino->getTipo() == REY)))
		{
			std::cout << "->Una es rey y la otra torre\n";
			if (colorDistinto(*origen, *destino) == false)
			{
				std::cout << "->Su color es igual\n";
				std::cout << "->En origen: "; imprimirTipo(origen->getTipo());
				std::cout << "->En destino: "; imprimirTipo(destino->getTipo());
				switch (origen->getTipo())
				{
				case REY:
					rey = origen; std::cout << " rey es el origen, torre es el destino\n";
					torre = destino;
					break;
				case TORRE:
					rey = destino; std::cout << " torre es el origen, rey es el destino\n";
					torre = origen;
					break;
				default:
					break;
				}
				std::cout << "-> Miro si es el movimiento inicial: ";
				if (((rey->getMovIni() == false) && (torre->getMovIni() == false))) //si son del mismo color y nunca se han movido se sobreentiende que están en la misma fila.
				{
					std::cout << "es el movimiento inicial de ambos\n-> Rey en jaque? ";
					if (amenaza(*rey) == 0) //si el rey no está en jaque
					{
						std::cout << "Rey no en jaque actualmente\n";
						if (piezaEnMedio(fdestino, cdestino, forigen, corigen,0))
						{
							return false; std::cout << "...pero hay una pieza en medio\n";
						}
						else
						{
							std::cout << "...y no hay pieza en medio\n";
							if (torre->getColumna() == 0) //torres de la izquierda
							{
								std::cout << "La columna de la torre es " << torre->getColumna() << " || Llamo a enroque largo\n";
								return (enroque(*torre, *rey, 'L'));
							}
							if (torre->getColumna() == 7)
							{
								std::cout << "La columna de la torre es " << torre->getColumna() << " |Llamo a enroque corto\n";
								return (enroque(*torre, *rey, 'C'));//torres de la derecha
							}
						}
					}
					else return false;
				}
				else return false;

			}
			else return false;
		}
		else return false;

	}
	else return false;
	
}

bool Tablero::enroque(Pieza& torre, Pieza& rey,char tipo)
{
	auto& _rey = rey;
	int _fila = torre.getFila();//tomo la fila en la que esté la torre
	int inicio = 2, fin = 4; //para enroque largo
	if (tipo == 'C') //enroque corto
	{
		inicio = fin;
		fin = 6;
	}
	for (int _columna = inicio; _columna == fin; _columna++)
	{
		_rey.setPosicion(_columna, _fila);//Compruebo que ninguna de las columnas por las que pasará el rey quede atacada
		if (amenaza(_rey))
			return false;
	}
	if (tipo == 'C')
	{
		if ((actualizarId(_fila, 6, rey.getFila(), rey.getColumna())) && (actualizarId(_fila, 5, torre.getFila(), torre.getColumna())))
		{
			torre.setMovIni(0);
			rey.setMovIni(0);
			return true;
		}
		else return false;
	}
	else //enroque largo
	{
		if ((actualizarId(_fila, 2, rey.getFila(), rey.getColumna())) && (actualizarId(_fila, 3, torre.getFila(), torre.getColumna())))
		{
			torre.setMovIni(0);
			rey.setMovIni(0);
			return true;
		}
		else return false;
	}


}



void Tablero::imprimirId(int i, int j, int NojaqueMate)
{
	if (NojaqueMate)
	{
		if (id[j][i])
		{
			std::cout << "\n-------SOBRE LA ID----------" << "\n";
			std::cout << "id[" << i << "][" << j << "] "; imprimirTipo(id[j][i]->getTipo()); std::cout << " en x= " << (id[j][i]->getColumna()) + 1 << " | y=" << (id[j][i]->getFila()) + 1 << "\n";
			imprimirColor(id[j][i]->getColor()); std::cout << "\n";
		}
		else { std::cout << "\t PUNTERO NULO, casilla vacia: x=" << i + 1 << " | y=" << j + 1 << "\n"; }
	}
	else
	{
		if (_id[j][i])
		{
			std::cout << "\n-------SOBRE LA COPIA ID----------" << "\n";
			std::cout << "id[" << i << "][" << j << "] "; imprimirTipo(_id[j][i]->getTipo()); std::cout << " en x= " << (_id[j][i]->getColumna()) + 1 << " | y=" << (_id[j][i]->getFila()) + 1 << "\n";
			imprimirColor(_id[j][i]->getColor()); std::cout << "\n";
		}
		else { std::cout << "\t PUNTERO NULO, casilla vacia: x=" << i + 1 << " | y=" << j + 1 << "\n"; }

	}

}
void Tablero::imprimirLista(int i, int j)
{
	std::cout << "\n-------SOBRE LA LISTA----------" << "\n";
	for (int k = 0; k < numero; k++)
	{
		if ((lista[k]->getColumna() == i)&&(lista[k]->getFila() == j))
		{
			std::cout << "lista[" << k << "] esta en c=" << i + 1 << " f=" << j + 1; imprimirTipo(lista[k]->getTipo()); std::cout << "\n";
			imprimirColor(lista[k]->getColor()); std::cout << "\n";
		}
		//else { std::cout << "\t No se encuentra ninguna pieza en la lista en: x=" << i + 1 << " | y=" << j + 1 << "\n"; }
	}
}
void Tablero::imprimirLista()
{
	std::cout << "\n-------SOBRE LA LISTA----------" << "\n";
	for (int k = 0; k < numero; k++)
	{
		std::cout << "lista[" << k << "] esta en c=" << (lista[k]->getColumna())+1 << " f=" << (lista[k]->getFila()) + 1;
		imprimirTipo(lista[k]->getTipo()); std::cout << "\n";
		imprimirColor(lista[k]->getColor()); std::cout << "\n";
	}
}

void Tablero::imprimirTurno()
{
	std::string _turno;
	switch (turno)
	{
	case indefinido:
		break;
	case blanco:
		_turno = "BLANCAS";
		break;
	case negro:
		_turno = "NEGRAS";
		break;
	default:
		_turno = "indefinidas";
		break;
	}	
	std::cout << "\t ******** Juegan las  " << _turno << " **************\n";

}

void Tablero::imprimirColor(Color col)
{
	std::string _color;
	switch (col)
	{
	case indefinido:
		_color = "indefinido";
		break;
	case blanco:
		_color = "blanco";
		break;
	case negro:
		_color = "negro";
		break;
	default:
		break;
	}
	std::cout << " color: " << _color << " ";

}

void Tablero::imprimirTipo(Tipo tip)
{
	std::string _tip;
	switch (tip)
	{
		case PEON:
			_tip = "peon"; break;
		case TORRE:
			_tip = "torre"; break;
		case CABALLO:
			_tip = "caballo"; break;
		case ALFIL:
			_tip = "alfil"; break;
		case REY:
			_tip = "rey"; break;
		case REINA:
			_tip = "reina"; break;
		case INDEFINIDO:
			_tip = "indefinido"; break;
		default:
			break;
	}

	std::cout<< " tipo: " << _tip << " ";
}

void Tablero::comprobarAsignaciones()
{
	std::cout << "\n\n<<<<<<<<<<<<<<<<<<<<<<<<<<<COMPRUEBO ASIGNACION>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
	for (int k = 0; k < numero; k++)
	{
		std::cout << "\n\n\===============" << k << "===============";
		int _columna = lista[k]->getColumna();
		int _fila = lista[k]->getFila();
		imprimirId(_columna, _fila);
		imprimirLista(_columna, _fila);

	}
	std::cout << "\n-------------FIN--------------\n";

 }
Pieza* Tablero::dameCopiaId(int c, int f)
{
	Pieza* _lista[32];
	for (int k = 0; k < numero; k++)
	{
		Tipo _tipo = lista[k]->getTipo();
		Color _color = lista[k]->getColor();
		int _x = lista[k]->getColumna();
		int _y = lista[k]->getFila();
		switch (_tipo)
		{
		case PEON:
			_lista[k] = new Peon(_color, _y, _x);
			break;
		case TORRE:
			_lista[k] = new Torre(_color, _y, _x);
			break;
		case ALFIL:
			_lista[k] = new Alfil(_color, _y, _x);
			break;
		case CABALLO:
			_lista[k] = new Caballo(_color, _y, _x);
			break;
		case REINA:
			_lista[k] = new Reina(_color, _y, _x);
			break;
		case REY:
			_lista[k] = new Rey(_color, _y, _x);
			break;
		case INDEFINIDO:
			break;
		case CAMPESINO:
			//_lista[k] = new Campesino(_color, _y, _x);
			break;
		case REGENTE:
			//_lista[k] = new Regente(_color, _y, _x);
			break;
		default:
			break;
		}
		_id[_y][_x] = _lista[k];
	}
	return _id[c][f];
}

