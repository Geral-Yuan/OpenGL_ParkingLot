//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 21:50
//
#ifndef P3P1_H
#define P3P1_H
#include <ctime>//time related functions and data types (might not use)
#include <iostream>//i/o
#include <cstdlib>//standard library, many useful tools
#include <chrono>//time related functions and data types
#include <vector>//It is highly recommended to use vector to store pointers to the vehicles
using namespace std;
static const int capacity = 35;
static const time_t demoDuration = 300;//run 5 minutes
class Vehicle {
public:
    virtual ~Vehicle();
    void PrintEnterTicket(const string&, int*);
    void PrintExitTicket(double, const string&) const;
    void removeSlotNum(int*) const;
protected:
    //chrono::time_point<chrono::system_clock> enterTime;
    time_t enterTimeSec;
    int slotNum;
};//abstract class
class Car : public Vehicle {
public:
    explicit Car(int*);
    ~Car() override;
};
class Van : public Vehicle {
public:
    explicit Van(int*);
    ~Van() override;
};
class Motor : public Vehicle {
public:
    explicit Motor(int*);
    ~Motor() override;
};
class Bike : public Vehicle {
public:
    explicit Bike(int*);
    ~Bike() override;
};
class parkingLot{
public:
    parkingLot();
    ~parkingLot();
    int getSize();
    void removeVehicle(int,int*);
    void vehicleTypeDice(int*);
    void vehicleIndexDice(int*);
private:
    vector<Vehicle*> vehicleVector;
    //vehicleVector parking lot has vehicleVector container of vehicles' information (implemented as vehicles' pointers)
};
void chronoDelay(double second);//delay vehicleVector certain time, using second(can be double type)
int actionDice(double a_LARGER_0_0001,double b_LARGER_0_0001);
//a dice to decide action (input e.g. chanceA = 0.001(return 1), chanceB = 0.01(return 2), else(return 0))
void printATime(time_t enterTimeSec);
int FindEmpty(int* slot);
#endif
