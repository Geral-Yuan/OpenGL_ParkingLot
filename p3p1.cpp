#include <ctime>
#include <iostream>
#include <cstdlib>
#include "p3p1.h"
using namespace std;
void Car :: printenterticket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Car" << ";" << endl;
    cout << "Slot: No."<< slotnum << ";" << endl;
}

void Motor :: printenterticket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Motor" << ";" << endl;
    cout << "Slot: No."<< slotnum << ";" << endl;
}

void Van :: printenterticket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Van" << ";" << endl;
    cout << "Slot: No."<< slotnum << ";" << endl;
}

void Bike :: printenterticket() {
    cout << endl << "----------Arrival Ticket----------" << endl;
    cout << "Time of arrival: " << entertime << ";" << endl;
    cout << "Type of vehicle: " << "Bike" << ";" << endl;
    cout << "Slot: No."<< slotnum << ";" << endl;
}

void Car :: printexitticket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Car" << ";" << endl;
    int price=countprice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

void Motor :: printexitticket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Motor" << ";" << endl;
    int price=countprice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

void Van :: printexitticket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Van" << ";" << endl;
    int price=countprice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

void Bike :: printexitticket(int exittime) {
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (exittime-entertime) << " hours;" << endl;
    cout << "Type of vehicle: " << "Bike" << ";" << endl;
    int price=countprice(exittime);
    cout << "Price: " << price << "¥;" << endl;
}

int Car :: countprice(int exittime) {
    int price=10*(exittime-entertime);
    return price;
}
int Motor :: countprice(int exittime) {
    int price=8*(exittime-entertime);
    return price;
}
int Van :: countprice(int exittime) {
    int price=15*(exittime-entertime);
    return price;
}
int Bike :: countprice(int exittime) {
    int price=5*(exittime-entertime);
    return price;
}