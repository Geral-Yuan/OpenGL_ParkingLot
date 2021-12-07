#ifndef FIGURE_H
#define FIGURE_H

#include "parking_lot.h"

//class of all figures
class Figure
{
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() { return anchor; }
    void setAnchor(Vec a) { anchor = a; }
    virtual void draw() = 0;
    virtual ~Figure() {}

protected:
    Vec anchor;
};

//ColoredFig(Basic Shapes) that is Figure
class ColoredFig : public Figure
{
public:
    virtual void draw() = 0;

protected:
    double r, g, b;
};

class Quodrilateral : public ColoredFig
{
public:
    virtual void draw() = 0;
};

class Rec : public Quodrilateral
{
public:
    Rec(Vec anchor, Vec v1, Vec v2, double r = 0, double g = 0, double b = 0);
    void draw();
    void zoom(double k);

protected:
    Vec v1, v2;
};
class Trapezium : public Quodrilateral
{
public:
    Trapezium(Vec anchor, Vec v1, Vec v2, Vec v3, Vec v4, double r = 0, double g = 0, double b = 0);
    void draw();
    void zoom(double k);

protected:
    Vec v1, v2, v3, v4;
};

class Triangle : public ColoredFig
{
public:
    Triangle(Vec anchor, Vec v1, Vec v2, Vec v3, double r = 0, double g = 0, double b = 0);
    void draw();
    void zoom(double k);

protected:
    Vec v1, v2, v3;
};

class Poly : public ColoredFig
{
public:
    Poly(Vec anchor, int n = 4, double R = 1, double r = 0, double g = 0, double b = 0);
    void draw();
    void zoom(double k);

protected:
    int n;
    double R;
};

//Vehicle is a figure having other figures
class Vehicle : public Figure
{
public:
    Vehicle() : x_dir(0, 0), y_dir(0, 0) {}
    virtual void draw() = 0;
    void move(Vec dir);
    void rotate(double angle);
    //get and set position info
    Vec getxDir() { return x_dir; }
    Vec getyDir() { return y_dir; }
    void SetDir(Vec x_d, Vec y_d)
    {
        x_dir = x_d;
        y_dir = y_d;
    }
    //get status
    status_quo getstatus(){return cur_status;}
    //set status
    void Setstatus(status_quo _status){
        cur_status = _status;
    }
    //soon deprecated ticket functions
    void print_arr_ticket(int time, v_type type, int slot_num);
    void print_exit_ticket(int in_time, v_type type, int out_time);
    virtual ~Vehicle(){};

protected:
    //a vehicle consists of basic shapes
    Figure *Shape[10] = {0};
    //a vector showing the vehicles's heading direction
    Vec x_dir;
    Vec y_dir;
    //calculate the price at exit
    double cal_price(int in_time, v_type type, int out_time);
    status_quo cur_status;
};

//those that is vehicle
class Car : public Vehicle
{
public:
    //constructor
    Car(Vec anchor, Vec x_dir, Vec y_dir);
    //draw a car
    void draw();
    ~Car();
};
class Van : public Vehicle
{
public:
    //constructor
    Van(Vec anchor, Vec x_dir, Vec y_dir);
    //draw a car
    void draw();
    ~Van();
};
class Bicycle : public Vehicle
{
public:
    //constructor
    Bicycle(Vec anchor, Vec x_dir, Vec y_dir);
    //draw a car
    void draw();
    ~Bicycle();
};
class Motorcycle : public Vehicle
{
public:
    //constructor
    Motorcycle(Vec anchor, Vec x_dir, Vec y_dir);
    //draw a car
    void draw();
    ~Motorcycle();
};

#endif /* FIGURE_H */
