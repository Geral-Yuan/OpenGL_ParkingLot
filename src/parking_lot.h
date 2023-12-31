//
//  parking_lot.h
//
#ifndef PARKING_LOT_H
#define PARKING_LOT_H
//system judge
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#elif _WIN32
#include <GL/freeglut.h>
#include <windows.h>
#elif _WIN64
#include <GL/freeglut.h>
#include <windows.h>
#elif __linux__
#include <GL/freeglut.h>
#endif

//C++ libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <vector>
#include <getopt.h>
using namespace std;

//define vector class for anchors
#include "vector.h"

//define all figures
#include "figure.h"

//draw the parking area
void parking_area_draw();

//singleton trial
class single_park{
private:
    int slot_num;
	int empty_slot_num;
    vector<Vehicle*> all_vehicles;
    int* slots_order;
	int bar_open_time=0;
    single_park(){}
    ~single_park(){}
    //delete vehicle
    void delete_vehicle();
    //free the memory allocated
    void delete_slot(){
        delete[] slots_order;
    }
public:
    static single_park* get_instance(){
        static single_park *parking_lot = NULL;
        if (parking_lot == NULL)
            parking_lot = new single_park();
        return parking_lot;
    }
    static void delete_instance(){
        single_park* parking_lot = single_park::get_instance();
        if(parking_lot != NULL){
			parking_lot->delete_vehicle();
        	parking_lot->delete_slot();
            delete parking_lot;
            parking_lot = NULL;
        }
    }
    //set the number of slots
    void set_slot(int _slot){
        slot_num = 2 * _slot;
		empty_slot_num = slot_num;//initialise the number of empty slots
        slots_order = new int[slot_num]();
		for (int i = 0; i < slot_num; i++)
			slots_order[i] = i;//initialise the order of each slot.
    }
    //draw the car park
    void draw();
    //generate new vehicle
    void generate_vehicle();
    //move vehicle
	void move_vehicle();
    //open and close the barrier at the entrance
	void move_barrier(){
		glColor3d(1, 0, 0);
		glBegin(GL_LINES);
		//One point fixed
		glVertex2d(0, 0);
		if (bar_open_time > 0)
		{
			if (bar_open_time > 70)//open the barrier
				glVertex2d(-25 * cos(PI / 40 * (90 - bar_open_time)), 25 * sin(PI / 40 * (90 - bar_open_time)));
			else if (bar_open_time <= 20)//close the barrier
				glVertex2d(-25 * cos(PI / 40 * bar_open_time), 25 * sin(PI / 40 * bar_open_time));
			else
				glVertex2d(0, 25);//keep open while a vehicle is entering
			bar_open_time -= 1;
		}
		else
			glVertex2d(-25, 0);//keep close while no vehicle arrives
		glEnd();
	}
};

#endif /* PARKING_LOT_H */
