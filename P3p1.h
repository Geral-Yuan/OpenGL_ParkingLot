//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 12:06
//
#ifndef P3P1_H
#define P3P1_H
#include <ctime>//time related functions and data types (might not use)
#include <iostream>//i/o
#include <cstdlib>//standard library, many useful tools
#include <chrono>//time related functions and data types
#include <vector>//It is highly recommended to use vector to store pointers to the vehicles
using namespace std;

class Vehicle {
public:
    virtual ~Vehicle();
    virtual void PrintEnterTicket() = 0;
    virtual void PrintExitTicket() = 0;
protected:
    chrono::time_point<chrono::system_clock> enterTime;
    time_t enterTimeSec;
    int slotnum;
};//abstract class

class Car : public Vehicle {
public:
    void PrintEnterTicket() override;
    void PrintExitTicket() override;
};

class Van : public Vehicle {
public:
    void PrintEnterTicket() override;
    void PrintExitTicket() override;
};

class Motor : public Vehicle {
public:
    void PrintEnterTicket() override;
    void PrintExitTicket() override;
};

class Bike : public Vehicle {
public:
    void PrintEnterTicket() override;
    void PrintExitTicket() override;
};
class parkingLot{
public:
    parkingLot();
    ~parkingLot();
    int getSize();
    Vehicle *GetVehicle(int vehicleIndex);
    void addVehicle(Vehicle* vehiclePointer);
    void removeVehicle(int vehicleIndex);
private:
    vector<Vehicle*> vehicleVector;
    //vehicleVector parking lot has vehicleVector container of vehicles' information (implemented as vehicles' pointers)
};

void chronoDelay(double second);//delay vehicleVector certain time, using second(can be double type)
void printLocalTimePithy();//print local time to debug;
#endif
