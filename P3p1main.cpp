//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 10:42
//
#include "P3p1.h"
using namespace std;

int FindEmpty(int* slot) {
    for (int i=0;i<=34;i++) {
        if (*(slot+i)==0) return i;
    }
    return 0;
}


int main() {
    int slot[35];
    for (int i=0;i<=34;i++) slot[i]=0;
    /*slot[0]=1;
    slot[1]=1;
    cout<<FindEmpty(slot)<<endl;
    return 0;*/
}
/*An implementation plan of time system:

main function start, get a time by calling std::chrono::system_clock::now
and construct a vector of vehicle's pointer. (i.e. vector<Vehicle> lot)

start a loop which is always true (how to exit will discuss later on)

role diceA: to decide if we will generate a vehicle(if parking lot isn't full, role diceB)/ drive away a vehicle(if parking lot isn't empty, role diceC)/ not do anything

role diceB: (if generate a vehicle): to decide which kind of vehicle will generate and print ticket
comment of step 4: push_back() a new vehicle with specfic vehicle type

role diceC: (if drive away a vehicle): to decide which vehicle will drive away and print ticket
comment of step 5: use iterator to scan the vector and erase() the vehicle's information

use my function void chronoDelay(double second); to delay time

turn to step 3.

This plan doesn't consider the difference between each slots.*/
