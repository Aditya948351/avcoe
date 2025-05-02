#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
void init()
{
glClearColor(0.0,0.0,0.0,0.0);
gluOrtho2D(0,640,0,480);
}
void flood_it(int x, int y, float* fillColor, float* ic)
{
float color[3];
glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
if(color[0]==ic[0] && color[1]==ic[1] && color[2]==ic[2])
{
glColor3f(fillColor[0],fillColor[1],fillColor[2]);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
glFlush();
flood_it(x-2,y,fillColor,ic);
flood_it(x+1,y,fillColor,ic);
flood_it(x,y+1,fillColor,ic);
flood_it(x,y-2,fillColor,ic);
}
}
void polygon()
{
glLineWidth(3);
glPointSize(2);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
glBegin(GL_LINES);
glColor3f(1,0,0);
glVertex2i(150,100);
glVertex2i(300,300);
glColor3f(0,1,0);
glVertex2i(300,300);
glVertex2i(450,100);
glColor3f(0,0,1);
glVertex2i(150,100);
glVertex2i(450,100);
glEnd();
glFlush();
}
void mouse(int btn, int state, int x, int y){
y = 480-y;
if(btn==GLUT_LEFT_BUTTON)
{
if(state==GLUT_DOWN)
{
float intCol[] = {1,0,0};
float color[] = {0,0,1};
glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
flood_it(x,y,color,intCol);
}
}
} int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,480);
glutInitWindowPosition(200,200);
glutCreateWindow("Polygon Filling - Flood Fill");
glutDisplayFunc(polygon);
glutMouseFunc(mouse);
init();
glutMainLoop();
return 0;
}