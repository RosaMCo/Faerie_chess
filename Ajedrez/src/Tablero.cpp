#include "Tablero.h"
#include <iostream>
#include <string>

Tablero::Tablero() {
	setTurno(negro);//inician blancas
	std::cout << "Incializo turno en: "<< turno; imprimirTurno();
	for (int i = 0; i < 32; i++) {
		lista[i] = 0;
	}
	for (int fila = 0; fila <= 7; fila++) {
		for (int columna = 0; columna <= 7; columna++) {
			casilla[fila][columna].setPosicion(columna * 20.0/8 - 10, fila * 20.0/8 - 2.5);//valores aleatorios de las casillas, cambiar a los concretos
			id[fila][columna] = NULL;
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
			id[0][i - 26] = lista[i];;
		}

		else {
			Rey* r = new Rey(negro, 7, i - 27);//fila 7, columna 4
			lista[i] = r;
			id[7][i - 27]=lista[i];
		}
		
	}

	//comprobarAsignaciones();
}

bool Tablero::selPieza(int forigen, int corigen) {//selección de pieza a mover [pasar como const?]
	std::cout << "\tEntro en Tablero::seleccionar Pieza" << "\n";
	std::cout << "El turno en tablero es:"; imprimirTurno();
	auto& iden = id[forigen][corigen];//es muy largo de escribir, así que referencia/alias
	if (iden) {//comprobar puntero no nulo (casilla no vacía)
		if (iden->getColor() == turno) {//comprobar que coinciden el color de la pieza y el del turno
			Color aux2 = iden->getColor();
			std::cout << "Coinciden color y turno; hay una pieza de color" << aux2 << "\n";
			return true;
		}
		else {
			return false; Color aux2 = iden->getColor();
			std::cout << "La pieza es de color " << aux2 << "y el turno es "; imprimirTurno();std::cout << "por lo que no muevo" << "\n";
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
		if (destino) {//casilla ocupada
			std::cout << "\ncasilla ocupada ";
			if (destino->getColor() != turno) {//comprobar pieza color distinto
				std::cout << "por pieza de distinto color \n ";
				if (origen->comer(cdestino, fdestino)) {//llamar a comer de la pieza seleccionada
					std::cout << "La puedo comer!! \n ";
					//llamar a destructor de la pieza destino (delete)
					//realizar el movimiento
					return actualizarId(fdestino, cdestino, forigen, corigen);
				}
				else { return false; std::cout << "No la puedo comer :( \n "; }
			}
			else { return false; std::cout << "por pieza del mismo color \n "; }
		}

		else {//casilla vacía
			std::cout << "La casilla destino esta vacia \n ";
			if (origen->mover(cdestino, fdestino)) {//llamar a mover de la pieza seleccionada
				//realizar el movimiento
				std::cout << "Me muevo a  \n ";
				imprimirId(cdestino, fdestino);
				return actualizarId(fdestino,cdestino,forigen,corigen);
			}
			else { return false; std::cout << "No me puedo mover... \n "; }
		}
	}
}
bool Tablero::actualizarId(int fdestino,int cdestino,int forigen,int corigen)
{
	std::cout << "\nestoy actualizando la id...";
	//auto& destino = id[fdestino][cdestino];
	//auto& origen = id[forigen][corigen];
	if (id[forigen][corigen])
	{
		id[forigen][corigen]->setPosicion(cdestino, fdestino);//actualizar posición de la pieza
		id[fdestino][cdestino] = id[forigen][corigen];//copia de dir. de memoria para que apunten ambos a la misma pieza
		id[forigen][corigen] = nullptr;//casilla origen ahora vacía (no apunta a la pieza)
		std::cout << "\nID ACTUALIZADA; Ahora nueva posicion:"; imprimirId(cdestino, fdestino); std::cout<<"\t\tLa posicion anterior: "; imprimirId(corigen, forigen);
		std::cout << "\nLISTA ACTUALIZADA; Ahora:"; imprimirLista(cdestino, fdestino);
		return true;
		
	}
	else 
	{
		std::cout << "Queria actualizar la id pero no había nada en origen";
		return false;
	}
	

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
bool Tablero::piezaEnMedio(int fdestino, int cdestino, int forigen, int corigen) {//selección de destino (una vez seleccionada pieza a mover)
	if ((id[forigen][corigen]->getTipo()) == CABALLO)
	{
		std::cout << "Es un caballo ->No se buscan piezas en medio e\n";
		return false;
	}
	else
	{
		//definir sentido del movimiento
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

		if (difY * difX)
			tipoMov = 'D'; //movimiento diagonal

		if (tipoMov == 'H')
		{
			for (int _columna = (corigen + incrementoX); _columna != cdestino; _columna += incrementoX)
			{
				if (casillaVacia(_columna,forigen)==0)
				{
					std::cout << "Mov horizontal -> Se encontró una pieza en medio en medio en: "; imprimirId(_columna, forigen);
					return true;
				}
			}
		}
		else if (tipoMov == 'V')
		{
			for (int _fila = (forigen + incrementoY); _fila != fdestino; _fila+=incrementoY)
			{
				std::cout << "\tColumna fija: " << corigen + 1 << "; buscando pieza en la fila: " << _fila +1 << "\n";
				if (casillaVacia(corigen,_fila)==0)
				{
					std::cout << "Mov vertical -> Se encontró una pieza en medio en: "; imprimirId(corigen, _fila);
					return true;
				}
			}
			return false;
		}
		else if (tipoMov == 'D') //movimiento diagonal
		{
			for (int _fila = forigen + incrementoY, _columna = corigen + incrementoX; (_fila != fdestino) && (_columna != cdestino); (_fila + incrementoY), (_columna + incrementoX))
			{
				if (casillaVacia(_columna, _fila) == 0)
				{
					std::cout << "Mov diagonal -> Se encontró una pieza en medio en: "; //imprimirId(_columna, _fila);
					return true;
				}
			}
			return false;

		}
		else return false;
	}
}

bool Tablero::casillaVacia(int c, int f)
{
	auto& iden = id[f][c];
	if (iden) {
		return false; std::cout << "---Casilla no vacía---\n";
	}
	else {
		return true; std::cout << "---Casilla vacía---\n";
	}
}

bool Tablero::colorDistinto(Pieza& pieza, Pieza& pieza2)
{
	if (pieza.getColor() != pieza2.getColor())
		return true;
	else return false;
}

bool Tablero::comerAlPaso(Peon& peon)
{
	for (int i = 0; i < 32; i++)
	{
		if (colorDistinto((*lista[i]), peon)) //si la pieza es de distinto color...
		{
			if (((lista[i]->getTipo()) == PEON)) //...y es un peon...
				if (lista[i]->getMovIniLargo()) //que se ha movido dos casillas en el primer movimiento...
				{
					int columna = peon.getColumna();
					int fila = peon.getFila();
					int columna2 = lista[i]->getColumna();
					int fila2 = lista[i]->getFila();

					if (fila2 == fila) //...si ambos peones se encuentran en la misma fila
						if ((columna == columna2 - 1) || (columna == columna2 + 1)) //y en una columna a la derecha o a la izquierda
							if (casillaVacia(columna2, fila2 - 1)) //y la casilla que está detrás del peon que se pretende comer al paso está vacía...
							{
								peon.setPosicion(columna2, fila + 1);
								return true; //....podremos comer al paso
							}

				}
		}
		else return false;
	}
}

bool Tablero::amenaza(Pieza& pieza)
{
	int _columna = pieza.getColumna();
	int _fila = pieza.getFila();
	for (int i = 0; i < 32; i++)
	{
		if (colorDistinto((*lista[i]), pieza)) //si tienen colores distintos
		{
				if (lista[i]->comer(_columna, _fila)) // incluir comer al paso
				return true;
			else return false;
		}
		else return false;
	}

}
bool Tablero::jaque(Color turno)
{
	if (lista[30]->getColor() == turno) //blancas
	{
		return amenaza(*lista[30]);
	}

	if (lista[31]->getColor() == turno) //negras
	{
		return amenaza(*lista[31]);
	}
}

/*bool Tablero::jaque(Rey& rey)
{
	if (amenaza(rey))
		return true;
	else
		return false;
}*/

void Tablero::enroque(Torre& torre, Rey& rey)
{
	if (((rey.getMovIni() == 0) && (torre.getMovIni() == 0)) && (colorDistinto(torre, rey) == 0))//si nunca se han movido y son del mismo color
	{
		if (amenaza(rey) == 0) //si el rey no está en jaque
		{
			if (torre.getColumna() == 0) //torres de la izquierda
				enroqueLargo(torre, rey);
			if (torre.getColumna() == 7)
				enroqueCorto(torre, rey); //torres de la derecha
		}
	}
}

void Tablero::enroqueLargo(Torre& torre, Rey& rey)
{
	Rey _rey = rey;
	//1. Compruebo que no haya piezas entre medias
	int contador = 0;
	int _fila = torre.getFila();//1.1 tomo la fila en la que esté la torre

	for (int i = 0; i < 32; i++)
	{
		if ((lista[i]->getFila()) == _fila) //1.2 si la fila de alguna pieza coincide con la de la torre
			for (int _columna = 1; _columna < 4; _columna++) //las columnas de las casillas entre torre y rey
			{
				if ((lista[i]->getColumna()) == _columna) //1.3 si además de la fila, está entre las columnas entre medias
					contador++; //1.4 si hay pieza entre medias, sumo contador 
				//2. Compruebo que ninguna de las columnas por las que pasará el rey quede atacada
				if (_columna > 1)//2.1 En el enroque largo, la casilla de la derecha de la torre sí puede ser atacada
					_rey.setPosicion(_columna, _fila);
				if (amenaza(rey))
					contador++;//2.2 Si alguna de las casillas está amenazada, sumo contador
			}
	}
	if (contador == 0) //no hay piezas entremedias, ninguna de las casillas por las que pasará el rey está amenazada.
	{
		_rey.setPosicion(2, _fila);
		if ((amenaza(_rey)) == 0)
		{
			rey.setPosicion(2, _fila);
			torre.setPosicion(3, _fila);
		}
		//FALTA ACTUALIZAR ID
	}

}

void Tablero::enroqueCorto(Torre& torre, Rey& rey)
{
	Rey _rey = rey;
	//1. Compruebo que no haya piezas entre medias
	int contador = 0;
	int _fila = torre.getFila();//1.1 tomo la fila en la que esté la torre

	for (int i = 0; i < 32; i++)
	{
		if ((lista[i]->getFila()) == _fila) //1.2 si la fila de alguna pieza coincide con la de la torre
			for (int _columna = 6; _columna > 4; _columna--) //las columnas de las casillas entre torre y rey
			{
				if ((lista[i]->getColumna()) == _columna) //1.3 si además de la fila, está entre las columnas entre medias
					contador++; //1.4 si hay pieza entre medias, sumo contador 

				_rey.setPosicion(_columna, _fila);//2. Compruebo que ninguna de las columnas por las que pasará el rey quede atacada
				if (amenaza(rey))
					contador++;//2.2 Si alguna de las casillas está amenazada, sumo contador
			}
	}
	if (contador == 0) //no hay piezas entremedias, ninguna de las casillas por las que pasará el rey está amenazada.
	{
		_rey.setPosicion(6, _fila);
		if ((amenaza(_rey)) == 0)
		{
			rey.setPosicion(6, _fila);
			torre.setPosicion(5, _fila);
		}

		//FALTA ACTUALIZAR ID

	}
}


bool Tablero::jaqueMate(Rey& rey)
{
	int _columna = rey.getColumna();
	int _fila = rey.getFila();
	if (amenaza(rey))//si está en jaque..
	{
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
			{
				if ((rey.mover(i, j)) && casillaVacia(i, j))//..y el rey se puede mover a una casilla vacía...
					return false; //...no hay jaque mate
				else return false;
			}
	}
	else
		return true;
}
void Tablero::imprimirId(int i, int j)
{
	if (id[j][i]) 
	{
		std::cout << "\n-------SOBRE LA ID----------" << "\n";
		std::cout << "id[" << i << "][" << j << "] "; imprimirTipo(id[j][i]->getTipo()); std::cout<< " en x= " << (id[j][i]->getColumna()) + 1 << " | y=" << (id[j][i]->getFila()) + 1 << "\n";
		imprimirColor(id[j][i]->getColor()); std::cout<< "\n";
	}
	else { std::cout << "\t PUNTERO NULO, casilla vacia: x=" << i +1 << " | y=" << j +1 << "\n"; }
}
void Tablero::imprimirLista(int i, int j)
{
	std::cout << "\n-------SOBRE LA LISTA----------" << "\n";
	for (int k = 0; k < 32; k++)
	{
		if ((lista[k]->getColumna() == i)&&(lista[k]->getFila() == j))
		{
			std::cout << "lista[" << k << "] esta en c=" << i + 1 << " f=" << j + 1; imprimirTipo(lista[k]->getTipo()); std::cout << "\n";
			imprimirColor(lista[k]->getColor()); std::cout << "\n";
		}
		//else { std::cout << "\t No se encuentra ninguna pieza en la lista en: x=" << i + 1 << " | y=" << j + 1 << "\n"; }
	}
}

void Tablero::imprimirTurno()
{
	std::string _turno;
	if((int)turno==1)
		_turno = "blancas";
	else if ((int)turno == 2)
		_turno = "negras";
	else if ((int)turno == 0)
		_turno = "indefinidas";
	
	std::cout << "\t ******** Juegan las  " << _turno << " **************\n";

}

void Tablero::imprimirColor(Color col)
{
	std::string _color;
	if(col==blanco)
		_color = "blanco";
	else if(col==negro)
		_color = "negro";
	else if(col==indefinido)
		_color = "indefinido";
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

	for (int fil = 0; fil < 8; fil++)
	{
		for (int col = 0; col < 8; col++)
		{
			bool OK = 0;
			int k = 0;
			while (OK != 1)
			{
				OK = ((lista[k]->getColumna() == col) && (lista[k]->getFila() == fil));
				k++;
			}
			std::cout << "\n\nLISTA[" << k << "] almacena que hay "; imprimirTipo(lista[k]->getTipo());
			imprimirColor(lista[k]->getColor()); std::cout << "en (" << col << " , " << fil << ")";
			OK = 0; k = 0;
			if (id[fil][col])
			{
				std::cout << "\nID[" << id[fil][col]->getColumna() << "][" << id[fil][col]->getFila() << "] almacena que hay ";
				imprimirTipo(id[fil][col]->getTipo()); imprimirColor(id[fil][col]->getColor());
			}
			else
				std::cout << "\nID[" << col << "][" << fil << "] vacío ";
			
		}
	}

 }

