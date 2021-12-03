//
//  carpark.h
//
//
//  Created by Elaine Liu on 2021/12/2.
//
#ifndef PARKING_LOT_H
#define PARKING_LOT_H
//system judgement issue
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

//original libraries included
#include <cmath>
#include <iostream>

//own header included

///header file specifying vector operation
#include "vector.h"

///header file specifying figures
#include "coloredfigs.h" /* basic shapes */
#include "vehicles.h" /* vehicles */

///header file specifying tickets
#include "ticket.h"

using namespace std;

//constant definition
#define PI acos(-1) /* pi */
enum v_type {CAR, VAN, MOTOR, BIKE};/* for vehicle type */
enum slot_state {EMPTY,OCCUPIED};/* slot state */

//the class of figure
class Figure {
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() {return anchor;}
    void setAnchor(Vec a) {anchor = a;}
    virtual void draw() = 0;
    virtual void move(Vec dir) = 0;
    virtual void rotate(float angle) = 0;
    virtual void zoom(float k) = 0;
    virtual ~Figure() {}
    
protected:
    Vec anchor;
};





#endif /* PARKING_LOT_H */
