#include "Figure.h"
Rectangle::Rectangle(Vec *v1, Vec *v2, double r, double g, double b)
{
	this->v1 = v1;
	this->v2 = v2;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Rectangle::draw()
{
	Vec p1 = anchor + *v1;
	Vec p2 = anchor + *v2;
	Vec p3 = anchor - *v1;
	Vec p4 = anchor - *v2;
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2d(p1.getX(), p1.getY());
	glVertex2d(p2.getX(), p2.getY());
	glVertex2d(p3.getX(), p3.getY());
	glVertex2d(p4.getX(), p4.getY());
	glEnd();
}
void Rectangle::zoom(double k)
{
	anchor = anchor * k;
	*v1 = *v1 * k;
	*v2 = *v2 * k;
}
Trapezium::Trapezium(Vec *v1, Vec *v2, Vec *v3, Vec *v4, double r, double g, double b)
{
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
	this->v4 = v4;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Trapezium::draw()
{
	Vec p1 = anchor + *v1;
	Vec p2 = anchor + *v2;
	Vec p3 = anchor + *v3;
	Vec p4 = anchor + *v4;
	glColor3f(r, g, b);
	glBegin(GL_QUADS);
	glVertex2d(p1.getX(), p1.getY());
	glVertex2d(p2.getX(), p2.getY());
	glVertex2d(p3.getX(), p3.getY());
	glVertex2d(p4.getX(), p4.getY());
	glEnd();
}
void Trapezium::zoom(double k)
{
	anchor = anchor * k;
	*v1 = *v1 * k;
	*v2 = *v2 * k;
	*v3 = *v3 * k;
	*v4 = *v4 * k;
}
Triangle::Triangle(Vec *v1, Vec *v2, Vec *v3, double r, double g, double b)
{
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Triangle::draw()
{
	Vec p1 = anchor + *v1;
	Vec p2 = anchor + *v2;
	Vec p3 = anchor + *v3;
	glColor3f(r, g, b);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(p1.getX(), p1.getY());
	glVertex2d(p2.getX(), p2.getY());
	glVertex2d(p3.getX(), p3.getY());
	glEnd();
}
void Triangle::zoom(double k)
{
	anchor = anchor * k;
	*v1 = *v1 * k;
	*v2 = *v2 * k;
	*v3 = *v3 * k;
}
Polygon::Polygon(int n, double R, double r, double g, double b)
{
	this->n = n;
	this->R = R;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Polygon::draw()
{
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
		glVertex2d(anchor.getX() + R * cos(2 * M_PI * i / n), anchor.getY() + R * sin(2 * M_PI * i / n));
	glEnd();
}
void Polygon::zoom(double k)
{
	R *= k;
}
