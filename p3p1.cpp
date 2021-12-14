//
// Created by ljr and ghy on 2021/12/9.
// Updated by ghy on 2021/12/11 11:15
//
#include "p3p1.h"
using namespace std;
Vehicle::~Vehicle() = default;
void Vehicle::PrintEnterTicket(const string& VehicleTypeName, int* slot, time_t demoStart) {
    cout << endl << "----------Arrival Ticket----------" << endl;
    enterTimeSec = time(nullptr);
    printATime2(enterTimeSec-demoStart,"Time of arrival: ","(since demo starts)");
    cout << "Type of vehicle: " << VehicleTypeName << ";" << endl;
    slotNum = FindEmpty(slot);
    cout << "Slot: Floor " << (slotNum / 20)+1 << " No." << slotNum - 20 * (int)(slotNum / 20) << endl;
}
void Vehicle::PrintExitTicket(double MoneyPerH, const string& VName) const {
    cout << endl << "----------Departure Ticket----------" << endl;
    time_t exitTimeSec = time(nullptr);
    printATime2(exitTimeSec - enterTimeSec,"Time spent in the parking lot: ","");
    cout << "Type of vehicle: " << VName << ";" << endl;
    double price=MoneyPerH*(double)(exitTimeSec - enterTimeSec)*(TCoefficient/60);
    cout << "Price: " << fixed << setprecision(precisionNumber)<< price << endl;
}
void Vehicle::removeSlotNum(int* slot) const {
    slot[slotNum-1] = 0;
}
Car::Car(int* slot,time_t demoStart) {
    Car::PrintEnterTicket("car", slot, demoStart);
}
Car::~Car() {
    Car::PrintExitTicket(10, "car");
}
Motor::Motor(int* slot,time_t demoStart){
    Motor::PrintEnterTicket("Motor", slot, demoStart);
}
Motor::~Motor() {
    Motor::PrintExitTicket(8, "Motor");
}
Van::Van(int* slot,time_t demoStart){
    Van::PrintEnterTicket("Van", slot, demoStart);
}
Van::~Van() {
    Van::PrintExitTicket(15, "Van");
}
Bike::Bike(int* slot,time_t demoStart){
    Bike::PrintEnterTicket("Bike",slot,demoStart);
}
Bike::~Bike(){
    Bike::PrintExitTicket(5, "Bike");
}
parkingLot::parkingLot() =default;
parkingLot::~parkingLot() = default;
int parkingLot::getSize(){
    return (int) vehicleVector.size();
}
void parkingLot::removeVehicle(int vehicleIndex,int* slot){
    if ((size_t)vehicleIndex <= vehicleVector.size()-1) {
        vehicleVector[(size_t)vehicleIndex]->removeSlotNum(slot);
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
void parkingLot::vehicleTypeDice(int* slot, time_t demoStart)
{
    switch (rand()%4) {//rolling a dice to decide which vehicle to generate
        case 0: {
            Vehicle* tmpPtr = new Car(slot, demoStart);//assign new area of memory of Car
            vehicleVector.push_back(tmpPtr);//put the new pointer and the end of the vector storing pointers to Vehicles
            break;
        }
        case 1:{
            Vehicle* tmpPtr = new Motor(slot,demoStart);
            vehicleVector.push_back(tmpPtr);
            break;
        }
        case 2:{
            Vehicle* tmpPtr = new Van(slot,demoStart);
            vehicleVector.push_back(tmpPtr);
            break;
        }
        case 3:{
            Vehicle* tmpPtr = new Bike(slot,demoStart);
            vehicleVector.push_back(tmpPtr);
        }
    }
}
void parkingLot::vehicleIndexDice(int* slot)
{
    parkingLot::removeVehicle(rand()%parkingLot::getSize(),slot);
}
void printATime(time_t enterTimeSec){
    string timeString = (string) ctime(&enterTimeSec);
    timeString[timeString.size()-1] = ';';
    cout << "Time of arrival: " <<timeString << endl;
}
int FindEmpty(int* slot) {
    for (int i=0;i<=capacity-1;i++) {
        if (slot[i] == 0) {
            slot[i] = 1;
            return i+1;
        }
    }
    return 0;
}
void printATime2(time_t Second, const string& information,const string& endInformation){
    cout << information;
    /*Minute is the Mock minute in demo*/
    time_t Minute = Second*(time_t)TCoefficient;
    int MinutesInADay = (int)(Minute%MinutePerDay);
    int Day = (int)((Minute-MinutesInADay)/MinutePerDay);
    if (Day!=0)
    {cout << Day <<" Day(s) ";}
    int MinutesInAnHour = (int)(MinutesInADay%60);
    int Hour = (int)((MinutesInADay-MinutesInAnHour)/60);
    if (Hour!=0)
    {cout << Hour <<" Hour(s) ";}
    if (MinutesInAnHour!=0)
    {cout << MinutesInAnHour << " Minute(s) ";}
    cout << endInformation <<endl;
}