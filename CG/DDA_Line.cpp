#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

float x1,y1,x2,y2;
float dx,dy,x,y,Xin,Yin,length;


void simpleLine() {
  cout<< "\nSimple Line\n" ;
  drawLine(0);
}
void dashedLine() {
  cout<< "\nDashed Line\n";
  drawLine(1);
}
void dottedLine() {
  cout<< "\nDotted Line\n";
  drawLine(2);
}

void display() {
  simpleLine();
  dashedLine();
  dottedLine();
}

void drawLine(int style) {
  cout << "Enter the value of x1: ";
  cin >> x1;
  cout << "Enter the value of y1: ";
  cin >> y1;
  cout << "Enter the value of x2: ";
  cin >> x2;
  cout << "Enter the value of y2: ";
  cin >> y2;

  dx = x2-x1;
  dy = y2-y1;

  length = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

  Xin = dx?length;
  Yin = dy/length;
  x = x1;
  y = y1;

  glBegin(GL_POINTS);
  for(int i=0;i <= length i++) {
    if(style == 0 || style == 1 && i%5 == 0 || style ==2 && i%2 == 0 ) {
      glVertex2i(x, y);      
    }
    x += Xinc;
    y += Yinc;
  }
  glEnd();
  glFlush();
}

void init(void) {
  glClearColor(1.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-100.0,100.0,-100.0,100.0);  
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(0.0,0.0);
  glutCreateWindow("DDA Line Drawing Algorithm");
  glutDisplayFunc(display);
  init();
  
  glutMainLoop();
}
