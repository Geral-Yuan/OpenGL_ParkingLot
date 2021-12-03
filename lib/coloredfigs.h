#ifndef COLOREDFIGS_H
#define COLOREDFIGS_H

#include "parking_lot.h"

//coloredfigs for basic shapes inheritting figure
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

protected:
};

class Rectangle : public Quodrilateral
{
public:
	Rectangle(Vec *v1, Vec *v2, double r = 0, double g = 0, double b = 0);
	void draw();
	void zoom(double k);

protected:
	Vec *v1, *v2;
};
class Trapezium : public Quodrilateral
{
public:
	Trapezium(Vec *v1, Vec *v2, Vec *v3, Vec *v4, double r = 0, double g = 0, double b = 0);
	void draw();
	void zoom(double k);

protected:
	Vec *v1, *v2, *v3, *v4;
};
class Triangle : public ColoredFig
{
public:
	Triangle(Vec *v1, Vec *v2, Vec *v3, double r = 0, double g = 0, double b = 0);
	void draw();
	void zoom(double k);

protected:
	Vec *v1, *v2, *v3;
};
class Polygon : public ColoredFig
{
public:
	Polygon(int n = 4, double R = 1, double r = 0, double g = 0, double b = 0);
	void draw();
	void zoom(double k);

protected:
	int n;
	double R;
};

#endif /* COLOREDFIG_H */
