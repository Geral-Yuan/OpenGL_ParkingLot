//
//  milestone1.hpp
//  project 3
//
//  Created by Elaine Liu on 2021/11/26.
//

#ifndef milestone1_hpp
#define milestone1_hpp

#include <iostream>
#include <math.h>
using namespace std;

class Vec{
private:
    float x,y;
public:
    Vec(float _x, float _y);
    float getX();
    float getY();
    Vec operator+ (Vec v);//Overloads + operator
    Vec operator- (Vec v);//Overloads - on 2 Vectors
    Vec operator* (float k);//Overloads * operator on a float k
    float operator* (Vec v);//Overloads * operator on 2 vectors
    Vec operator<< (float angle);//Overload << operator on an angle
    Vec operator>> (float angle);//Overload >> operator on an angle
};

class Figure {
protected:
    Vec anchor;
public:
    Figure() : anchor(0, 0) {}
    Vec getAnchor() {return anchor;}
    void setAnchor(Vec a) {anchor = a;}
    virtual void draw() = 0;
    virtual void move(Vec dir) = 0;
    virtual void rotate(float angle) = 0;
    virtual void zoom(float k) = 0;
    virtual ~Figure() {};
};

class Vehicle : Figure{
    
};


#endif /* milestone1_hpp */
