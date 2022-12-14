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

//DDA (-5,1) to (8,13)

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //glBegin(GL_POINTS);
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);
    float dx,dy,x1,x2,y1,y2,m,x,y;
    int i,j,k;
    x1 = -5;
    x2 = 8;
    y1 = 1;
    y2 = 13;
    k = y2;
    j=y1;
    dx = x2-x1;
    dy = y2-y1;
    m = dy/dx;
    x=x1;
    y=y1;
    glVertex3f(x,y,0.0);
    if(abs(m)>1)
    {
        for(i=j+1;i<=k;i++)
        {
            x = x + 1/m;
            y= y +1.0;
            //cout<<x<<" "<<y<<endl;
            glVertex3f(x,y,0.0);
        }
    }
    else
    {
        k = x2;
        j = x1;
        for(i=j+1;i<=k;i++)
        {
            y = y + m;
            x = x +1.0;
            //cout<<x<<" "<<y<<endl;
            glVertex3f(x,y,0.0);
        }
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
