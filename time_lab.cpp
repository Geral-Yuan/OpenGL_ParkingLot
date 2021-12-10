//
// Created by Harry on 2021/12/8.
//
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
void printLocalTimeDetail();
void printLocalTimePithy();
int delaying(int timed);
void threeWayPrintTime();
void testAddTime(size_t num);
void chronoDelay(double second);
int main()
{
    //printLocalTimeDetail();
    //printLocalTimePithy();
    threeWayPrintTime();
    //threeWayPrintTime();
    //testAddTime(10000000);
    /*cout << "---------------------------------" << endl;
    delaying(5);
    printLocalTimePithy();*/
    //cout << "---------------------------------" << endl;
    //chronoDelay(2);
    //printLocalTimePithy();

    return 0;
}

int delaying(int timed)
{
    time_t timedd = (time_t) timed;
    const time_t ts = time(0);
    time_t te = 0;
    while(te==0 || te - ts <= timedd)
    {
        te = time(0);
    }
    return 1;
}
void printLocalTimeDetail(){
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
}
void threeWayPrintTime() {
    time_t t = time(0);
    if (t != (time_t) (-1))
    {
        cout << "The current time is " << asctime(localtime(&t)) << (intmax_t) t << " seconds since the Epoch" << endl;
        cout << "The current time is " << asctime(gmtime(&t)) << (intmax_t) t << " seconds since the Epoch" << endl;
        //asctime: ASCII time
        cout << "The current time is " << ctime(&t) << (intmax_t) t << " seconds since the Epoch" << endl;
        string timeString = (string) ctime(&t);
        timeString[timeString.size()-1] = ';';
        cout << timeString << endl;

    }
}
void testAddTime(size_t num)
{
    time_t t = time(0);
    size_t sum = 0;
    for (size_t i = 0; i <= num; i++)
    {
        sum+=i;
    }
    cout << sum << endl;
    time_t t2 = time(0);
    cout << (intmax_t)t2-t << endl;
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
void printLocalTimePithy(){
    time_t t = time(0);
    tm* localTimePointer = localtime(&t);
    cout << " Current Date: " << (localTimePointer->tm_mday) << "/" << (localTimePointer->tm_mon) + 1 << "/" << (localTimePointer->tm_year) + 1900 << endl;
    cout << " Current Time: " << (localTimePointer->tm_hour) << ":" << (localTimePointer->tm_min) << ":" << (localTimePointer->tm_sec) << endl;
    cout << endl;
}
//reference
/*
https://en.cppreference.com/w/c/chrono/tm
https://en.cppreference.com/w/c/chrono/time
https://www.w3resource.com/cpp-exercises/basic/cpp-basic-exercise-34.php
https://en.cppreference.com/w/cpp/chrono/system_clock/now
 */



