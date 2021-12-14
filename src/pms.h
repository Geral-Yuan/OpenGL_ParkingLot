//
//  pms.h
//  opengl
//
//  Created by Elaine Liu on 2021/12/14.
//

#ifndef pms_h
#define pms_h

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

#define PRICE_CAR 15
#define PRICE_VAN 20
#define PRICE_BIKE 5
#define PRICE_MOTOR 10

enum VEHICLE {CAR,VAN,BIKE,MOTOR};
enum STATUS {EMPTY,OCCUPIED};


void delay(time_t n);

typedef struct _pos{
    int floor;
    int number;
}position;

typedef struct _slot{
    position pos;
    VEHICLE slot_type;
    STATUS slot_status;
}slot;

class Vehicle{
private:
    VEHICLE my_type;
    slot my_slot;
    time_t my_duration;
    time_t enter_time;
    time_t exit_time;//1 second means 10min
    //enter
    void enter(){
        time(&enter_time);
    }
    //exit
    void exit(){
        time(&exit_time);
    }
    //calculate price
    double price_cal(){
        int price[4] = {PRICE_CAR,PRICE_VAN,PRICE_BIKE,PRICE_MOTOR};//price for an hour
        return (exit_time-enter_time)*10.0f/60.0f*price[my_type];
    }
public:
    Vehicle(VEHICLE generated_type, slot assigned_slot){
        my_type = generated_type;
        my_slot = assigned_slot;
        my_duration = (time_t)(rand()%20+3);
    }
    void enter_print(time_t start_time){
        enter();
        time_t tmp = (enter_time-start_time)*(time_t)600+start_time;
        std::string vehicle[4] = {"Car", "Van", "Bike", "Motor"};
        std::cout << std::endl;
        std::cout << "----------Arrival Ticket----------" << std::endl;
        std::cout << "Time of arrival: " << ctime(&tmp);
        std::cout << "Type of vehicle: " << vehicle[my_type] << ";" << std::endl;
        std::cout << "Slot: [FLOOR: " << my_slot.pos.floor << "; NUMBER: " << my_slot.pos.number  << "];" << std::endl;
        std::cout << std::endl;
    }
    void exit_print(){
        exit();
        std::string vehicle[4] = {"Car", "Van", "Bike", "Motor"};
        std::cout << std::endl;
        std::cout << "----------Departure Ticket----------" << std::endl;
        std::cout << "Time spent in the parking lot: " << (exit_time-enter_time)/6.0f << " hours;" << std::endl;
        std::cout << "Type of vehicle: " << vehicle[my_type] << ";" << std::endl;
        std::cout << "Price: " << price_cal() << "¥;" << std::endl;
        std::cout << std::endl;
    }
    time_t get_duration() {return my_duration;}
    time_t get_enter_time() {return enter_time;}
    slot get_slot() {return my_slot;}
    VEHICLE get_type() {return my_type;}
};

class Parking_lot{
private:
    int floor;
    slot** all_slots;
    std::vector<slot> Car_slot;
    std::vector<slot> Van_slot;
    std::vector<slot> Bike_slot;
    std::vector<slot> Motor_slot;
    std::vector<Vehicle> all_vehicle;
    time_t start_time;
public:
    Parking_lot(){
        std::cout << "Decide how many floor the parking lot has: " << std::endl;
        std::cin >> floor;
        for(int i = 0; i< floor; i++){
            std::cout << "Decide the slot number on floor " << i+1 << ": " << std::endl;
            int tmp = 0;
            std::cin >> tmp;
            std::cin.ignore(100,'\n');
            for(int j = 0; j< tmp; j++){
                if(j <= (int)tmp*0.3)
                    Car_slot.push_back((slot){(position){i+1,j+1},CAR,EMPTY});
                else if(j <= (int)tmp*0.6)
                    Van_slot.push_back((slot){(position){i+1,j+1},CAR,EMPTY});
                else if(j <= (int)tmp*0.8)
                    Bike_slot.push_back((slot){(position){i+1,j+1},CAR,EMPTY});
                else
                    Motor_slot.push_back((slot){(position){i+1,j+1},CAR,EMPTY});
            }
        }
    }
    void PrintInfo(){
        std::cout << "[WELCOME TO THE PARKING LOT MANAGEMENT SYSTEM]" << std::endl;
        std::cout << "TOTAL FLOOR: " << floor << std::endl;
        std::cout << "SLOTS FOR CARS: " << Car_slot.size() << "; Price Per hour: "<< PRICE_CAR << "¥/hr" << std::endl;
        std::cout << "SLOTS FOR VANS: " << Van_slot.size() << "; Price Per hour: "<< PRICE_VAN << "¥/hr" << std::endl;
        std::cout << "SLOTS FOR BIKES: " << Bike_slot.size() << "; Price Per hour: "<< PRICE_BIKE << "¥/hr" <<std::endl;
        std::cout << "SLOTS FOR MOTORS: " << Motor_slot.size() << "; Price Per hour: "<< PRICE_MOTOR << "¥/hr" << std::endl;
        time(&start_time);
        std::cout << "SIMULATION START TIME: " << ctime(&start_time) << std::endl;
    }
    void Generate_Vechicle(){
        std::string vehicle[4] = {"Car", "Van", "Bike", "Motor"};
        VEHICLE new_veh = VEHICLE(rand()%4);
        bool flag = 0;//if generated successfully with a slot assigned
        std::vector<slot>::iterator it;
        switch(new_veh){
            case CAR:
                for(it = Car_slot.begin(); it != Car_slot.end(); it++){
                    if(it->slot_status == EMPTY){
                        it->slot_status = OCCUPIED;
                        flag = 1;
                        break;
                    }
                }
                break;
            case VAN:
                for(it = Van_slot.begin(); it != Van_slot.end(); it++){
                    if(it->slot_status == EMPTY){
                        it->slot_status = OCCUPIED;
                        flag = 1;
                        break;
                    }
                }
                break;
            case BIKE:
                for(it = Bike_slot.begin(); it != Bike_slot.end(); it++){
                    if(it->slot_status == EMPTY){
                        it->slot_status = OCCUPIED;
                        flag = 1;
                        break;
                    }
                }
                break;
            case MOTOR:
                for(it = Motor_slot.begin(); it != Motor_slot.end(); it++){
                    if(it->slot_status == EMPTY){
                        it->slot_status = OCCUPIED;
                        flag = 1;
                        break;
                    }
                }
                break;
        }
        if(flag == 1){
            all_vehicle.push_back(Vehicle(new_veh,*it));
            all_vehicle.back().enter_print(start_time);
        }
        else{
            std::cout << "[ALREADY FULL] A " << vehicle[new_veh] << " fails to park in." << std::endl;
        }
    }
    void Checkout_Veh(){
        std::vector<Vehicle>::iterator it;
        time_t cur_time;
        time(&cur_time);
        for(it = all_vehicle.begin();it != all_vehicle.end(); it++){
            if(it->get_duration() == cur_time-it->get_enter_time()){
                it->exit_print();
                switch(it->get_type()){
                    case CAR:
                        for(auto &target: Car_slot){
                            if(target.pos.floor == it->get_slot().pos.floor && target.pos.number == it->get_slot().pos.number)
                                target.slot_status = EMPTY;
                        }
                        break;
                    case VAN:
                        for(auto &target: Van_slot){
                            if(target.pos.floor == it->get_slot().pos.floor && target.pos.number == it->get_slot().pos.number)
                                target.slot_status = EMPTY;
                        }
                        break;
                    case BIKE:
                        for(auto &target: Bike_slot){
                            if(target.pos.floor == it->get_slot().pos.floor && target.pos.number == it->get_slot().pos.number)
                                target.slot_status = EMPTY;
                        }
                        break;
                    case MOTOR:
                        for(auto &target: Motor_slot){
                            if(target.pos.floor == it->get_slot().pos.floor && target.pos.number == it->get_slot().pos.number)
                                target.slot_status = EMPTY;
                        }
                        break;
                }
                all_vehicle.erase(it);
                it--;
            }
        }
    }
};


#endif /* pms_h */
