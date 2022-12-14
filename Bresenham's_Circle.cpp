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

//plot circle (x-3/2)^2 + (y-7/2)^2 = 43
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
    float dx,dy,x1,x2,y1,y2,m,x,y,d,dS,dT,r,a,b;
    a = 3/2;
    b = 7/2;
    int i,j,k;
    r =sqrt(49);
    x =  0;
    y = r;
    d = 3 - 2*r;

    glColor3f(1.0,1.0,1.0);
    while(x<=y){
        glVertex3f(x+a,y+b,0.0);
        glVertex3f(y+a,x+b,0.0);

        glVertex3f(x+a,-y+b,0.0);
        glVertex3f(y+a,-x+b,0.0);

        glVertex3f(-y+a,-x+b,0.0);
        glVertex3f(-x+a,-y+b,0.0);

        glVertex3f(-x+a,y+b,0.0);
        glVertex3f(-y+a,x+b,0.0);
        if(d<0){
            d = d = 4*x+6;
        }
        else{
            d = d + 4*(x-y)+10;
            y--;
        }
        x++;
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
