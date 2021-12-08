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

//some enum for status

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
            delete parking_lot;
            parking_lot = NULL;
        }
    }
    //set the slot per row
    void set_slot(int _slot){
        slot_num = 2 * _slot;
		empty_slot_num = slot_num;
        slots_order = new int[slot_num]();
		for (int i = 0; i < slot_num; i++)
			slots_order[i] = i;
    }
    //draw the car park
    void draw();
    //generate new vehicle
    void generate_vehicle();
    //move vehicle
	void move_vehicle();
    //delete the parking lot
    void delete_parking_lot(){
        delete_vehicle();
        delete_slot();
    }
};

#endif /* PARKING_LOT_H */
