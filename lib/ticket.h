#ifndef TICKET_H
#define TICKET_H

#include "parking_lot.h"

//general ticket
class Ticket{
public:
    virtual void print() = 0;
    //get the time of the ticket
    int get_time(){return time;}
    //set the time of the ticket
    void set_time(int current_time){time = current_time;}
    virtual ~Ticket() = 0;
protected:
    int time;
    v_type type;
};

//arrival ticket
class Arr_ticket : public Ticket{
public:
    //generate an arrival ticket
    Arr_ticket(Vec* _anchor, int _time, v_type _type){
        anchor = _anchor;
        time = _time;
        type = _type;
    }
    //print
    void print(){
        string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
        cout << "----------Arrival Ticket----------" << endl;
        cout << "Time of arrival: " << time << ";" << endl;
        cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
        cout << "Empty slot: "<< ";" << endl;
    }
private:
    //every enter ticket is linked to the anchor of a slot
    Vec* anchor;
};

//departure ticket
class Dep_ticket : public Ticket{
public:
    //generate a departure ticket with time: duration
    Dep_ticket(int _time, v_type _type){
        time = _time;
        type = _type;
    }
    //calculate the price
    void cal_price(){
        int type_prize[4] = {10,20,30,40};
        price = type_prize[type]*time;
    }
    //print
    void print(){
        string vehicle[4] = {"Car", "Van", "Motorcycle", "Bike"};
        cout << "----------Departure Ticket----------" << endl;
        cout << "Time spent in the parking lot: " << time << ";" << endl;//duration
        cout << "Type of vehicle: " << vehicle[type] << ";" << endl;
        cout << "Price: " << price << ";" << endl;
    }
    //set the price on the ticket
    void set_price(int _price){price = _price;}
private:
    int price;
};

#endif /* ticket_h */
