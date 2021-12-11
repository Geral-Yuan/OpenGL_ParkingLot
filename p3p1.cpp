//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/11 11:15
//
#include "p3p1.h"
using namespace std;
Vehicle::~Vehicle() = default;
void Vehicle::PrintEnterTicket(const string& VName) {
    cout << endl << "----------Arrival Ticket----------" << endl;
    enterTimeSec = time(nullptr);
    printATime(enterTimeSec);
    cout << "Type of vehicle: " << VName << ";" << endl;
    //cout << "Slot: Floor " << slotNum / 20 << " No." << slotNum - 20 * (int)(slotNum / 20) << endl;
}
void Vehicle::PrintExitTicket(double MoneyPerH, const string& VName) const {
    cout << endl << "----------Departure Ticket----------" << endl;
    time_t exitTimeSec = time(nullptr);
    //cout << exitTimeSec << endl;
    cout << "Time spent in the parking lot: " << (exitTimeSec - enterTimeSec) << " hours;" << endl;
    cout << "Type of vehicle: " << VName << ";" << endl;
    double price=MoneyPerH*(double)(exitTimeSec - enterTimeSec);
    cout << "Price: " << price << endl;
}
Car::Car() {
    Car::PrintEnterTicket("car");
}
Car::~Car() {
    Car::PrintExitTicket(10, "car");
}
Motor::Motor(){
    Motor::PrintEnterTicket("Motor");
}
Motor::~Motor() {
    Motor::PrintExitTicket(8, "Motor");
}
Van::Van(){
    Van::PrintEnterTicket("Van");
}
Van::~Van() {
    Van::PrintExitTicket(15, "Van");
}
Bike::Bike(){
    Bike::PrintEnterTicket("Bike");
}
Bike::~Bike(){
    Bike::PrintExitTicket(5, "Bike");
}
parkingLot::parkingLot() =default;
parkingLot::~parkingLot() = default;
Vehicle* parkingLot::GetVehicle(int vehicleIndex){
    return vehicleVector[(size_t)vehicleIndex];//return the pointer of the ith car
}
int parkingLot::getSize(){
    return (int) vehicleVector.size();
}
void parkingLot::removeVehicle(int vehicleIndex){
    if ((size_t)vehicleIndex <= vehicleVector.size()-1) {
        delete vehicleVector[(size_t)vehicleIndex];
        vehicleVector.erase(vehicleVector.begin() + vehicleIndex);
    }
    else {
        cerr << "removeVehicle() denied to remove, to avoid segmentation fault." << endl;
    }
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
int actionDice(double chanceA,double chanceB)
{
    if (chanceA + chanceB <= 1.0){
        int tmp = rand()%10000;//tmp = 0~9999
        if (tmp <= (int)(chanceA*10000)){
            return 1;
        }
        else if (tmp <= (int)((chanceA+chanceB)*10000)){
            return 2;
        }
        else{
            return 0;
        }
    }
    else{
        cerr << "invalid input in actionDice() " << endl;
        return -1;
    }
}
void parkingLot::vehicleTypeDice()
{
    switch (rand()%4) {//rolling a dice to decide which vehicle to generate
        case 0: {
            Vehicle* tmpPtr = new Car;//assign new area of memory of Car
            vehicleVector.push_back(tmpPtr);//put the new pointer and the end of the vector storing pointers to Vehicles
            break;
        }
        case 1:{
            Vehicle* tmpPtr = new Motor;
            vehicleVector.push_back(tmpPtr);
            break;
        }
        case 2:{
            Vehicle* tmpPtr = new Van;
            vehicleVector.push_back(tmpPtr);
            break;
        }
        case 3:{
            Vehicle* tmpPtr = new Bike;
            vehicleVector.push_back(tmpPtr);
        }
    }
}
void parkingLot::vehicleIndexDice()
{
    parkingLot::removeVehicle(rand()%parkingLot::getSize());
}
void printATime(time_t enterTimeSec){
    string timeString = (string) ctime(&enterTimeSec);
    timeString[timeString.size()-1] = ';';
    cout << "Time of arrival: " <<timeString << endl;
}