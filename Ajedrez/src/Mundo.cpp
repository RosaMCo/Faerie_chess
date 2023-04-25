#include "Mundo.h"

//Estado inicial del mundo
 
Mundo::Mundo()
{
	estado = Inicio;

}
/*void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}*/
void Mundo::dibuja()
{
	//Aquí va el juego del ajedrez clásico
	
}

void Mundo::mueve()
{

}

void Mundo::inicializa()
{
	
}

void Mundo::tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{

}
