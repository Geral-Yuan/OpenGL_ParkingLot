#include "parking_lot.h"

void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, n);
	glutPostRedisplay();
}
void glDraw()
{
	single_park *carpark_map = single_park::get_instance();
	static int t = 0;
	static int bar_open_time = 0;
	//drawing part
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//draw the parking lot
	carpark_map->draw();
	//generate a new vehicle
	if (t % 300 == 0)
		carpark_map->generate_vehicle(&bar_open_time);
	glColor3d(1, 0, 0);
	glBegin(GL_LINES);
	glVertex2d(0, 0);
	if (bar_open_time > 0)
	{
		if (bar_open_time > 70)
			glVertex2d(-25 * cos(PI / 40 * (90 - bar_open_time)), 25 * sin(PI / 40 * (90 - bar_open_time)));
		else if (bar_open_time <= 20)
			glVertex2d(-25 * cos(PI / 40 * bar_open_time), 25 * sin(PI / 40 * bar_open_time));
		else
			glVertex2d(0, 25);
		bar_open_time -= 1;
	}
	else
		glVertex2d(-25, 0);
	glEnd();
	//move and draw the vehicle
	carpark_map->move_vehicle();
	glutSwapBuffers();
	glFlush();
	t++;
}

int main(int argc, char *argv[])
{
	//use commandline argument to specify the number of slots per row
	int slot_num_per_row = 6;
	char c = 0;
	while ((c = getopt(argc, argv, "n:")) != -1)
	{
		switch (c)
		{
		case 'n':
			slot_num_per_row = atoi(optarg);
			break;
		}
	}
	//initialize a singleton parking lot with its slot number per row
	single_park *carpark_map = single_park::get_instance();
	carpark_map->set_slot(slot_num_per_row);
	glutInit(&argc, argv);
	//set the window size accoring to user input
	glutInitWindowSize((20 * slot_num_per_row + 80) * 3, 510);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
	//create the window and clear the background
	glutCreateWindow("INTERSTELLAR PARKING LOT");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//set the range of the x&y axis
	gluOrtho2D(-40, 20 * slot_num_per_row + 40, -50, 120);
	srand((unsigned int)time(NULL));
	glutDisplayFunc(glDraw);
	glutTimerFunc(25, TimeStep, 25);
	glutMainLoop();
	carpark_map->delete_parking_lot();
	carpark_map->delete_instance();
	return 0;
}
