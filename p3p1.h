#include<ctime>
#include<iostream>
#include <cstdlib>

#ifndef P3P1_H
#define P3P1_H
class Vehicle {
    public:
        void generate();
        void remove();
        virtual void printenterticket();
        virtual void printexitticket(int exittime);
        virtual int countprice(int exittime);
    
    protected:
        int entertime;
        int slotnum;
};

class Car : public Vehicle {
    public:
        int countprice(int exittime);
        void printenterticket();
        void printexitticket(int exittime);
};

class Van : public Vehicle {
    public:
        int countprice(int exittime);
        void printenterticket();
        void printexitticket(int exittime);
};


class Motor : public Vehicle {
    public:
        int countprice(int exittime);
        void printenterticket();
        void printexitticket(int exittime);
};


class Bike : public Vehicle {
    public:
        int countprice(int exittime);
        void printenterticket();
        void printexitticket(int exittime);
};


#endif