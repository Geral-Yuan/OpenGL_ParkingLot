#include "parking_lot.h"
//vehicles
//motion of vehicles
void Vehicle::move(double v)
{
	anchor = anchor + x_dir * v;
}
//rotation of vehicles
void Vehicle::rotate(double angle)
{
	x_dir = x_dir << angle;
	y_dir = y_dir << angle;
}
void Vehicle::Changestatus(int slot_num)
{
	if (slot < slot_num / 2 && cur_status == 1)
		cur_status = status_quo(cur_status + 3);
	else
		cur_status = status_quo(cur_status + 1);
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
}
void Car::draw()
{
	if (cur_status != PARK)
		move_flag();
	//anchors of shapes
	Vec v1 = y_dir * (-H / 2);
	Vec v2 = y_dir * (H / 2);
	Vec v3 = x_dir * (-d / 2) + y_dir * (-H);
	Vec v4 = x_dir * (d / 2) + y_dir * (-H);
	//lower body
	Vec v11 = x_dir * (L / 2) + y_dir * (H / 2);
	Vec v12 = x_dir * (L / 2) + y_dir * (-H / 2);
	Shape[0] = new Rec(anchor - y_dir * 2 + v1, v11, v12, 0.67, 0.51, 1);
	//upper body
	Vec v21 = x_dir * (d / 2) + y_dir * (H / 2);
	Vec v22 = x_dir * (d / 2 + s) + y_dir * (-H / 2);
	Vec v23 = x_dir * (-d / 2 - s) + y_dir * (-H / 2);
	Vec v24 = x_dir * (-d / 2) + y_dir * (H / 2);
	Shape[1] = new Trapezium(anchor - y_dir * 2 + v2, v21, v22, v23, v24, 0.54, 0.54, 0.54);
	//wheels
	Shape[2] = new Poly(anchor - y_dir * 2 + v3, 80, R, 0.1, 0.1, 0.1);
	Shape[3] = new Poly(anchor - y_dir * 2 + v4, 80, R, 0.1, 0.1, 0.1);
	//flag for bonus
	Vec v51 = y_dir * (H + flag_height);
	Vec v52 = y_dir * (H + 2 + flag_height);
	Vec v53 = x_dir * 3 + y_dir * (H + 1 + flag_height);
	Shape[4] = new Triangle(anchor - y_dir * 2, v51, v52, v53, 1.0, 0, 0);
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2d((anchor - y_dir * 2 + y_dir * H).getX(), (anchor - y_dir * 2 + y_dir * H).getY());
	glVertex2d((anchor + v51).getX(), (anchor + v51).getY());
	glEnd();
	for (int i = 0; i < 5; i++)
	{
		Shape[i]->draw();
		delete Shape[i];
	}
}
Car::~Car() {}

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
	Vec l1 = anchor + x_dir * (-3.0);
	Vec l2 = anchor + x_dir * (2.0) + y_dir * (7.0);
	Vec l3 = anchor + x_dir * (5.0) + y_dir * (-3.0);
	glColor3d(0.64, 0.82, 0.93);
	glBegin(GL_LINES);
	glVertex2d(l1.getX(), l1.getY());
	glVertex2d(l2.getX(), l2.getY());
	glVertex2d(l1.getX(), l1.getY());
	glVertex2d(l3.getX(), l3.getY());
	glEnd();
	Vec v11 = x_dir * (-4.0) + y_dir * (5.0);
	Vec v12 = x_dir * (-6.0 - 2.0 / 3.0) + y_dir * (5.0);
	Vec v13 = x_dir * (-5.0);
	Vec v14 = x_dir * (-3.0) + y_dir * (2.0);
	Shape[0] = new Trapezium(anchor, v11, v12, v13, v14, 0.5, 0.5, 0.5);
	Vec v21 = x_dir * (-2.0) + y_dir * (-1.0);
	Vec v22 = x_dir * (-4.0 - 2.0 / 3.0) + y_dir * (-1.0);
	Vec v23 = x_dir * (-3.0) + y_dir * (-6.0);
	Vec v24 = x_dir * (-1.0) + y_dir * (-4.0);
	Shape[1] = new Trapezium(anchor, v21, v22, v23, v24, 0.5, 0.5, 0.5);
	Vec v3 = x_dir * (-3.0);
	Shape[2] = new Half_Circle(anchor + v3, x_dir, y_dir, 100, sqrt(40), 0, 0.54, 0.54);
	for (int i = 0; i < 3; i++)
	{
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
	Vec v11 = (x_dir * (8.0) + y_dir * (3.0)) * change;
	Vec v12 = (x_dir * (8.0) + y_dir * (-3.0)) * change;
	Vec v13 = (x_dir * (-7.0) + y_dir * (-3.0)) * change;
	Vec v14 = (x_dir * (-7.0) + y_dir * (3.0)) * change;
	Shape[0] = new Trapezium(anchor, v11, v12, v13, v14, 1, 0.5, 0);
	Vec v21 = (x_dir * (1.0) + y_dir * (1.0)) * change;
	Vec v22 = (x_dir * (1.0) + y_dir * (-1.0)) * change;
	Vec v23 = (x_dir * (-2.0) + y_dir * (-1.0)) * change;
	Vec v24 = (x_dir * (-2.0) + y_dir * (1.0)) * change;
	Shape[1] = new Trapezium(anchor, v21, v22, v23, v24, 0.5, 0.5, 0.5);
	Vec v31 = (x_dir * (4.0) + y_dir * (2.0)) * change;
	Vec v32 = (x_dir * (4.0) + y_dir * (1.0)) * change;
	Vec v33 = (x_dir * (3.0) + y_dir * (1.0)) * change;
	Vec v34 = (x_dir * (3.0) + y_dir * (2.0)) * change;
	Shape[2] = new Trapezium(anchor, v31, v32, v33, v34, 0.5, 0.5, 0.5);
	Vec v41 = (x_dir * (4.0) + y_dir * (-1.0)) * change;
	Vec v42 = (x_dir * (4.0) + y_dir * (-2.0)) * change;
	Vec v43 = (x_dir * (3.0) + y_dir * (-2.0)) * change;
	Vec v44 = (x_dir * (3.0) + y_dir * (-1.0)) * change;
	Shape[3] = new Trapezium(anchor, v41, v42, v43, v44, 0.5, 0.5, 0.5);
	Vec v51 = (x_dir * (8.0) + y_dir * (3.0)) * change;
	Vec v52 = (x_dir * (8.0) + y_dir * (-3.0)) * change;
	Vec v53 = (x_dir * (12.0)) * change;
	Shape[4] = new Triangle(anchor, v51, v52, v53, 0.5, 0.5, 0.5);
	Vec v61 = (x_dir * (-1.0) + y_dir * (3.0)) * change;
	Vec v62 = (x_dir * (-7.0) + y_dir * (3.0)) * change;
	Vec v63 = (x_dir * (-7.0) + y_dir * (6.0)) * change;
	Shape[5] = new Triangle(anchor, v61, v62, v63, 0.5, 0.5, 0.5);
	Vec v71 = (x_dir * (-1.0) + y_dir * (-3.0)) * change;
	Vec v72 = (x_dir * (-7.0) + y_dir * (-3.0)) * change;
	Vec v73 = (x_dir * (-7.0) + y_dir * (-6.0)) * change;
	Shape[6] = new Triangle(anchor, v71, v72, v73, 0.5, 0.5, 0.5);
	Vec v81 = (x_dir * (-7.0) + y_dir * (2.0)) * change;
	Vec v82 = (x_dir * (-7.0) + y_dir * (-2.0)) * change;
	Vec v83 = (x_dir * (-9.0) + y_dir * (-3.0)) * change;
	Vec v84 = (x_dir * (-9.0) + y_dir * (3.0)) * change;
	Shape[7] = new Trapezium(anchor, v81, v82, v83, v84, 0.5, 0.5, 0.5);
	for (int i = 0; i < 8; i++)
	{
		Shape[i]->draw();
		delete Shape[i];
	}
}
Spacecraft::~Spacecraft()
{
}
Teleported::Teleported(Vec anchor, Vec v1, Vec v2, status_quo status)
{
	this->anchor = anchor;
	this->v1 = v1;
	this->v2 = v2;
	this->cur_status = status;
	color_change_time = 0;
	side = 3;
}
void Teleported::draw()
{
	if (color_change_time % 10 == 0)
	{
		r = (double)rand() / (double)RAND_MAX;
		g = (double)rand() / (double)RAND_MAX;
		b = (double)rand() / (double)RAND_MAX;
		if (color_change_time == 0)
		{
			side += 1;
			color_change_time = 400;
		}
	}
	color_change_time--;
	Poly polygon = Poly(anchor, side, 9.5, r, g, b);
	polygon.draw();
	/*
	Vec p1 = anchor + v1;
	Vec p2 = anchor + v2;
	Vec p3 = anchor - v1;
	Vec p4 = anchor - v2;
	glColor3d(r, g, b);
	glBegin(GL_QUADS);
	glVertex2d(p1.getX(), p1.getY());
	glVertex2d(p2.getX(), p2.getY());
	glVertex2d(p3.getX(), p3.getY());
	glVertex2d(p4.getX(), p4.getY());
	glEnd();
     */
}
