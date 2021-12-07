#include "parking_lot.h"

void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, n);
	glutPostRedisplay();
}
void glDraw()
{
    single_park* carpark_map = single_park::get_instance();
    
    //drawing part
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //draw the parking lot
    carpark_map->draw();
    //draw all the vehicles
    /*
	for (int i = 0; i < 26; i++)
        //if the car is assigned a slot
		if (slot[i])
		{
            //read its current anchor and facing direction
			Vec anchor(state[i][0], state[i][1]), x_dir(state[i][2], state[i][3]), y_dir(-state[i][3], state[i][2]);
            //decide vehicle type
			if (i < 12)
				vehicle[i] = new Car(anchor, x_dir, y_dir);
			else if (i < 18)
				vehicle[i] = new Van(anchor, x_dir, y_dir);
			else if (i < 22)
				vehicle[i] = new Bicycle(anchor, x_dir, y_dir);
			else
				vehicle[i] = new Motorcycle(anchor, x_dir, y_dir);
			//Realize cars' park.
            //if not parked in
            int distance[26];
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
						park_in[i] = PARKED;
				}
				else
				{
					vehicle[i]->move(x_dir * (-1));
					distance[i] += 1;
					if ((i < 5 && distance[i] < 50 + 24 + 5 + 24 + 1 + 20 * (i + 1)) || (i > 5 && i < 12 && distance[i] < 50 + 24 + 90 + 24 + 24 + 5 + 24 + 1 + 20 * (i - 6)))
						vehicle[i]->rotate(PI / 48);
					if (vehicle[i]->getAnchor().getY() < 15.5 || vehicle[i]->getAnchor().getY() > 94.5)
						park_in[i] = PARKED;
				}
				state[i][0] = vehicle[i]->getAnchor().getX();
				state[i][1] = vehicle[i]->getAnchor().getY();
				state[i][2] = vehicle[i]->getxDir().getX();
				state[i][3] = vehicle[i]->getxDir().getY();
			}
			vehicle[i]->draw();
		}
    //generate new vehicles
	if (t % 300 == 0)
	{
		int k = rand() % 12;
		if (!slot[k])
		{
            //get the assigned slot occupied
			slot[k] = OCCUPIED;
            //assign innitial index position
			state[k][0] = 30;
			state[k][1] = -25;
			state[k][2] = 0;
			state[k][3] = 1;
            //save the arrival time
			arr_time[k] = t;
            //initially generated spot
			Vec anchor(30, -25), x_dir(0, 1), y_dir(-1, 0);
            //judge which vehicle it is and print arrival ticket
			if (k < 12)
			{
				vehicle[k] = new Car(anchor, x_dir, y_dir);
				distance[k] = 0;
                vehicle[k]->print_arr_ticket(t,CAR,k+1);
			}
			else if (k < 18)
            {
				vehicle[k] = new Van(anchor, x_dir, y_dir);
                distance[k] = 0;
            }
			else if (k < 22)
            {
				vehicle[k] = new Bicycle(anchor, x_dir, y_dir);
                distance[k] = 0;
            }
			else
            {
				vehicle[k] = new Motorcycle(anchor, x_dir, y_dir);
                distance[k] = 0;
            }
		}
	}
     */
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char *argv[])
{
    //use commandline argument to specify the number of slots per row
    int slot_num_per_row = 6;
    char c  = 0;
    while((c = getopt(argc,argv,"n:")) != -1){
        switch(c){
            case 'n':
                slot_num_per_row = atoi(optarg);
                break;
        }
    }
    //initialize a singleton parking lot with its slot number per row
    single_park* carpark_map = single_park::get_instance();
    carpark_map->set_slot(slot_num_per_row);
	glutInit(&argc, argv);
    //set the window size accoring to user input
	glutInitWindowSize((20*slot_num_per_row+80)*3, 510);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGB);
    //create the window and clear the background
	glutCreateWindow("INTERSTELLAR PARKING LOT");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
    //set the range of the x&y axis
	gluOrtho2D(-40, 20*slot_num_per_row+40, -50, 120);
	srand((unsigned int)time(NULL));
	glutDisplayFunc(glDraw);
	glutTimerFunc(25, TimeStep, 25);
	glutMainLoop();
	return 0;
}
