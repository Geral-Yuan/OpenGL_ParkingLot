//
//  carpark.h
//  
//
//  Created by Elaine Liu on 2021/12/2.
//

#ifndef PARKING_LOT_H
#define PARKING_LOT_H

#ifdef __APPLE__
#ifndef JOJ
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#endif
#elif _WIN32
#include <GL/freeglut.h>
#include <windows.h>
#elif _WIN64
#include <GL/freeglut.h>
#include <windows.h>
#elif __linux__
#include <GL/freeglut.h>
#endif

#include <math.h>
#include <iostream>

using namespace std;

enum v_type {CAR, VAN, MOTOR, BIKE};
enum slot_state {EMPTY,OCCUPIED};

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
    Vec* anchor;
};

//Vehicle is a figure having other figures
class Vehicle : public Figure{
public:
    //draw a vehicle(different ways)
    virtual void draw() = 0;
    //move a vehicle
    void move(Vec* dir);
    //rotate a vehicle
    void rotate(double angle);
    //calculate the price for parking
    int get_price(int in_time, int out_time);
    virtual ~Figure() {}
protected:
    //a vehicle consists of basic shapes
    Figure Shape[10] = {0};
    //a vector showing the vehicles's heading direction
    Vec* x_dir;
    Vec* y_dir;
};

//those that is vehicle
class Car : public Vehicle{
public:
    //constructor
    Car(Vec* anchor, Vec* x_dir, Vec* y_dir);
    //draw a car
    void draw();
};
class Van : public Vehicle{
public:
    //constructor
    Van(Vec* anchor, Vec* x_dir, Vec* y_dir);
    //draw a car
    void draw();
};
class Bicycle : public Vehicle{
public:
    //constructor
    Bicycle(Vec* anchor, Vec* x_dir, Vec* y_dir);
    //draw a car
    void draw();
};
class Motorcycle : public Vehicle{
public:
    //constructor
    Motorcycle(Vec* anchor, Vec* x_dir, Vec* y_dir);
    //draw a car
    void draw();
};


class Ticket{
public:
    virtual void print() = 0;
    //get the time of the ticket
    int get_time(){return time;}
    //set the time of the ticket
    void set_time(int current_time){time = current_time;}
    virtual ~Ticket() = 0;
protected:
    int time;
    v_type type;
}


class Arr_ticket : public Ticket{
public:
    //generate an arrival ticket
    Arr_ticket(Vec* _anchor, int _time, v_type _type){
        anchor = _anchor;
        time = _time;
        type = _type;
    }
    //print
    void print(){
        string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
        cout << "----------Arrival Ticket----------" << endl;
        cout << "Time of arrival: " << duration << ";" << endl;
        cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
        cout << "Empty slot: " <<  << ";" << endl;
    }
private:
    //every enter ticket is linked to the anchor of a slot
    Vec* anchor;
}

class Dep_ticket : public Ticker{
public:
    //generate a departure ticket
    Dep_ticket(int _time, v_type _type){
        duration = _time;
        type = _type;
    }
    //print
    void print(){
        string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
        cout << "----------Departure Ticket----------" << endl;
        cout << "Time spent in the parking lot: " << duration << ";" << endl;
        cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
        cout << "Price: " << price << ";" << endl;
    }
    //set the price on the ticket
    void set_price(int _price){price = _price;}
private:
    int price;
}
#endif /* PARKING_LOT_H */
