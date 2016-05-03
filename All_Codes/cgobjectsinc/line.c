#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	
	glBegin(GL_LINES);
	glVertex3f(50,50,0.0);
	glVertex3f(50,100,0.0);
	glRotatef(180,0,0,1);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex3f(100,50,0.0);
	glVertex3f(100,100,0.0);
	glRotatef(180,0,0,1);
	glEnd();

	glFlush();
}

void main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("points and lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}
