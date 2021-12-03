#include "parking_lot.h"
Car::Car(Vec anchor, Vec x_dir, Vec y_dir)
{
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
	double L = 4;
	double H = 1;
	double d = 2;
	double s = 0.5;
	double R = 0.3;
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
void Car::move(Vec dir)
{
	anchor = anchor + dir * 0.1;
}
void Car::rotate(double angle)
{
	x_dir = x_dir << angle;
	y_dir = y_dir << angle;
}