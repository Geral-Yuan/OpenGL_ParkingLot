//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 10:42
//
#include "P3p1.h"
using namespace std;
Vehicle::~Vehicle() = default;
void Car :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << ctime(&enterTimeSec) << ";" << endl;
    cout << "Type of vehicle: " << "Car" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Motor :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << ctime(&enterTimeSec) << ";" << endl;
    cout << "Type of vehicle: " << "Motor" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Van :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << ctime(&enterTimeSec) << ";" << endl;
    cout << "Type of vehicle: " << "Van" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Bike :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << ctime(&enterTimeSec) << ";" << endl;
    cout << "Type of vehicle: " << "Bike" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Car :: PrintExitTicket() {
    cout << "----------Departure Ticket----------" << endl;
    time_t exitTimeSec = time(0);
    cout << "Time spent in the parking lot: " << (exitTimeSec - enterTimeSec) << " hours;" << endl;
    cout << "Type of vehicle: " << "Car" << ";" << endl;
    time_t price=0.0010*(float)(exitTimeSec - enterTimeSec);
    cout << "Price: " << price << "¥;" << endl;
}

void Motor :: PrintExitTicket() {
    cout << "----------Departure Ticket----------" << endl;
    time_t exitTimeSec = time(0);
    cout << "Time spent in the parking lot: " << (exitTimeSec - enterTimeSec) << " hours;" << endl;
    cout << "Type of vehicle: " << "Motor" << ";" << endl;
    time_t price=0.0008*(float)(exitTimeSec - enterTimeSec);
    cout << "Price: " << price << "¥;" << endl;
}

void Van :: PrintExitTicket() {
    cout << "----------Departure Ticket----------" << endl;
    time_t exitTimeSec = time(0);
    cout << "Time spent in the parking lot: " << (exitTimeSec - enterTimeSec) << " hours;" << endl;
    cout << "Type of vehicle: " << "Van" << ";" << endl;
    time_t price=0.0015*(float)(exitTimeSec - enterTimeSec);
    cout << "Price: " << price << "¥;" << endl;
}

void Bike :: PrintExitTicket() {
    cout << "----------Departure Ticket----------" << endl;
    time_t exitTimeSec = time(0);
    cout << "Time spent in the parking lot: " << (exitTimeSec - enterTimeSec) << " hours;" << endl;
    cout << "Type of vehicle: " << "Bike" << ";" << endl;
    float price=0.0005*(float)(exitTimeSec - enterTimeSec);
    cout << "Price: " << price << "¥;" << endl;
}
parkingLot :: parkingLot() =default;
parkingLot :: ~parkingLot() = default;
Vehicle* parkingLot :: GetVehicle(int vehicleIndex){
    return vehicleVector[(size_t)vehicleIndex];//return the pointer of the ith car
}
int parkingLot :: getSize(){
    return (int) vehicleVector.size();
}
void parkingLot :: addVehicle(Vehicle* vehiclePointer){
    vehicleVector.push_back(vehiclePointer);
}
void parkingLot :: removeVehicle(int vehicleIndex){
    if ((size_t)vehicleIndex <= vehicleVector.size()-1) {
        delete vehicleVector[(size_t)vehicleIndex];
        vehicleVector.erase(vehicleVector.begin() + vehicleIndex);
    }
    else {
        cerr << "removeVehicle() denied to remove, to avoid segmentation fault." << endl;
    }
}

void chronoDelay(double second)
{
    const chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    chrono::time_point<chrono::system_clock> end = chrono::system_clock::now();
    chrono::duration<double> diff = end - start;
    while( (double)diff.count() <= second)
    {
        end = chrono::system_clock::now();
        diff = end - start;
    }
}
void printLocalTimePithy(){
    time_t t = time(0);
    tm* localTimePointer = localtime(&t);
    cout << " Current Date: " << (localTimePointer->tm_mday) << "/" << (localTimePointer->tm_mon) + 1 << "/" << (localTimePointer->tm_year) + 1900 << endl;
    cout << " Current Time: " << (localTimePointer->tm_hour) << ":" << (localTimePointer->tm_min) << ":" << (localTimePointer->tm_sec) << endl;
    cout << endl;
}