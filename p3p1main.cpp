//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/11 10:44
//
#include "p3p1.h"
using namespace std;
int main() {
    cout << "one second in real life is " << TCoefficient << " minute(s) in demo parking lot" << endl;
    srand((unsigned)time(nullptr));
    const time_t demoStart = time(nullptr);
    time_t demoEnd = time(nullptr);
    int slot[capacity];
    for (int i = 0; i <= capacity-1; i++)
    {
        slot[i] = 0;
    }
    parkingLot lot;
    while(demoEnd - demoStart <= (time_t)demoDuration)
    {
        switch(actionDice(0.005/*possibility of entering car*/,0.003/*possibility of leaving car*/))
        {
            case 1://try to generate car
                if(lot.getSize() < capacity)
                {
                    lot.vehicleTypeDice(slot,demoStart);
                    //decide which kind of vehicle will generate and print ticket
                    if (lot.getSize() == capacity) {
                        cout << "I'm full, don't come in." << endl;
                    }
                }
                break;
            case 2:
                if(lot.getSize() >= 1)
                {
                    lot.vehicleIndexDice(slot);
                    //decide which vehicle will drive away and print ticket
                }

        }
        chronoDelay(refreshTime);
        demoEnd = time(nullptr);
    }
    return 0;
}
