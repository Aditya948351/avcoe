#include<GL/glut.h>


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POINTS);
        glVertex2f(250.0,250.0);
    glEnd();
    glFlush();
}

void myinit() {
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(20.0);
    gluOrtho2D(0.0,499.0,0.0,0.499);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Points");
    
    myinit();
    glutDisplayFunc(display);
    
    glutMainLoop();
}
