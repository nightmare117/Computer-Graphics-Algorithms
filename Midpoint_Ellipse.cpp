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

//plot ellipse ((x-7)^2)/5^2 + ((y-5)^2)/7^2 = 1
void draw_coordinates()
{
    for(float i=-20.0;i<=20.0;i++){
        glColor3f(1.0,0.0,0.0);
        glVertex3f(i,0.0,0.0);
        glVertex3f(0.0,i,0.0);
    }
}

void draw_points(float x,float y,float a,float b){
    glVertex3f(x+a,y+b,0.0);
    //glVertex3f(y+a,x+b,0.0);

    glVertex3f(x+a,-y+b,0.0);
    //glVertex3f(y+a,-x+b,0.0);

    //glVertex3f(-y+a,-x+b,0.0);
    glVertex3f(-x+a,-y+b,0.0);

    glVertex3f(-x+a,y+b,0.0);
    //glVertex3f(-y+a,x+b,0.0);*/
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glBegin(GL_POINTS);
    glBegin(GL_POINTS);
    draw_coordinates();

    glColor3f(1.0,1.0,1.0);
    float dx,dy,x1,x2,y1,y2,m,x,y,d,dS,dT,r,a,b,aa,bb,aa2,bb2,fx,fy,p;
    int i,j,k;
    glColor3f(1.0,1.0,1.0);
    a = 5.0;
    b = 7.0;
    x = 0;
    y = b;
    aa = a*a;
    bb =b*b;
    aa2 = aa*2;
    bb2 = bb*2;
    p = bb-aa*b + .25*aa;
    fx = 0;
    fy = aa2*b;
    while(fx<fy){
        draw_points(x,y,7.0,5.0);
        x++;
        fx = fx + bb2;
        if(p<0){
            p = p + fx + bb;
        }
        else{
            y--;
            fy = fy - aa2;
            p = p + fx + bb - fy;
        }
    }
    draw_points(x,y,7.0,5.0);
    p = bb*(x + 0.5)*(x + 0.5) + aa*(y-1)*(y-1)- aa*bb;
    while(y>0){
        y--;
        fy = fy-aa2;
        if(p>=0){
            p = p - fy + aa;
        }
        else{
            x++;
            fx = fx + bb2;
            p = p + fx - fy +aa;
        }
        draw_points(x,y,7.0,5.0);
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
