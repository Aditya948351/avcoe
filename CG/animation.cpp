#include <GL/glut.h>
float rt = 0.0f;
void init(int Width, int Height)
{
glClearColor(1.1, 1.1, 1.1, 1.1);
glMatrixMode(GL_PROJECTION);
gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,50.0f);
glMatrixMode(GL_MODELVIEW);
}
float ballX = -0.5f;
float ballY = 0.0f;
float ballZ = 0.0f;
void Draw()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(rt,0.0f,-6.0f);
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,0.0);
glVertex3f(-1.0f, 1.0f, 0.0f);
glVertex3f(0.4f, 1.0f, 0.0f);
glVertex3f(1.0f, 0.4f, 0.0f);
glColor3f(0.0,0.0,0.0);
glVertex3f( 1.0f,0.0f, 0.0f);
glColor3f(0.0,0.0,0.0);
glVertex3f(-1.0f,0.0f, 0.0f);
glEnd();
glColor3f(1.0, 0.0, 0.0);
glTranslatef(ballX,ballY,ballZ);
glutSolidSphere (0.3, 20, 20);
glTranslatef(ballX+1.5,ballY,ballZ);
glutSolidSphere (0.3, 20, 20);
rt+=0.005f;
if(rt>2)
rt=-2.0f;
glutSwapBuffers();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE );
glutInitWindowSize(640, 480);
glutInitWindowPosition(0, 0);
glutCreateWindow("Moving Car");
glutDisplayFunc(Draw);
glutIdleFunc(Draw);
init(640,480);
glutMainLoop();
return 0;
}
