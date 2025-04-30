#include <GL/glut.h>

// Display function that will draw the points
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Set color to green for points (since background is black)
    glColor3f(0.0, 1.0, 0.0); 

    // Start drawing points
    glBegin(GL_POINTS);
        glVertex2f(10.0, 10.0);  // First point
        glVertex2f(150.0, 80.0); // Second point
        glVertex2f(100.0, 20.0); // Third point
        glVertex2f(200.0, 100.0);// Fourth point
    glEnd();

    glFlush(); // Ensure that all drawing commands are executed
}

// Initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set the background color to black
    glColor3f(0.0, 1.0, 0.0);          // Set the drawing color to green (for contrast)
    glPointSize(30.0);                 // Set the point size to 30 pixels (increase it)

    // Set the coordinate system for the viewport
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);  // Coordinate system (0,0) to (500,500)
}

// Reshape function to handle window resizing
void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Set the viewport size to match the window
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set the display mode to single buffer, RGB
    glutInitWindowSize(500, 500);  // Set the window size to 500x500
    glutInitWindowPosition(100, 100);  // Set the window position on screen
    glutCreateWindow("first program");  // Create the window with title "Points"
    
    init(); // Initialize OpenGL settings

    glutDisplayFunc(display);  // Register display function to render the window
    glutReshapeFunc(reshape);  // Register the reshape function for window resizing

    glutMainLoop();  // Start the GLUT event loop
}
