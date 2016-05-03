#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

static int flag=0, squash = 0;
float tx=0.0,ty=0.0,tz=0.0;
float ball_x=0.0,ball_y=0.0,ball_z=0.0;

void drawCircle(float horRad, float vertRad)
{
	int i;
	float x2, y2, angle;
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(ball_x, ball_y, ball_z);

	if(squash) {
		horRad *= 0.5;
		vertRad *= 2;
		squash = 0;
	}

	for(angle = 1.0; angle < 361.0; angle += 0.2) {
		x2 = ball_x + sin(angle) * vertRad;
		y2 = ball_y + cos(angle) * horRad;
		glVertex3f(x2, y2, ball_z);
	}

	glEnd();
}

void reshaped(int w,int h){}

void updateBall()
{
    if(!flag)
    {
        ball_y+=0.005;
        if(ball_y>0.44) {
            flag=1;
	    squash = 1;
	}
    }
    if(flag)
    {
        ball_y-=0.005;
        if(ball_y<-0.44) {
            flag=0;
	    squash = 1;
	}
    }
}

void display()
{
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);  
        glClearColor(1,1,1,0);
        glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(ball_x,ball_y,ball_z);
        //glutSolidSphere(0.2,30,30);
	drawCircle(0.1, 0.1);
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
