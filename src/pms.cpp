//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/11 10:44
//
#include "pms.h"
int main() {
    srand((unsigned int)time(NULL));
    Parking_lot my_park;
    my_park.PrintInfo();
    time_t start_time,cur_time;
    time(&start_time);
    time(&cur_time);
    while(cur_time-start_time <= 60){
        my_park.Generate_Vechicle();
        my_park.Checkout_Veh();
        delay(1);
        time(&cur_time);
    }
    return 0;
}
