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
#include <iomanip>
using namespace std;
/*the parking lot capacity*/
static const int capacity = 35;
/*the demo runs demoDuration second(s)*/
static const time_t demoDuration = 300;
/*one second in real life is TCoefficient minute(s) in demo parking lot*/
static const double TCoefficient = 10.0;
/*a day is 1440 minutes*/
static const int MinutePerDay = 1440;
/*precision of output price*/
static const unsigned precisionNumber = 2;
/*used in chronoDelay(), the time in second(s) between each refresh*/
static const double refreshTime = 0.005;
class Vehicle {
public:
    virtual ~Vehicle();
    void PrintEnterTicket(const string&, int*, time_t);
    void PrintExitTicket(double, const string&) const;
    void removeSlotNum(int*) const;
protected:
    //chrono::time_point<chrono::system_clock> enterTime;
    time_t enterTimeSec;
    int slotNum;
};//abstract class
class Car : public Vehicle {
public:
    explicit Car(int*,time_t);
    ~Car() override;
};
class Van : public Vehicle {
public:
    explicit Van(int*,time_t);
    ~Van() override;
};
class Motor : public Vehicle {
public:
    explicit Motor(int*,time_t);
    ~Motor() override;
};
class Bike : public Vehicle {
public:
    explicit Bike(int*,time_t);
    ~Bike() override;
};
class parkingLot{
public:
    parkingLot();
    ~parkingLot();
    int getSize();
    void removeVehicle(int,int*);
    void vehicleTypeDice(int*,time_t);
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
void printATime2(time_t,const string&,const string&);
#endif
