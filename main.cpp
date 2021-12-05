#include "parking_lot.h"
void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, n);
	glutPostRedisplay();
}
void glDraw()
{
	static int t = 0;
	Vehicle *vehicle[26];
	static bool slot[26] = {EMPTY};
	static bool park_in[26] = {0};
	static double state[26][4];
	static double distance[26];
	//static int time[26][2];
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 26; i++)
		if (slot[i])
		{
			Vec anchor(state[i][0], state[i][1]), x_dir(state[i][2], state[i][3]), y_dir(-state[i][3], state[i][2]);
			if (i < 12)
				vehicle[i] = new Car(anchor, x_dir, y_dir);
			else if (i < 18)
				vehicle[i] = new Van(anchor, x_dir, y_dir);
			else if (i < 22)
				vehicle[i] = new Bicycle(anchor, x_dir, y_dir);
			else
				vehicle[i] = new Motorcycle(anchor, x_dir, y_dir);
			//Realize cars' park.
			if (!park_in[i])
			{
				if ((i < 5 && distance[i] < 50 + 24 + 5 + 20 * (i + 1)) || (i == 5 && distance[i] < 50 + 24 + 90 + 24 - 1) || (i > 5 && i < 12 && distance[i] < 50 + 24 + 90 + 24 + 24 + 5 + 20 * (i - 6)))
				{
					vehicle[i]->move(x_dir);
					distance[i] += 1;
					if (distance[i] >= 50 && distance[i] < 50 + 24)
						vehicle[i]->rotate(-PI / 48);
					if (i != 4)
						if (distance[i] >= 50 + 24 + 90 && distance[i] < 50 + 24 + 90 + 24 + 24)
							vehicle[i]->rotate(PI / 48);
				}
				else if (i == 5 && distance[i] < 50 + 24 + 90 + 24 + 40)
				{
					vehicle[i]->move(x_dir * (-1));
					distance[i] += 1;
					if (vehicle[i]->getAnchor().getY() < 15.5)
						park_in[i] = true;
				}
				else
				{
					vehicle[i]->move(x_dir * (-1));
					distance[i] += 1;
					if ((i < 5 && distance[i] < 50 + 24 + 5 + 24 + 1 + 20 * (i + 1)) || (i > 5 && i < 12 && distance[i] < 50 + 24 + 90 + 24 + 24 + 5 + 24 + 1 + 20 * (i - 6)))
						vehicle[i]->rotate(PI / 48);
					if (vehicle[i]->getAnchor().getY() < 15.5 || vehicle[i]->getAnchor().getY() > 94.5)
						park_in[i] = true;
				}
				state[i][0] = vehicle[i]->getAnchor().getX();
				state[i][1] = vehicle[i]->getAnchor().getY();
				state[i][2] = vehicle[i]->getxDir().getX();
				state[i][3] = vehicle[i]->getxDir().getY();
			}
			vehicle[i]->draw();
		}
	if (t % 300 == 0)
	{
		int k = rand() % 12;
		if (!slot[k])
		{
			slot[k] = OCCUPIED;
			state[k][0] = 30;
			state[k][1] = -25;
			state[k][2] = 0;
			state[k][3] = 1;
			//time[k][0] = t;
			Vec anchor(30, -25), x_dir(0, 1), y_dir(-1, 0);
			if (k < 12)
			{
				vehicle[k] = new Car(anchor, x_dir, y_dir);
				distance[k] = 0;
			}
			else if (k < 18)
				vehicle[k] = new Van(anchor, x_dir, y_dir);
			else if (k < 22)
				vehicle[k] = new Bicycle(anchor, x_dir, y_dir);
			else
				vehicle[k] = new Motorcycle(anchor, x_dir, y_dir);
		}
	}
	glutSwapBuffers();
	glFlush();
	t++;
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(468, 728);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Hello, Car!");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-10, 170, -40, 240);
	srand((size_t)time(NULL));
	glutDisplayFunc(glDraw);
	glutTimerFunc(25, TimeStep, 25);
	glutMainLoop();
	return 0;
}