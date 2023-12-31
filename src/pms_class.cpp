//
//  pms_class.cpp
//  opengl
//
//  Created by Elaine Liu on 2021/12/14.
//

#include "pms.h"

//delay function
void delay(time_t n){
    time_t start_time, cur_time;
    time(&start_time);
    do{
        time(&cur_time);
    }while(cur_time-start_time < n);
}

//class vehicle implementation
///private
void Vehicle::enter(){time(&enter_time);} /*enter the lot = get time*/
void Vehicle::exit(){time(&exit_time);} /*exit the lot = get time*/

int Car::price_cal(){
    return exit_time-enter_time%6 == 0 ? (int)(exit_time-enter_time)/6*PRICE_CAR : (int)((exit_time-enter_time)/6+1)*PRICE_CAR ;
}/* price calculation */
int Van::price_cal(){
    return exit_time-enter_time%6 == 0 ? (int)(exit_time-enter_time)/6*PRICE_VAN : (int)((exit_time-enter_time)/6+1)*PRICE_VAN ;
}/* price calculation */
int Bike::price_cal(){
    return exit_time-enter_time%6 == 0 ? (int)(exit_time-enter_time)/6*PRICE_BIKE : (int)((exit_time-enter_time)/6+1)*PRICE_BIKE ;
}/* price calculation */
int Motor::price_cal(){
    return exit_time-enter_time%6 == 0 ? (int)(exit_time-enter_time)/6*PRICE_MOTOR : (int)((exit_time-enter_time)/6+1)*PRICE_MOTOR ;
}/* price calculation */

///public
Vehicle::Vehicle(){
    my_type = CAR;
    my_slot = {{0,0},EMPTY};
    my_duration = (time_t)(rand()%20+3);
}/* constructor */
Car::Car(slot assigned_slot){
    my_type = CAR;
    my_slot = assigned_slot;
    my_duration = (time_t)(rand()%20+3);
}/* constructor */
Van::Van(slot assigned_slot){
    my_type = VAN;
    my_slot = assigned_slot;
    my_duration = (time_t)(rand()%20+3);
}/* constructor */
Bike::Bike(slot assigned_slot){
    my_type = BIKE;
    my_slot = assigned_slot;
    my_duration = (time_t)(rand()%20+3);
}/* constructor */
Motor::Motor(slot assigned_slot){
    my_type = MOTOR;
    my_slot = assigned_slot;
    my_duration = (time_t)(rand()%20+3);
}/* constructor */

void Car::enter_print(time_t start_time){
    enter();
    time_t tmp = (enter_time-start_time)*(time_t)600+start_time;
    std::cout << std::endl;
    std::cout << "----------Arrival Ticket----------" << std::endl;
    std::cout << "Time of arrival: " << ctime(&tmp);
    std::cout << "Type of vehicle: Car;" << std::endl;
    std::cout << "Slot: [FLOOR: " << my_slot.pos.floor << "; NUMBER: " << my_slot.pos.number  << "];" << std::endl;
    std::cout << std::endl;
}/* print enter ticket*/
void Van::enter_print(time_t start_time){
    enter();
    time_t tmp = (enter_time-start_time)*(time_t)600+start_time;
    std::cout << std::endl;
    std::cout << "----------Arrival Ticket----------" << std::endl;
    std::cout << "Time of arrival: " << ctime(&tmp);
    std::cout << "Type of vehicle: VAN;" << std::endl;
    std::cout << "Slot: [FLOOR: " << my_slot.pos.floor << "; NUMBER: " << my_slot.pos.number  << "];" << std::endl;
    std::cout << std::endl;
}/* print enter ticket*/
void Bike::enter_print(time_t start_time){
    enter();
    time_t tmp = (enter_time-start_time)*(time_t)600+start_time;
    std::cout << std::endl;
    std::cout << "----------Arrival Ticket----------" << std::endl;
    std::cout << "Time of arrival: " << ctime(&tmp);
    std::cout << "Type of vehicle: Bike;" << std::endl;
    std::cout << "Slot: [FLOOR: " << my_slot.pos.floor << "; NUMBER: " << my_slot.pos.number  << "];" << std::endl;
    std::cout << std::endl;
}/* print enter ticket*/
void Motor::enter_print(time_t start_time){
    enter();
    time_t tmp = (enter_time-start_time)*(time_t)600+start_time;
    std::cout << std::endl;
    std::cout << "----------Arrival Ticket----------" << std::endl;
    std::cout << "Time of arrival: " << ctime(&tmp);
    std::cout << "Type of vehicle: Motor;" << std::endl;
    std::cout << "Slot: [FLOOR: " << my_slot.pos.floor << "; NUMBER: " << my_slot.pos.number  << "];" << std::endl;
    std::cout << std::endl;
}/* print enter ticket*/

void Car::exit_print(){
    exit();std::cout << std::endl;
    std::cout << "----------Departure Ticket----------" << std::endl;
    std::cout << "Time spent in the parking lot: " << (exit_time-enter_time)/6.0f << " hours;" << std::endl;
    std::cout << "Type of vehicle: Car;" << std::endl;
    std::cout << "Price: " << price_cal() << "RMB;" << std::endl;
    std::cout << std::endl;
}/* print exit ticket*/
void Van::exit_print(){
    exit();std::cout << std::endl;
    std::cout << "----------Departure Ticket----------" << std::endl;
    std::cout << "Time spent in the parking lot: " << (exit_time-enter_time)/6.0f << " hours;" << std::endl;
    std::cout << "Type of vehicle: Van;" << std::endl;
    std::cout << "Price: " << price_cal() << "RMB;" << std::endl;
    std::cout << std::endl;
}/* print exit ticket*/
void Bike::exit_print(){
    exit();std::cout << std::endl;
    std::cout << "----------Departure Ticket----------" << std::endl;
    std::cout << "Time spent in the parking lot: " << (exit_time-enter_time)/6.0f << " hours;" << std::endl;
    std::cout << "Type of vehicle: Bike;" << std::endl;
    std::cout << "Price: " << price_cal() << "RMB;" << std::endl;
    std::cout << std::endl;
}/* print exit ticket*/
void Motor::exit_print(){
    exit();std::cout << std::endl;
    std::cout << "----------Departure Ticket----------" << std::endl;
    std::cout << "Time spent in the parking lot: " << (exit_time-enter_time)/6.0f << " hours;" << std::endl;
    std::cout << "Type of vehicle: Motor;" << std::endl;
    std::cout << "Price: " << price_cal() << "RMB;" << std::endl;
    std::cout << std::endl;
}/* print exit ticket*/


//class parking lot
///private
slot Parking_lot::have_empty(std::vector<slot> &type_slot,bool* flag){
    std::vector<slot>::iterator it;
    for(it = type_slot.begin(); it != type_slot.end(); it++){
        if(it->slot_status == EMPTY){
            it->slot_status = OCCUPIED;
            *flag = 1;
            return *it;
        }
    }
    slot tmp = {{0,0},EMPTY};
    return tmp;
}/*find empty slot*/

void Parking_lot::empty_slot(std::vector<slot> &type_slot, slot the_slot){
    for(auto &target: type_slot){
        if(target.pos.floor == the_slot.pos.floor && target.pos.number == the_slot.pos.number)
            target.slot_status = EMPTY;
    }
}/*empty the slot*/


void Parking_lot::type_draw(std::vector<slot> type_slot){
    std::vector<slot>::iterator it;
    int count = 0;
    for(it = type_slot.begin(); it!= type_slot.end(); it++){
        if(count++%3==0)
            std::cout << std::endl;
        std::cout << "[F" << it->pos.floor << "N" << std::setw(2) << std::setfill('0') << it->pos.number << "] |" << ((it->slot_status == EMPTY)? " " : "*" )<< "| ";
    }
    std::cout << std::endl;
}
///public
Parking_lot::Parking_lot(int choice){
    std::cout << "The floors the parking lot has: ";
    if(choice == 2)
        std::cin >> floor;
    else{
        floor = rand()%3+2;
        std::cout <<floor << std::endl;
    }
    for(int i = 0; i< floor; i++){
        std::cout << "The slot number on floor (no less than 4) " << i+1 << ": ";
        int tmp = 0;
        if(choice == 2){
            std::cin >> tmp;
            std::cin.ignore(100,'\n');
        }
        else{
            tmp = rand()%9+4;
            std::cout << tmp << std::endl;
        }
        slot s_tmp;
        s_tmp.slot_status = EMPTY;
        s_tmp.pos.floor = i+1;
        for(int j = 0; j< tmp; j++){
            s_tmp.pos.number = j+1;
            if(j <= (int)tmp*0.3)
                Car_slot.push_back(s_tmp);
            else if(j <= (int)tmp*0.6)
                Van_slot.push_back(s_tmp);
            else if(j <= (int)tmp*0.8)
                Bike_slot.push_back(s_tmp);
            else
                Motor_slot.push_back(s_tmp);
        }
    }
} /* constructor */

void Parking_lot::PrintInfo(){
    std::cout << "[SIMULATION STARTS IN 3 SECONDS]" << std::endl;
    delay(3);
    std::cout << std::endl << "[WELCOME TO THE PARKING LOT MANAGEMENT SYSTEM]" << std::endl;
    std::cout << "TOTAL FLOOR: " << floor << std::endl;
    std::cout << "SLOTS FOR CARS: " << Car_slot.size() << "; Price Per hour: "<< PRICE_CAR << "RMB/hr" << std::endl;
    std::cout << "SLOTS FOR VANS: " << Van_slot.size() << "; Price Per hour: "<< PRICE_VAN << "RMB/hr" << std::endl;
    std::cout << "SLOTS FOR BIKES: " << Bike_slot.size() << "; Price Per hour: "<< PRICE_BIKE << "RMB/hr" <<std::endl;
    std::cout << "SLOTS FOR MOTORS: " << Motor_slot.size() << "; Price Per hour: "<< PRICE_MOTOR << "RMB/hr" << std::endl;
    time(&start_time);
    std::cout << "[SIMULATION START] TIME: " << ctime(&start_time) << std::endl;
} /* information print */

void Parking_lot::Generate_Vehicle(){
    std::string vehicle[4] = {"Car", "Van", "Bike", "Motor"};
    VEHICLE new_veh = VEHICLE(rand()%4);
    Vehicle* veh;
    bool flag = 0;//if generated successfully with a slot assigned
    slot target;
    switch(new_veh){
        case CAR:
            target = have_empty(Car_slot,&flag);
            veh = new Car(target);
            break;
        case VAN:
            target = have_empty(Van_slot,&flag);
            veh = new Van(target);
            break;
        case BIKE:
            target = have_empty(Bike_slot,&flag);
            veh = new Bike(target);
            break;
        case MOTOR:
            target = have_empty(Motor_slot,&flag);
            veh = new Motor(target);
            break;
    }
    if(flag == 1){
        all_vehicle.push_back(veh);
        all_vehicle.back()->enter_print(start_time);
    }
    else{
        std::cout << "[ALREADY FULL] A " << vehicle[new_veh] << " fails to park in." << std::endl;
    }
}/* generate new vehicles */

void Parking_lot::Checkout_Veh(){
    std::vector<Vehicle*>::iterator it;
    //get time
    time_t cur_time;
    time(&cur_time);
    //go through all
    for(it = all_vehicle.begin();it != all_vehicle.end(); it++){
        //duration reached -> get out
        if((*it)->get_duration() == cur_time-(*it)->get_enter_time()){
            (*it)->exit_print();
            //empty the slot
            switch((*it)->get_type()){
                case CAR:
                    empty_slot(Car_slot, (*it)->get_slot());
                    break;
                case VAN:
                    empty_slot(Van_slot, (*it)->get_slot());
                    break;
                case BIKE:
                    empty_slot(Bike_slot, (*it)->get_slot());
                    break;
                case MOTOR:
                    empty_slot(Motor_slot, (*it)->get_slot());
                    break;
            }
            delete (*it);
            all_vehicle.erase(it);
            it--;
        }
    }
}/* checkout vehicles */

void Parking_lot::draw(){
    std::cout << "------THE PARKING AREA------" << std::endl;
    std::cout << "Car slots:";
    type_draw(Car_slot);
    std::cout << "Van slots:";
    type_draw(Van_slot);
    std::cout << "Bike slots:";
    type_draw(Bike_slot);
    std::cout << "Motor slots:";
    type_draw(Motor_slot);
    std::cout << "------------------------------" << std::endl << std::endl;
}/* draw the parking area*/

Parking_lot::~Parking_lot(){
    std::vector<Vehicle*>::iterator it;
    for(it = all_vehicle.begin(); it != all_vehicle.end(); it++){
        delete (*it);
    }
}/* destructor */
