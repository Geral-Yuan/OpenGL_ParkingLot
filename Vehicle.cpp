#include "parking_lot.h"
//vehicles
//motion of vehicles
void Vehicle::move(Vec dir)
{
	anchor = anchor + dir;
}
//rotation of vehicles
void Vehicle::rotate(double angle)
{
	x_dir = x_dir << angle;
	y_dir = y_dir << angle;
}
//arrival tickets printed for vehicles
void Vehicle::print_arr_ticket(int time, v_type type, int slot_num){
    string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
    cout << endl << "----------Arrival Ticket----------" << endl;
    int hour = 8 + (int)time/60;
    int min = 0 + time%60;
    cout << "Time of arrival: " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << min << ";" << endl;
    cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
    cout << "Slot: No."<< slot_num << ";" << endl;
}
//departure tickets printed for vehicles
void Vehicle::print_exit_ticket(int in_time, v_type type, int out_time){
    double price = cal_price(in_time,type, out_time);
    string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
    cout << "----------Departure Ticket----------" << endl;
    cout << "Time spent in the parking lot: " << (out_time-in_time) << " hours;" << endl; //duration
    cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
    cout << "Price: " << price << "¥;" << endl;
}
//price calculation at departure
double Vehicle::cal_price(int in_time, v_type type, int out_time){
    int price_table[4] = {15,20,5,10};/* price per hour*/
    return (double)price_table[type]*(double)(out_time-in_time)/60.0;
}

//car that is a vehicle
Car::Car(Vec anchor, Vec x_dir, Vec y_dir)
{
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
	double L = 20, H = 6, d = 10, s = 3, R = 2;
	Vec v1 = y_dir * (-H / 2);
	Vec v2 = y_dir * (H / 2);
	Vec v3 = x_dir * (-d / 2) + y_dir * (-H);
	Vec v4 = x_dir * (d / 2) + y_dir * (-H);
	Vec v11 = x_dir * (L / 2) + y_dir * (H / 2);
	Vec v12 = x_dir * (L / 2) + y_dir * (-H / 2);
	Shape[0] = new Rec(anchor + v1, v11, v12, 0, 1, 0);
	Vec v21 = x_dir * (d / 2) + y_dir * (H / 2);
	Vec v22 = x_dir * (d / 2 + s) + y_dir * (-H / 2);
	Vec v23 = x_dir * (-d / 2 - s) + y_dir * (-H / 2);
	Vec v24 = x_dir * (-d / 2) + y_dir * (H / 2);
	Shape[1] = new Trapezium(anchor + v2, v21, v22, v23, v24, 0, 0, 1);
	Shape[2] = new Poly(anchor + v3, 80, R, 1, 0, 0);
	Shape[3] = new Poly(anchor + v4, 80, R, 1, 0, 0);
}
void Car::draw()
{
	for (int i = 0; i < 4; i++)
		Shape[i]->draw();
}
Car::~Car()
{
	for (int i = 0; i < 4; i++)
		delete Shape[i];
}

//van that is a vehicle
Van::Van(Vec anchor, Vec x_dir, Vec y_dir)
{
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
}
void Van::draw()
{
}
Van::~Van()
{
}

//bicycle that is a vehicle
Bicycle::Bicycle(Vec anchor, Vec x_dir, Vec y_dir)
{
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
}
void Bicycle::draw()
{
}
Bicycle::~Bicycle()
{
}

//motorcycle that is a vehicle
Motorcycle::Motorcycle(Vec anchor, Vec x_dir, Vec y_dir)
{
	this->anchor = anchor;
	this->x_dir = x_dir;
	this->y_dir = y_dir;
}
void Motorcycle::draw()
{
}
Motorcycle::~Motorcycle()
{
}
