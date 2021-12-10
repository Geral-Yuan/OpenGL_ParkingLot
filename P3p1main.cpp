//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/10 10:42
//
#include "P3p1.h"
using namespace std;
static const int capacity = 35;
int FindEmpty(int* slot) {
    for (int i=0;i<=34;i++) {
        if (*(slot+i)==0) return i;
    }
    return 0;
}


int main() {
    srand((unsigned)time(nullptr));
    //const chrono::time_point<chrono::system_clock> demostart = chrono::system_clock::now();

    /*int slot[35];
    for (int i=0;i<=34;i++) slot[i]=0;
    slot[0]=1;
    slot[1]=1;
    cout<<FindEmpty(slot)<<endl;
    return 0;*/

    parkingLot lot;
    while(true)
    {
        switch(actionDice(0.005,0.001))
        {
            case 1://try to generate car
                if(lot.getSize() < capacity)
                {
                    lot.vehicleTypeDice();
                    if (lot.getSize() == capacity)
                        cout  << "I'm full, don't come in." << endl;
                    else
                        cout << lot.getSize() << endl;
                }
                break;
            case 2:
                if(lot.getSize() >= 0)
                {
                    lot.vehicleIndexDice();
                }

        }
        chronoDelay(0.005);
    }
}
/*An implementation plan of time system:

main function start, get vehicleVector time by calling std::chrono::system_clock::now
and construct vehicleVector vector of vehicle's pointer. (i.e. vector<Vehicle> lot)

start vehicleVector loop which is always true (how to exit will discuss later on)

role diceA: to decide if we will generate vehicleVector vehicle(if parking lot isn't full, role diceB)/ drive away vehicleVector vehicle(if parking lot isn't empty, role diceC)/ not do anything

role diceB: (if generate vehicleVector vehicle): to decide which kind of vehicle will generate and print ticket
comment of step 4: push_back() vehicleVector new vehicle with specfic vehicle type

role diceC: (if drive away vehicleVector vehicle): to decide which vehicle will drive away and print ticket
comment of step 5: use iterator to scan the vector and erase() the vehicle's information

use my function void chronoDelay(double second); to delay time

turn to step 3.

This plan doesn't consider the difference between each slots.*/
