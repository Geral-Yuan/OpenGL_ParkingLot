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
    L = 20;H = 6;d = 10;s = 3;R = 2;
}
void Car::draw()
{
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
    for (int i = 0; i < 4; i++){
		Shape[i]->draw();
        delete Shape[i];
    }
}
Car::~Car(){}

//UFO that is a vehicle
Ufo::Ufo(int slot, Vec anchor, Vec x_dir, Vec y_dir, int step, status_quo status)
{
	this->slot = slot;
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
	this->remain_step = step;
	this->cur_status = status;
}
void Ufo::draw()
{
    spin();
    Vec l1 = anchor+ x_dir*(-3.0);
    Vec l2 = anchor+ x_dir*(2.0)+ y_dir*(7.0);
    Vec l3 = anchor+ x_dir*(5.0)+ y_dir*(-3.0);
    glColor3d(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    glVertex2d(l1.getX(), l1.getY());
    glVertex2d(l2.getX(), l2.getY());
    glVertex2d(l1.getX(), l1.getY());
    glVertex2d(l3.getX(), l3.getY());
    glEnd();
    Vec v11 = x_dir*(-4.0)+ y_dir*(5.0);
    Vec v12 = x_dir*(-6.0-2.0/3.0)+ y_dir*(5.0);
    Vec v13 = x_dir*(-5.0);
    Vec v14 = x_dir*(-3.0)+ y_dir*(2.0);
    Shape[0] = new Trapezium(anchor,v11,v12,v13,v14,0.5,0.5,0.5);
    Vec v21 = x_dir*(-2.0)+ y_dir*(-1.0);
    Vec v22 = x_dir*(-4.0-2.0/3.0)+ y_dir*(-1.0);
    Vec v23 = x_dir*(-3.0)+y_dir*(-6.0);
    Vec v24 = x_dir*(-1.0)+ y_dir*(-4.0);
    Shape[1] = new Trapezium(anchor,v21,v22,v23,v24,0.5,0.5,0.5);
    Vec v3 = x_dir*(-3.0);
    Shape[2] = new Half_Circle(anchor+v3,x_dir,y_dir,100,sqrt(40),0.5,0.5,0.5);
    for (int i = 0; i < 3; i++){
        Shape[i]->draw();
        delete Shape[i];
    }
}
Ufo::~Ufo()
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
    zoom();
    Vec v11 = (x_dir*(8.0) + y_dir*(3.0))*change;
    Vec v12 = (x_dir*(8.0) + y_dir*(-3.0))*change;
    Vec v13 = (x_dir*(-7.0) + y_dir*(-3.0))*change;
    Vec v14 = (x_dir*(-7.0) + y_dir*(3.0))*change;
    Shape[0] = new Trapezium(anchor,v11,v12,v13,v14,1,0.0,0.2);
    Vec v21 = (x_dir*(1.0) + y_dir*(1.0))*change;
    Vec v22 = (x_dir*(1.0) + y_dir*(-1.0))*change;
    Vec v23 = (x_dir*(-2.0) + y_dir*(-1.0))*change;
    Vec v24 = (x_dir*(-2.0) + y_dir*(1.0))*change;
    Shape[1] = new Trapezium(anchor,v21,v22,v23,v24,0.5,0.5,0.5);
    Vec v31 = (x_dir*(4.0) + y_dir*(2.0))*change;
    Vec v32 = (x_dir*(4.0) + y_dir*(1.0))*change;
    Vec v33 = (x_dir*(3.0) + y_dir*(1.0))*change;
    Vec v34 = (x_dir*(3.0) + y_dir*(2.0))*change;
    Shape[2] = new Trapezium(anchor,v31,v32,v33,v34,0.5,0.5,0.5);
    Vec v41 = (x_dir*(4.0) + y_dir*(-1.0))*change;
    Vec v42 = (x_dir*(4.0) + y_dir*(-2.0))*change;
    Vec v43 = (x_dir*(3.0) + y_dir*(-2.0))*change;
    Vec v44 = (x_dir*(3.0) + y_dir*(-1.0))*change;
    Shape[3] = new Trapezium(anchor,v41,v42,v43,v44,0.5,0.5,0.5);
    Vec v51 = (x_dir*(8.0) + y_dir*(3.0))*change;
    Vec v52 = (x_dir*(8.0) + y_dir*(-3.0))*change;
    Vec v53 = (x_dir*(12.0))*change;
    Shape[4] = new Triangle(anchor,v51,v52,v53,0.5,0.5,0.5);
    Vec v61 = (x_dir*(-1.0) + y_dir*(3.0))*change;
    Vec v62 = (x_dir*(-7.0) + y_dir*(3.0))*change;
    Vec v63 = (x_dir*(-7.0) + y_dir*(6.0))*change;
    Shape[5] = new Triangle(anchor,v61,v62,v63,0.5,0.5,0.5);
    Vec v71 = (x_dir*(-1.0) + y_dir*(-3.0))*change;
    Vec v72 = (x_dir*(-7.0) + y_dir*(-3.0))*change;
    Vec v73 = (x_dir*(-7.0) + y_dir*(-6.0))*change;
    Shape[6] = new Triangle(anchor,v71,v72,v73,0.5,0.5,0.5);
    Vec v81 = (x_dir*(-7.0) + y_dir*(2.0))*change;
    Vec v82 = (x_dir*(-7.0) + y_dir*(-2.0))*change;
    Vec v83 = (x_dir*(-9.0) + y_dir*(-3.0))*change;
    Vec v84 = (x_dir*(-9.0) + y_dir*(3.0))*change;
    Shape[7] = new Trapezium(anchor,v81,v82,v83,v84,0.5,0.5,0.5);
    for (int i = 0; i < 8; i++){
        Shape[i]->draw();
        delete Shape[i];
    }
}
Spacecraft::~Spacecraft()
{
}
