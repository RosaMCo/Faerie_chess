
#include "freeglut.h"
#include"CoordinadorAjedrez.h"


CoordinadorAjedrez ajedrez;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void OnMouseDown(int button, int state, int x, int y);

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseDown);

	//mundo.inicializa();
	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//mundo.dibuja();
	ajedrez.dibuja();


	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el c�digo de teclado
	//mundo.tecla(key);
	ajedrez.tecla(key);
	ajedrez.teclaEspecial(key);
	glutPostRedisplay();
}

void OnMouseDown(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN
		&& x >= 125 && x <= 677 && y >= 25 && y <= 577
		/*x >= glutGet(GLUT_WINDOW_HEIGHT) * 0.15 &&
			x <= glutGet(GLUT_WINDOW_HEIGHT) * 0.85 &&
			y >= glutGet(GLUT_WINDOW_WIDTH) * 0.04 &&
			y <= glutGet(GLUT_WINDOW_WIDTH) * 0.96*/)
	{
		
		ajedrez.jugada(button, state, x, y);
		ajedrez.jaque();
	}
}

void OnTimer(int value)
{
//poner aqui el c�digo de animacion
	//mundo.mueve();

	//no borrar estas lineas
	//ajedrez.jaque();
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}
