#include<GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);          // Clear the screen
    glColor3f(1.0, 0.0, 0.0);             // Set the color to red
    glBegin(GL_POINTS);                    // Start drawing points
        glVertex2f(10.0, 10.0);           // Draw a point at (10, 10)
    glEnd();                              // End drawing points
    glFlush();                            // Force execution of all OpenGL commands
}

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);     // Set the background color to black
    glColor3f(1.0, 0.0, 0.0);             // Set the point color to red
    glPointSize(10.0);                    // Set the point size to 10
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);   // Set the 2D orthogonal view (viewport)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(700, 800);           // Set the window size
    glutInitWindowPosition(0, 0);           // Set the window position on screen
    glutCreateWindow("Points");             // Create the window with the title "Points"

    myinit();                               // Call initialization function to set up OpenGL settings
    glutDisplayFunc(display);               // Register the display function

    glutMainLoop();                         // Start the GLUT main loop, and keep the window open
}
