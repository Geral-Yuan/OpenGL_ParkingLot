#include "parking_lot.h"
Rec::Rec(Vec anchor, Vec v1, Vec v2, double r, double g, double b) : v1(0, 0), v2(0, 0)
{
	this->anchor = anchor;
	this->v1 = v1;
	this->v2 = v2;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Rec::draw()
{
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
}
void Rec::zoom(double k)
{
	anchor = anchor * k;
	v1 = v1 * k;
	v2 = v2 * k;
}
Trapezium::Trapezium(Vec anchor, Vec v1, Vec v2, Vec v3, Vec v4, double r, double g, double b) : v1(0, 0), v2(0, 0), v3(0, 0), v4(0, 0)
{
	this->anchor = anchor;
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
	Vec p1 = anchor + v1;
	Vec p2 = anchor + v2;
	Vec p3 = anchor + v3;
	Vec p4 = anchor + v4;
	glColor3d(r, g, b);
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
	v1 = v1 * k;
	v2 = v2 * k;
	v3 = v3 * k;
	v4 = v4 * k;
}
Triangle::Triangle(Vec anchor, Vec v1, Vec v2, Vec v3, double r, double g, double b) : v1(0, 0), v2(0, 0), v3(0, 0)
{
	this->anchor = anchor;
	this->v1 = v1;
	this->v2 = v2;
	this->v3 = v3;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Triangle::draw()
{
	Vec p1 = anchor + v1;
	Vec p2 = anchor + v2;
	Vec p3 = anchor + v3;
	glColor3d(r, g, b);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2d(p1.getX(), p1.getY());
	glVertex2d(p2.getX(), p2.getY());
	glVertex2d(p3.getX(), p3.getY());
	glEnd();
}
void Triangle::zoom(double k)
{
	anchor = anchor * k;
	v1 = v1 * k;
	v2 = v2 * k;
	v3 = v3 * k;
}
Poly::Poly(Vec anchor, int n, double R, double r, double g, double b)
{
	this->anchor = anchor;
	this->n = n;
	this->R = R;
	this->r = r;
	this->g = g;
	this->b = b;
}
void Poly::draw()
{
	glColor3d(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
		glVertex2d(anchor.getX() + R * cos(2 * PI * i / n), anchor.getY() + R * sin(2 * PI * i / n));
	glEnd();
}
void Poly::zoom(double k)
{
	R *= k;
}

Half_Circle::Half_Circle(Vec anchor, Vec x_dir, Vec y_dir , int n, double R, double r, double g, double b){
    this->anchor = anchor;
    this->n = n;
    this->R = R;
    this->r = r;
    this->g = g;
    this->b = b;
    this->x_dir = x_dir;
    this->y_dir = y_dir;
}
void Half_Circle::draw(){
    glColor3d(r,g,b);
    glBegin(GL_POLYGON);
    for(int i= 0; i<n; i++){
        Vec temp = anchor+ x_dir*(R*cos(PI*i/n-atan(3))) + y_dir*(R*sin(PI*i/n-atan(3)));
        glVertex2d(temp.getX(),temp.getY());
    }
    glEnd();
}
