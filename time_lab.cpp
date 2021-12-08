//
// Created by Harry on 2021/12/8.
//
#include <iostream>
#include <ctime>
#include <cstdint>
using namespace std;

int main()
{

    time_t t = time(0);
    /*get the present time in second since the epoch
    time type is int type of the second since 1970/1/1
    time_t t = time(0); is the same
    e.g. t = 1638967376*/
    cout << ' ' << t << endl;
    tm* localtimepointer = localtime(&t);
    //give a pointer to the second since the epoch, and computer will change it into our local time
    cout << endl <<" Display the Current Date and Time :" << endl;
    {
    cout << " seconds = " << localtimepointer->tm_sec << endl;
    cout << " minutes = " << localtimepointer->tm_min << endl;
    cout << " hours = " << localtimepointer->tm_hour << endl;
    cout << " day of month = " << localtimepointer->tm_mday << endl;
    cout << " month of year = " << localtimepointer->tm_mon + 1 << endl;
    cout << " year = " << localtimepointer->tm_year + 1900 << endl;
    /*start from 1900*/
    cout << " weekday = " << localtimepointer->tm_wday << endl;
    cout << " day of year = " << localtimepointer->tm_yday << endl;
    //cout << " daylight savings = " <<(localtimepointer->tm_isdst )<< endl;
    cout << endl;
    }

    cout << " Current Date: " << (localtimepointer->tm_mday) << "/" << (localtimepointer->tm_mon) + 1 << "/" << (localtimepointer->tm_year) + 1900 << endl;
    cout << " Current Time: " << (localtimepointer->tm_hour) << ":" << (localtimepointer->tm_min) << ":" << (localtimepointer->tm_sec) << endl;
    cout << endl;


    if (t != (time_t) (-1))
    {
        cout << "The current time is " << asctime(localtime(&t)) << (intmax_t) t << " seconds since the Epoch" << endl;
        cout << "The current time is " << asctime(gmtime(&t)) << (intmax_t) t << " seconds since the Epoch" << endl;
        //asctime: ASCII time
        cout << "The current time is " << ctime(&t) << (intmax_t) t << " seconds since the Epoch" << endl;
    }
    return 0;
}
//reference
/*
https://en.cppreference.com/w/c/chrono/tm
https://en.cppreference.com/w/c/chrono/time
https://www.w3resource.com/cpp-exercises/basic/cpp-basic-exercise-34.php
 */