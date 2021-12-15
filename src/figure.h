#ifndef FIGURE_H
#define FIGURE_H

#include "vector.h"
//some enum for vehicle type
enum v_type
{
	CAR,
	UFO,
	SPACECRAFT,
	TELEPORTED
};
//some enum for status
enum status_quo
{
	GET_IN,
	TURN_RIGHT,
	ACROSS,
	TURN_ROUND,
	REACH_SLOT,
	BACK,
	PARK_IN,
	PARK
};

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

class Rec : public ColoredFig
{
public:
	Rec(Vec anchor, Vec v1, Vec v2, double r = 0, double g = 0, double b = 0);
	void draw();

protected:
	Vec v1, v2;
};
class Trapezium : public ColoredFig
{
public:
	Trapezium(Vec anchor, Vec v1, Vec v2, Vec v3, Vec v4, double r = 0, double g = 0, double b = 0);
	void draw();

protected:
	Vec v1, v2, v3, v4;
};

class Triangle : public ColoredFig
{
public:
	Triangle(Vec anchor, Vec v1, Vec v2, Vec v3, double r = 0, double g = 0, double b = 0);
	void draw();

protected:
	Vec v1, v2, v3;
};

class Poly : public ColoredFig
{
public:
	Poly(Vec anchor, int n = 4, double R = 1, double r = 0, double g = 0, double b = 0);
	void draw();

private:
	int n;
	double R;
};

class Half_Circle : public ColoredFig
{
public:
	Half_Circle(Vec anchor, Vec x_dir, Vec y_dir, int n = 200, double R = 1, double r = 0, double g = 0, double b = 0);
	void draw();

private:
	int n;
	double R;
	Vec x_dir;
	Vec y_dir;
};

//Vehicle is a figure having other figures
class Vehicle : public Figure
{
public:
	Vehicle() : x_dir(0, 1), y_dir(-1, 0) {}
	virtual void draw() = 0;
	void move(double v);
	void rotate(double angle);
	//get direction
	Vec getxDir() { return x_dir; }
	//get status
	status_quo Getstatus(){return cur_status;}
	//change status
	void Changestatus(int slot_num);
	//set steps
	void Setstep(int _step) { remain_step = _step; }
	//get steps
	int Getstep() { return remain_step; }
	//get slot
	int Getslot() { return slot; }
	~Vehicle(){};

protected:
	//a vehicle consists of basic shapes
	ColoredFig *Shape[10] = {0};
	//a vector showing the vehicles's heading direction
	Vec x_dir;
	Vec y_dir;
	status_quo cur_status;
	int remain_step;
	int slot;
};

//those that is vehicle
class Car : public Vehicle
{
private:
	double L=20, H=6, d=10, s=3, R=2;
    double flag_height=0;
    bool flag=0;
    void move_flag(){
        if(flag_height-0<=0.001)
            flag = 1;
        if(2-flag_height<=0.001)
            flag = 0;
        if(flag == 0)
            flag_height -=0.5;
        if(flag ==1)
            flag_height +=0.5;
    }
public:
	//constructor
	Car(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step = 50, status_quo status = GET_IN);
	//draw a car
	void draw();
	~Car();
};
class Ufo : public Vehicle
{
private:
	int count = 0;
	void spin()
	{
		if (count++ % 10 == 0)
			y_dir = y_dir * (-1);
	}

public:
	//constructor
	Ufo(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step = 50, status_quo status = GET_IN);
	//draw a UFO
	void draw();
	~Ufo();
};
class Spacecraft : public Vehicle
{
private:
	double change = 1.00;
	bool flag = 0;
	void zoom()
	{
		if (abs(1.25 - change) < 0.001)
			flag = 1;
		if (abs(change - 0.25) < 0.001)
			flag = 0;
		if (flag == 0)
			change += 0.01;
		if (flag == 1)
			change -= 0.01;
	}

public:
	//constructor
	Spacecraft(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step = 50, status_quo status = GET_IN);
	//draw a car
	void draw();
	~Spacecraft();
};
class Teleported : public Vehicle
{
public:
	Teleported(Vec anchor, Vec v1, Vec v2, status_quo status = PARK);
	void draw();

private:
	Vec v1, v2;
	int color_change_time;
    int side;
	double r, g, b;
};

#endif /* FIGURE_H */
