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


vector<pair<float,float>>v;

map<float,int>mFlag;
map<float,int>sFlag;
struct Edge{
    float ymin,ymax,x,invm;
    Edge(float a,float b,float c,float d){
        ymin = a;
        ymax = b;
        x = c;
        invm = d;
    }
    Edge(){
    }
};
vector<Edge>arr;
bool cmpE(Edge a,Edge b){
    return a.ymin<b.ymin;
}
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    v.push_back({6,0});
    v.push_back({6,2});
    v.push_back({4,4});
    v.push_back({1,3});
    v.push_back({-2,6});
    v.push_back({-4,2});
    v.push_back({0,0});
    int n = v.size();
    glColor3f(1.0,1.0,1.0);
    for(int i=0;i<v.size();i++){
        glVertex3f(v[i].first,v[i].second,0.0);
        glVertex3f(v[(i+1)%n].first,v[(i+1)%n].second,0.0);
    }

    float smin=1000.0,smax=-1000.0,ymin,ymax,t,invC;

    for(int i=0;i<n;i++){
        if(v[i].second==v[(i+1)%n].second)
        {
            sFlag[v[i].second] =1;
            continue;
        }
        ymin = min(v[i].second,v[(i+1)%n].second);
        ymax = max(v[i].second,v[(i+1)%n].second);
        if(ymin == v[i].second)t = v[i].first;
        else t = v[(i+1)%n].first;
        invC = (v[(i+1)%n].first-v[i].first)/((v[(i+1)%n].second-v[i].second));
        //cout<<invC<<endl;
        arr.push_back(Edge(ymin,ymax,t,invC));
        mFlag[ymin] = 1;
        smin = min(smin,ymin);
        smax= max(smax,ymax);
    }
    //cout<<"wow"<<endl;
    for(int i=0;i<arr.size();i++){
        if(mFlag[arr[i].ymax])arr[i].ymax--;
    }
    sort(arr.begin(),arr.end(),cmpE);


    for(int i=smin;i<=smax;i++){
        vector<pair<float,float>> points;
        for(int j=0;j<arr.size();j++)
        {
            float x, y;
            if(arr[j].ymin<=i&&arr[j].ymax>=i){
                x = arr[j].x;
                y = i;
                arr[j].x+=arr[j].invm;
                points.push_back({x,y});
            }
        }
        sort(points.begin(),points.end());

        for(int k=0;k<points.size();k+=2){
            if(sFlag[points[k].second])continue;
            glColor3f(1.0,0.0,0.0);
            glVertex3f(points[k].first,points[k].second,0.0);
            glVertex3f(points[k+1].first,points[k+1].second,0.0);
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
