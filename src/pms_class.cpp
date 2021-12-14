//
//  pms_class.cpp
//  opengl
//
//  Created by Elaine Liu on 2021/12/14.
//

#include "pms.h"
void delay(time_t n){
    time_t start_time, cur_time;
    time(&start_time);
    do{
        time(&cur_time);
    }while(cur_time-start_time < n);
}
