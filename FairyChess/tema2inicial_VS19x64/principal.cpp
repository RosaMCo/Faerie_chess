#include "freeglut.h"

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}
/*void Dibuja(Esfera esf)
{
	glColor3ub(esf.rojo, esf.verde, esf.azul);
	glTranslatef(esf.x, esf.y, 0);
	glutSolidSphere(esf.radio, 20, 20);
	glTranslatef(-esf.x, -esf.y, 0); //DUDA: por qué el negativo?

}*/
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(20.0, 0, 0,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 


	/*//aqui es donde hay que poner el código de dibujo
	glColor3ub(150, 0, 250); //rojo, verde, azul RGB
	glutWireCube(5);
	glutSolidTeapot(1);
	glColor3ub(0, 255, 0);*/
	//Trasladar el punto a uno nuevo para dibujar
	//glTranslatef(1, 1, 1); //no necesario cambiar cada vez el origen porque lo podemos definir directamente cuando creamos
	//Dibujamos otras formas ahora en el 1,1,1 <--Ya no porque línea anterior comentada

	
	//para colorear con degradado usamos glBegin, imaginando un cuadrado
	//de paleta de color con vértices en xy:
	//-5,5(arriba izq);5,5(arriba der);-5,-5(abajo izq);5,-5
	//siempre definidos en sentido horario o antihorario
	glDisable(GL_LIGHTING);//desactivamos primero la iluminación, para evitar err
	glBegin(GL_POLYGON); //define tipo de objeto que se va a dibujar
		glColor3ub(255, 255, 0); //amarillo. OJO PARAM FLOAT
		glVertex3f(-5.0f, 0.0f, 5.0f); //en esquina izq inf
		glColor3ub(255, 255, 0);
		glVertex3f(-5.0f, 0.0f, -5.0f);
		glColor3ub(255, 0, 0);
		glVertex3f(5.0f, 0.0f, -5.0f);
		glColor3ub(255, 0, 0);
		glVertex3f(5.0f, 0.0f, 5.0f);
	glEnd();
	glEnable(GL_LIGHTING);//activamos la iluminación de nuevo


	glColor3ub (0, 255, 0);
	glutSolidTorus(1, 5, 20, 20);

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) //x_t e y_t irrelevantes
{
	
	glutPostRedisplay(); //avisamos de que se ha modificado escena
}

void OnTimer(int value) //para animaciones, vamos a hacer que la segunda esfera esté siempre variando
{
	
	
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay(); //Aviso que redibuje

}
