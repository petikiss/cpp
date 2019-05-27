// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle.

#include "GL/freeglut.h"
#include "GL/gl.h"

int onMouse = 0;

void drawTriangle()
{
   if (onMouse == 1)
   {
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex3f(-0.7, 0.7, 0);
                glVertex3f(0.7, 0.7, 0);
                glVertex3f(0, -1, 0);
        glEnd();

    glFlush();
   }
}



void mouseClicks(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
       onMouse = 1;
    }
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating a triangle");
    glutMouseFunc(mouseClicks);

    glutDisplayFunc(drawTriangle);


    glutMainLoop();
    return 0;
}
