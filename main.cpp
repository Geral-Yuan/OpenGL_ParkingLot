#include "parking_lot.h"
void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, n);
	glutPostRedisplay();
}
void glDraw()
{
	Vehicle *vehicle;
	static double x = 0, y = 0;
	static double a = 1, b = 0;
	Vec anchor(x, y);
	Vec x_dir(a, b), y_dir(-b, a);
	vehicle = new Car(anchor, x_dir, y_dir);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	vehicle->draw();
	vehicle->move(x_dir);
	vehicle->rotate(0.01);
	x = vehicle->getAnchor().getX();
	y = vehicle->getAnchor().getY();
	a = vehicle->getxDir().getX();
	b = vehicle->getxDir().getY();
	glutSwapBuffers();
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(750, 750);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Hello, Car!");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-20, 20, -20, 20);
	glutDisplayFunc(glDraw);
	glutTimerFunc(25, TimeStep, 25);
	glutMainLoop();
	return 0;
}