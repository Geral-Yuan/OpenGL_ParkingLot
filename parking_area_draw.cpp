//
//  parking_area_draw.cpp
//  project 3
//
//  Created by Elaine Liu on 2021/12/5.
//

#include "parking_lot.h"

void parking_area_draw(){
    //draw the outter layer of the whole parking lot
    double axis_points[8][2] = {{40.0,120.0},{160.0,120.0},{160.0,230.0},{0.0,230.0},{0.0,0.0},{160.0,0.0},{160.0,110.0},{40.0,110.0}};
    glColor3d(0.0, 0.0, 0.0);
    glLineWidth(1.5);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i<8; i++){
        glVertex2d(axis_points[i][0], axis_points[i][1]);
    }
    glEnd();
    //draw seperate lines for the parking lot
    double seperate_lines[4] = {230.0,150.0,110.0,30.0};
    glBegin(GL_LINES);
    for(int i = 0; i<4; i++){
        for(int k = 0; k<6; k++){
            glVertex2d(40.0+(double)k*20.0, seperate_lines[i]);
            glVertex2d(40.0+(double)k*20.0, seperate_lines[i]-30.0);
        }
    }
    //one extra separation at 2F
    glVertex2d(20.0, 230.0);
    glVertex2d(20.0, 200.0);
    glEnd();
    //open the door for the parking lot
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(40.0, 0.0);
    glEnd();
    //draw the barriers inside
    double barrier_index[4][2] = {{40.0,170.0},{40.0,180.0},{140.0,180.0},{140.0,170.0}};
    glColor3d(0.0, 0.0, 0.0);
    for(int i = 0;i <2; i++){
        glBegin(GL_QUADS);
        for(int k = 0; k<4; k++){
            glVertex2d(barrier_index[k][0], barrier_index[k][1]-(double)i*120.0);
        }
        glEnd();
    }
    //draw the dotted line at the main lane
    glColor3d(0.7, 0.7, 0.7);
    glLineWidth(3.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINES);
    glVertex2d(20.0, 10.0);
    glVertex2d(20.0, 190.0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
