//
// Created by Harry on 2021/12/10.
//
#include <iostream>
#include <ctime>
int actionDice(double a_LARGER_0_0001, double b_LARGER_0_0001);
using namespace std;
int main()
{
    int atime = 0;
    int btime = 0;
    srand((unsigned)time(0));
    for (int i = 0; i<= 10000;i++) {
        switch(actionDice(0.0001, 0.0001)){
            case 1:
                atime ++;
                //cout << endl;
                break;
            case 2:
                btime ++;
                //cout << endl;
        }
    }
    cout << atime << ' '<< btime << endl;
    return 0;
}
int actionDice(double a_LARGER_0_0001, double b_LARGER_0_0001)
{
    if (a_LARGER_0_0001 + b_LARGER_0_0001 <= 1.0){
        int tmp = rand()%10000;//tmp = 0~9999
        if (tmp <= (int)(a_LARGER_0_0001 * 10000)){
            return 1;
        }
        else if (tmp <= (int)((a_LARGER_0_0001 + b_LARGER_0_0001) * 10000)){
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