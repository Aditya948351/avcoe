#include<GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,1.0,1.0,1.0);
  glBegin(GL_POINTS);
  glVertex2f(10.0,10.0);
  
  glEnd();
  glFlush();

}

void myinit() {
  glClearColor(1.0,0.0,0.0);
  glColor3f(1.0,0.0,0.0);
  glPointSize(20.0);
  gluOrtho2D(0.0,499.0,0.0,499.0);
}


int main(int argc , char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  gkutInitWindowSize(1080,720);
  glutInitWindowPosition(0.0,0.0);
  glutCreateWindow("Points Program");
  
  glutDisplayFunc(display);
  myinit();
  
  glutMainLoop();
  
}
