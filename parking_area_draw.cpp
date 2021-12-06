//
//  parking_area_draw.cpp
//  project 3
//
//  Created by Elaine Liu on 2021/12/5.
//

#include "parking_lot.h"

void single_park::draw(){
    //draw the outter layer of the whole parking lot
    double axis_points[6][2] = {{-30.0,-10.0}, {-30.0,110.0}, {20.0*(double)slot_num+30.0,110.0}, {20.0*(double)slot_num+30.0,0.0}, {0.0,0.0}, {0.0,-10.0}};
    glColor3d(0.0, 0.0, 0.0);
    glLineWidth(1.5);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i<8; i++){
        glVertex2d(axis_points[i][0], axis_points[i][1]);
    }
    glEnd();
    //draw seperate lines for the parking lot
    double seperate_lines[2] = {110.0,30.0};
    glBegin(GL_LINES);
    for(int i = 0; i<2; i++){
        for(int k = 0; k<slot_num+1; k++){
            glVertex2d((double)k*20.0, seperate_lines[i]);
            glVertex2d((double)k*20.0, seperate_lines[i]-30.0);
        }
    }
    glEnd();
    //draw the barrier inside
    double barrier_index[4][2] = {{10.0,50.0},{10.0,60.0}, {20.0*(double)slot_num-10.0,60.0}, {20.0*(double)slot_num-10.0,50.0}};
    glColor3d(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
    for(int k = 0; k<4; k++){
        glVertex2d(barrier_index[k][0], barrier_index[k][1]);
    }
    glEnd();
}
