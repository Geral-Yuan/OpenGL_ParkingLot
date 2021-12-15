#ifndef VECTOR_H
#define VECTOR_H
#include <cmath>
//constant definition
#define PI acos(-1) /* pi */
//basic class vec for anchors
class Vec
{
private:
    double x, y;

public:
    Vec(){
        x = 0.0;
        y = 1.0;
    }
    Vec(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double getX() { return x; }
    double getY() { return y; }

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

    // Overload * operator on a double k
    // return current Vector scaled by k
    Vec operator*(double k)
    {
        return Vec(x * k, y * k);
    }

    // Overload * on 2 Vectors
    // return thier inner product (scaler product)
    double operator*(Vec v)
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

#endif /* VECTOR_H */
