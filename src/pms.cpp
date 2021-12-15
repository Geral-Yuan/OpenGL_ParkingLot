//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/11 10:44
//
#include "pms.h"
int main() {
    std::cout << "------WELCOME TO THE PARKING MANAGEMENT SYSTEM------" << std::endl;
    //decide simulation length
    std::cout << "*NOTE* In this simulation [1 second] in REAL equals [10 minutes]\n[Decide on the total time of simulation](in seconds)>>>";
    int sec = 0;
    std::cin>>sec; std::cin.ignore(100,'\n');
    //mode choose
    std::cout << "[CHOOSE YOUR MODE]\n*MODE 1*: DEMO MODE\n*MODE 2*: DECIDE YOUR PARKING LOT\n[enter your choice]>>> ";
    int choice = 1;
    std::cin >> choice;
    //time seed
    srand((unsigned int)time(NULL));
    //create
    Parking_lot my_park(choice);
    my_park.PrintInfo();
    time_t start_time,cur_time;
    time(&start_time);
    time(&cur_time);
    //main loop
    while(cur_time-start_time <= sec){
        my_park.Generate_Vehicle();
        my_park.Checkout_Veh();
        my_park.draw();
        delay(1);
        time(&cur_time);
    }
    //end
    std::cout << "End of simulation, bye~" << std::endl;
    return 0;
}
