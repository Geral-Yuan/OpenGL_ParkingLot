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
    STATUS slot_status;
}slot;

class Vehicle{
protected:
    VEHICLE my_type;
    slot my_slot;
    time_t my_duration;
    time_t enter_time;
    time_t exit_time;//1 second means 10min
    //enter
    void enter();
    //exit
    void exit();
    //calculate price
    virtual int price_cal() = 0;
public:
    //destructor
    virtual ~Vehicle(){}
    //constructor
    Vehicle();
    //print enter ticket
    virtual void enter_print(time_t start_time) = 0;
    //print exit ticket
    virtual void exit_print() = 0;
    //get info funcitons
    time_t get_duration() {return my_duration;}
    time_t get_enter_time() {return enter_time;}
    slot get_slot() {return my_slot;}
    VEHICLE get_type() {return my_type;}
};
//car is a vehicle
class Car : public Vehicle{
private:
    int price_cal();
public:
    //constructor
    Car(slot assigned_slot);
    //print enter ticket
    void enter_print(time_t start_time);
    //print exit ticket
    void exit_print();
};
//van is a vehicle
class Van : public Vehicle{
private:
    int price_cal();
public:
    //constructor
    Van(slot assigned_slot);
    //print enter ticket
    void enter_print(time_t start_time);
    //print exit ticket
    void exit_print();
};
//bike is a vehicle
class Bike : public Vehicle{
private:
    int price_cal();
public:
    //constructor
    Bike(slot assigned_slot);
    //print enter ticket
    void enter_print(time_t start_time);
    //print exit ticket
    void exit_print();
};
//motor is a vehicle
class Motor : public Vehicle{
private:
    int price_cal();
public:
    //constructor
    Motor(slot assigned_slot);
    //print enter ticket
    void enter_print(time_t start_time);
    //print exit ticket
    void exit_print();
};

//class parking lot
class Parking_lot{
private:
    //number of floor
    int floor;
    //vectors for different type of vehicle
    std::vector<slot> Car_slot;
    std::vector<slot> Van_slot;
    std::vector<slot> Bike_slot;
    std::vector<slot> Motor_slot;
    std::vector<Vehicle*> all_vehicle;
    //simulation start_time
    time_t start_time;
    //check if has empty slot
    slot have_empty(std::vector<slot> &type_slot,bool* flag);
    //empty the slot after a car leaves
    void empty_slot(std::vector<slot> &type_slot, slot the_slot);
    void type_draw(std::vector<slot> type_slot);
public:
    //constructor
    Parking_lot(int choice);
    //print general information
    void PrintInfo();
    //generate new vehicles
    void Generate_Vehicle();
    //checkout vehicles
    void Checkout_Veh();
    //draw the parking lot
    void draw();
    //destructor
    ~Parking_lot();
};


#endif /* pms_h */
