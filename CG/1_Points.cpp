#include<GL/glut.h>


void display() {
  glClear(GL_COLOR_BUFFER_BIT); //Clears the buffer
  glColor3f(1.0,1.0,1.0); //every vertex has its own color
  glBegin(GL_POINTS);
  glVertex2f(10.0,10.0);
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1080,720);
  glutInitWindowPosition(0,0);
  glutCreateWindow("1. Points");

  glutDisplayFunc(display);  
  
  glutMainLoop();
}
