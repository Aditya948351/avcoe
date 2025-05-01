#include<GL/glut.h>
#include<iostream>
using namespace std;

float x1,y1,x2,y2;
float dx,dy,e,x,y;

void drawLine() {
  
}

void display() {
  glutOrtho2D(-100.0,100,-100,100);
  
}

void init(void) {
  
}

int main(int argc, char** argv) {
  glutInit(& argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(720,600);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Bresenham Line Drawing Algorithm");
  
  glutDisplayFunc(display);
  init();
  
  glutMainLoop();
  
}

