//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 10:42
//
#include "P3p1.h"
using namespace std;
void Car :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Car" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Motor :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Motor" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Van :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Van" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Bike :: PrintEnterTicket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Bike" << ";" << endl;
    cout << "Slot: Floor "<< slotnum/20 << " No." << slotnum-20*(int)(slotnum/20)<< endl;
}

void Car :: PrintExitTicket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Car" << ";" << endl;
    int price=CountPrice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

void Motor :: PrintExitTicket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Motor" << ";" << endl;
    int price=CountPrice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

void Van :: PrintExitTicket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Van" << ";" << endl;
    int price=CountPrice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

void Bike :: PrintExitTicket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Bike" << ";" << endl;
    int price=CountPrice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

int Car :: CountPrice(int exittime) {
    int price=10*(exittime-entertime);
    return price;
}
int Motor :: CountPrice(int exittime) {
    int price=8*(exittime-entertime);
    return price;
}
int Van :: CountPrice(int exittime) {
    int price=15*(exittime-entertime);
    return price;
}
int Bike :: CountPrice(int exittime) {
    int price=5*(exittime-entertime);
    return price;
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