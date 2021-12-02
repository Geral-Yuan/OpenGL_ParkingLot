//
//  milestone1.cpp
//  project 3
//
//  Created by Elaine Liu on 2021/11/26.
//

#include "milestone1.hpp"

Vec::Vec(float _x, float _y){x = _x; y = _y;}
float Vec::getX(){return x;}
float Vec::getY(){return y;}
//Overloads + operator
Vec Vec::operator+ (Vec v){
    return Vec(x + v.getX(), y + v.getY());
}
//Overloads - on 2 Vectors
Vec Vec::operator- (Vec v){
    return Vec(x-v.getX(), x-v.getY());
}
//Overloads * operator on a float k
Vec Vec::operator* (float k){
    return Vec(x*k,y*k);
}
//Overloads * operator on 2 vectors
float Vec::operator* (Vec v){
    return y*v.getX() + x*v.getY();
}
//Overload << operator on an angle
Vec Vec::operator<< (float angle){
    float new_angle = asin((float)y/(float)sqrt(x*x+y*y)) + angle;
    return Vec((sqrt(x*x+y*y))*cos(new_angle),(sqrt(x*x+y*y))*sin(new_angle));
}
//Overload >> operator on an angle
Vec Vec::operator>> (float angle){
    float new_angle = asin((float)y/(float)sqrt(x*x+y*y)) - angle;
    return Vec((sqrt(x*x+y*y))*cos(new_angle),(sqrt(x*x+y*y))*sin(new_angle));
}
