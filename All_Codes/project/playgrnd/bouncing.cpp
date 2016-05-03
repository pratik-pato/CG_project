#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static int flag=0;
float tx=0.0,ty=0.0,tz=0.0;
float ball_x=0.0,ball_y=0.0,ball_z=0.0;
GLfloat d[3] = {0, -1, 0};
void reshaped(int w,int h){}


void Draw_Box (void)
{
  glBegin (GL_QUADS);

  glColor3f  ( 0.0,  0.7, 0.1);     // Front - green
  glVertex3f (-1.0,  1.0, 1.0);
  glVertex3f ( 1.0,  1.0, 1.0);
  glVertex3f ( 1.0, -1.0, 1.0);
  glVertex3f (-1.0, -1.0, 1.0);

  glColor3f  ( 0.9,  1.0,  0.0);    // Back  - yellow
  glVertex3f (-1.0,  1.0, -1.0);
  glVertex3f ( 1.0,  1.0, -1.0);
  glVertex3f ( 1.0, -1.0, -1.0);
  glVertex3f (-1.0, -1.0, -1.0);

  glColor3f  ( 0.2, 0.2,  1.0);     // Top - blue
  glVertex3f (-1.0, 1.0,  1.0);
  glVertex3f ( 1.0, 1.0,  1.0);
  glVertex3f ( 1.0, 1.0, -1.0);
  glVertex3f (-1.0, 1.0, -1.0);

  glColor3f  ( 0.7,  0.0,  0.1);    // Bottom - red
  glVertex3f (-1.0, -1.0,  1.0);
  glVertex3f ( 1.0, -1.0,  1.0);
  glVertex3f ( 1.0, -1.0, -1.0);
  glVertex3f (-1.0, -1.0, -1.0);

  glEnd();

}


void updateBall()
{
    if(!flag)
    {
        d[0]+=0.00;
	d[1]+=0.00;
	d[2]+=0.02;
        if(d[2]>0.8)
            flag=1;
    }
    if(flag)
    {
        d[0]-=0.00;
	d[1]-=0.00;
	d[2]-=0.02;
        if(d[2]<-0.8)
            flag=0;
    }
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  
        glClearColor(0,0,0,0);
        glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(d[0],d[1],d[2]);
        //glutSolidSphere(0.2,30,30);
	glPushMatrix ();
	glTranslatef (d[0], d[1], d[2]);    // Move box down X axis.
	glScalef (0.2, 0.2, 0.2);
	Draw_Box ();
	glPopMatrix ();
	
	glPushMatrix ();
	glTranslatef (d[0], d[1], (d[2]-2.0f));    // Move box down X axis.
	glScalef (0.2, 0.2, 0.2);
	Draw_Box ();
	glPopMatrix ();

        glPopMatrix();
        updateBall();
        glutSwapBuffers();
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(720,720);
    glutCreateWindow("Bouncing Ball");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshaped);
    glutMainLoop();  
}
