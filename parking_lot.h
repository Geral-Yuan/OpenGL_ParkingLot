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
using namespace std;

//constant definition
#define PI acos(-1) /* pi */

//define vector class for anchors
#include "Vector.h"

//some enum for status
enum v_type{CAR,VAN,BICYCLE,MOTORCYCLE};
enum slot_state{EMPTY,OCCUPIED};
enum is_parked{NOT_PARKED,PARKED};

//define all figures
#include "Figure.h"

//draw the parking area
void parking_area_draw();

#endif /* PARKING_LOT_H */
