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
#include <cmath>
#include <iostream>
using namespace std;
#define PI acos(-1) /* pi */
class Vec {
private:
    float x, y;

public:
    Vec(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    float getX() { return x; }
    float getY() { return y; }

    // Example Overloads + operator
    // returns the sum of 2 Vec
    Vec operator+(Vec v)
    {
        return Vec(x + v.x, y + v.y);
    }

    // Overload - on 2 Vectors
    // return thier difference Vector
    Vec operator-(Vec v)
    {
        return Vec(x - v.x, y - v.y);
    }

    // Overload * operator on a float k
    // return current Vector scaled by k
    Vec operator*(float k)
    {
        return Vec(x * k, y * k);
    }

    // Overload * on 2 Vectors
    // return thier inner product (scaler product)
    float operator*(Vec v)
    {
        return x * v.x + y * v.y;
    }

    // Overload << on an angle
    // return current vector rotated counter clockwise
    // by this angle
    Vec operator<<(double theta)
    {
        return Vec(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }

    // Overload >> on an angle
    // return current vector rotated clockwise
    // by this angle
    Vec operator>>(double theta)
    {
        return Vec(x * cos(theta) + y * sin(theta), -x * sin(theta) + y * cos(theta));
    }
};

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
    Vec anchor;
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
	Vec getxDir(){return x_dir;}
	Vec getyDir(){return y_dir;}
	void SetDir(Vec x_d,Vec y_d){x_dir = x_d; y_dir = y_d;}
    virtual ~Vehicle() = 0;
protected:
    //a vehicle consists of basic shapes
    Figure* Shape[10] = {0};
    //a vector showing the vehicles's heading direction
    Vec x_dir;
    Vec y_dir;
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
};


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
        cout << "Time of arrival: " << time << ";" << endl;
        cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
        cout << "Empty slot: "<< ";" << endl;
    }
private:
    //every enter ticket is linked to the anchor of a slot
    Vec* anchor;
};

class Dep_ticket : public Ticket{
public:
    //generate a departure ticket with time: duration
    Dep_ticket(int _time, v_type _type){
        time = _time;
        type = _type;
    }
    //calculate the price
    void cal_price(){
        int type_prize[4] = {10,20,30,40};
        price = type_prize[type]*time;
    }
    //print
    void print(){
        string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
        cout << "----------Departure Ticket----------" << endl;
        cout << "Time spent in the parking lot: " << time << ";" << endl;//duration
        cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
        cout << "Price: " << price << ";" << endl;
    }
    //set the price on the ticket
    void set_price(int _price){price = _price;}
private:
    int price;
};
#endif /* PARKING_LOT_H */