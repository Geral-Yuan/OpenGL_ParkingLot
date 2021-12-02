#ifndef Vector_H
#define Vector_H
#include <cmath>
#define M_PI 3.14159265358979323846 /* pi */
class Vec
{
private:
	float x, y;

public:
	Vec(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
	float getX() { return x; }
	float getY() { return y; }

	// Example Overloads + operator
	// returns the sum of 2 Vec
	Vec operator+(Vec v)
	{
		return Vec(x + v.x, y + v.y);
	}

	// Overload - on 2 Vectors
	// return thier difference Vector
	Vec operator-(Vec v)
	{
		return Vec(x - v.x, y - v.y);
	}

	// Overload * operator on a float k
	// return current Vector scaled by k
	Vec operator*(float k)
	{
		return Vec(x * k, y * k);
	}

	// Overload * on 2 Vectors
	// return thier inner product (scaler product)
	float operator*(Vec v)
	{
		return x * v.x + y * v.y;
	}

	// Overload << on an angle
	// return current vector rotated counter clockwise
	// by this angle
	Vec operator<<(double theta)
	{
		return Vec(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
	}

	// Overload >> on an angle
	// return current vector rotated clockwise
	// by this angle
	Vec operator>>(double theta)
	{
		return Vec(x * cos(theta) + y * sin(theta), -x * sin(theta) + y * cos(theta));
	}
};

class Figure
{
protected:
	Vec anchor;

public:
	Figure() : anchor(0, 0) {}
	Vec getAnchor() { return anchor; }
	void setAnchor(Vec a) { anchor = a; }
	virtual void draw() = 0;
	virtual void move(Vec dir) = 0;
	virtual void rotate(float angle) = 0;
	virtual void zoom(float k) = 0;
	virtual ~Figure() {}
};
class Group : Figure
{
private:
	// A Group of figure "has" other figures.
public:
	// We left out the constructor as well
	void draw();			  // Draw out all its figures
	void move(Vec dir);		  // Move all its figures
	void rotate(float angle); // Rotate the group as a whole.
	void zoom(float k);		  // Zoom the group as a whole.
	~Group() {}
};
#endif