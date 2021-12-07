#include "parking_lot.h"
//vehicles
//motion of vehicles
void Vehicle::move(Vec dir)
{
	anchor = anchor + dir;
}
//rotation of vehicles
void Vehicle::rotate(double angle)
{
	x_dir = x_dir << angle;
	y_dir = y_dir << angle;
}
//car that is a vehicle
Car::Car(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step, status_quo status)
{
	this->slot = slot;
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
	this->remain_step = step;
	this->cur_status = status;
	double L = 20, H = 6, d = 10, s = 3, R = 2;
	Vec v1 = y_dir * (-H / 2);
	Vec v2 = y_dir * (H / 2);
	Vec v3 = x_dir * (-d / 2) + y_dir * (-H);
	Vec v4 = x_dir * (d / 2) + y_dir * (-H);
	Vec v11 = x_dir * (L / 2) + y_dir * (H / 2);
	Vec v12 = x_dir * (L / 2) + y_dir * (-H / 2);
	Shape[0] = new Rec(anchor + v1, v11, v12, 0, 1, 0);
	Vec v21 = x_dir * (d / 2) + y_dir * (H / 2);
	Vec v22 = x_dir * (d / 2 + s) + y_dir * (-H / 2);
	Vec v23 = x_dir * (-d / 2 - s) + y_dir * (-H / 2);
	Vec v24 = x_dir * (-d / 2) + y_dir * (H / 2);
	Shape[1] = new Trapezium(anchor + v2, v21, v22, v23, v24, 0, 0, 1);
	Shape[2] = new Poly(anchor + v3, 80, R, 1, 0, 0);
	Shape[3] = new Poly(anchor + v4, 80, R, 1, 0, 0);
}
void Car::draw()
{
	for (int i = 0; i < 4; i++)
		Shape[i]->draw();
}
Car::~Car()
{
	for (int i = 0; i < 4; i++)
		delete Shape[i];
}

//UFO that is a vehicle
UFO::UFO(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step, status_quo status)
{
	this->slot = slot;
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
	this->remain_step = step;
	this->cur_status = status;
}
void UFO::draw()
{
}
UFO::~UFO()
{
}

//spacecraft that is a vehicle
Spacecraft::Spacecraft(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step, status_quo status)
{
	this->slot = slot;
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
	this->remain_step = step;
	this->cur_status = status;
}
void Spacecraft::draw()
{
}
Spacecraft::~Spacecraft()
{
}
