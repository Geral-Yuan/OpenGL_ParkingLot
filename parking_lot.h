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
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <getopt.h>
using namespace std;

//constant definition
#define PI acos(-1) /* pi */

//define vector class for anchors
#include "vector.h"

//some enum for status
enum v_type{CAR,UFO,SPACECRAFT};
enum slot_state{EMPTY,OCCUPIED};
enum is_parked{NOT_PARKED,PARKED};
enum status_quo{FORWARD,F2B,BACK,RIGHT,LEFT};

//define all figures
#include "figure.h"

//draw the parking area
void parking_area_draw();


//singleton trial
class single_park{
private:
    int slot_num;
    vector<Vehicle*> all_vehicles;
    slot_state* all_slots;
    is_parked* park_in;
    single_park(){}
    ~single_park(){}
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
        slot_num = _slot;
        all_slots = new slot_state[_slot]{};
        park_in = new is_parked[_slot]{};
    }
    //draw the car park
    void draw();
};

#endif /* PARKING_LOT_H */
