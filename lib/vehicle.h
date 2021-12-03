#ifndef VEHICLE_H
#define VEHICLE_H

#include <parking_lot.h>

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

#endif /* VEHICLE_H */
