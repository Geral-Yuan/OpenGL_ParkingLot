#ifndef P3P1_H
#define P3P1_H

#include<ctime>
#include<iostream>
#include <cstdlib>

class Vehicle {
    public:
        void generate();
        void remove();
        virtual void PrintEnterTicket();
        virtual void PrintExitTicket(int exittime);
        virtual int CountPrice(int exittime);
    
    protected:
        int entertime;
        int slotnum;
};

class Car : public Vehicle {
    public:
        int CountPrice(int exittime);
        void PrintEnterTicket();
        void PrintExitTicket(int exittime);
};

class Van : public Vehicle {
    public:
        int CountPrice(int exittime);
        void PrintEnterTicket();
        void PrintExitTicket(int exittime);
};


class Motor : public Vehicle {
    public:
        int CountPrice(int exittime);
        void PrintEnterTicket();
        void PrintExitTicket(int exittime);
};


class Bike : public Vehicle {
    public:
        int CountPrice(int exittime);
        void PrintEnterTicket();
        void PrintExitTicket(int exittime);
};


#endif