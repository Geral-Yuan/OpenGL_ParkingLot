#ifndef VECTOR_H
#define VECTOR_H
class Vec {
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

#endif /* vector_h */
