//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 10:42
//
#ifndef P3P1_H
#define P3P1_H
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <chrono>
class Vehicle {
public:
    void generate();
    void remove();
    virtual void PrintEnterTicket() = 0;
    virtual void PrintExitTicket() = 0;
    //virtual int CountPrice(int exittime);

protected:
    int entertime;
    int slotnum;
};//abstract class

class Car : public Vehicle {
public:
    //int CountPrice(int exittime);
    void PrintEnterTicket();
    void PrintExitTicket();
};

class Van : public Vehicle {
public:
    //int CountPrice(int exittime);
    void PrintEnterTicket();
    void PrintExitTicket();
};

class Motor : public Vehicle {
public:
    //int CountPrice(int exittime);
    void PrintEnterTicket();
    void PrintExitTicket();
};

class Bike : public Vehicle {
public:
    //int CountPrice(int exittime);
    void PrintEnterTicket();
    void PrintExitTicket();
};

void chronoDelay(double second);//delay a certain time, using second(can be double type)
void printLocalTimePithy();//print local time to debug;
#endif
