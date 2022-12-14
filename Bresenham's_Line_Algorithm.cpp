/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<cmath>
#include <stdlib.h>

//DDA (6,-10) to (-8,13)
//m <0, so (-8,13) -> (13,-8) , (6,-10) -> (-10,6) | both y axix*-1;
//(6,-10) to (13,-8)

void draw_coordinates()
{
    for(float i=-20.0;i<=20.0;i++){
        glColor3f(1.0,0.0,0.0);
        glVertex3f(i,0.0,0.0);
        glVertex3f(0.0,i,0.0);
    }
}
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glBegin(GL_POINTS);
    glBegin(GL_POINTS);
    draw_coordinates();


    glColor3f(1.0,1.0,1.0);
    float dx,dy,x1,x2,y1,y2,m,x,y,d,dS,dT;
    int i,j,k;
    x1 = -10.0;
    x2 = 13.0;
    y1 = -6.0;
    y2 = 8.0;
    x =x1;
    y = y1;
    dy = y2 - y1;
    dx = x2 - x1;
    dT = 2*(dy-dx);
    dS = 2*dy;
    d = 2*dy-dx;
    glVertex3f(-y,x,0.0);
    while(x<x2){
        x++;
        if(d<0){
            d = d+dS;
        }
        else{
            y++;
            d = d + dT;
        }
        glVertex3f(-y,x,0.0);
    }
    glEnd();
    glFlush();
}
void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0,20.0,-20.0,20.0,-5.0,5.0);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );

    glutCreateWindow("Demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
