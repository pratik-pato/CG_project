
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define  RADDEG  57.29577951f

float XUP[3] = {1,0,0}, XUN[3] = {-1, 0, 0},
  YUP[3] = {0,1,0}, YUN[3] = { 0,-1, 0},
  ZUP[3] = {0,0,1}, ZUN[3] = { 0, 0,-1},
  ORG[3] = {0,0,0};

GLfloat viewangle = 0, tippangle = 0, traj[120][3];

GLfloat d[3] = {0, -1, 0};
float i,theta;
GLfloat  xAngle = 45, yAngle = 0.0, zAngle = 0.0,angle=0.0;
int wheelflag=0;   //to switch fog effect
GLUquadricObj *t;
GLfloat xs=1.0,ys=1.0,zs=1.0,xw=0.0;

//------------------------------------------------------------------------


void Keyboard (unsigned char key, int x, int y)
{
  switch (key) {

  case 's' : d[0] += 1;
    if(d[0]==3)
      d[0]=-2;
    break;
  
  case 'a' : d[0] -= 1;
    if(d[0]==-3)
      d[0]=2;
    break;
  

  default:
    {}//printf ("   Keyboard %c == %d\n", key, key);
  }

  glutPostRedisplay();
}
//------------------------------------------------------------------------------

void Draw_Box (void)
{

  glColor3f(1.0,.75,0.0);
  glPointSize(30.0);
  glBegin(GL_POINTS);
  glVertex3f(0.2,0.3,0.3);
  glVertex3f(0.2,0.3,0.5);
  glEnd();
  glPointSize(200.0);



  glBegin(GL_QUADS);                /* OBJECT MODULE*/

  /* top of cube*/
  //************************FRONT BODY****************************************
  glColor3f(0,1,0);
  glVertex3f( 0.2, 0.4,0.6);
  glVertex3f(0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);

  /* bottom of cube*/
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* front of cube*/
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.2, 0.4,0.6);
  glVertex3f(0.2,0.4,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* back of cube.*/
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.6,0.5,0.2);
  glVertex3f( 0.6,0.2,0.2);

  /* left of cube*/
  glVertex3f(0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.2,0.4,0.6);

  /* Right of cube */
  glVertex3f(0.2,0.2,0.2);
  glVertex3f( 0.6,0.2,0.2);
  glVertex3f( 0.6,0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);
//****************************************************************************
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(1.7,0.65,0.2);        //top cover
  glVertex3f(1.7,0.65,0.6);
//***************************back guard******************************
  glColor3f(1,0,0);            /* Set The Color To Blue*/
  glVertex3f( 1.8, 0.5,0.6);
  glVertex3f(1.8, 0.5,0.2);
  glVertex3f(2.1, 0.4, 0.2);
  glVertex3f(2.1,0.4,0.6);

  /* bottom of cube*/
  glVertex3f( 2.1,0.2,0.6);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(1.8,0.2,0.6);
  glVertex3f( 1.8,0.2,0.6);

  /* back of cube.*/
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(2.1,0.2,0.6);

  /* left of cube*/
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);

  /* Right of cube */
  glVertex3f(1.8,0.2,0.6);
  glVertex3f(1.8,0.5,0.6);
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.2,0.6);
//******************MIDDLE BODY************************************
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.2,0.6);
  glVertex3f(1.8, 0.2, 0.6);
  glVertex3f(1.8,0.5,0.6);

  /* bottom of cube*/
  glVertex3f( 0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f( 1.8,0.2,0.6);

  /* back of cube.*/
  glVertex3f(0.6,0.5,0.2);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
//*********************ENTER WINDOW**********************************
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.2);
  glVertex3f(0.75, 0.5,0.2);        //quad front window
  glVertex3f(1.2, 0.5, 0.2);
  glVertex3f( 1.22,0.63,0.2);

  glVertex3f(1.27,0.63,.2);
  glVertex3f(1.25,0.5,0.2);        //quad back window
  glVertex3f(1.65,0.5,0.2);
  glVertex3f(1.67,0.63,0.2);

  glColor3f(0.5,0.5,0);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(0.7,0.5,.2);       //first separation
  glVertex3f(0.75,0.5,0.2);
  glVertex3f(0.77,0.65,0.2);

  glVertex3f(1.2,0.65,0.2);
  glVertex3f(1.2,0.5,.2);       //second separation
  glVertex3f(1.25,0.5,0.2);
  glVertex3f(1.27,0.65,0.2);

  glVertex3f(1.65,0.65,0.2);
  glVertex3f(1.65,0.5,.2);     //3d separation
  glVertex3f(1.7,0.5,0.2);
  glVertex3f(1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.2);
  glVertex3f(0.75, 0.63,0.2);        //line strip
  glVertex3f(1.7, 0.63, 0.2);
  glVertex3f( 1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.6);
  glVertex3f(0.75, 0.63,0.6);        //line strip
  glVertex3f(1.7, 0.63, 0.6);
  glVertex3f( 1.7,0.65,0.6);

  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.6);
  glVertex3f(0.75, 0.5,0.6);        //quad front window
  glVertex3f(1.2, 0.5, 0.6);
  glVertex3f( 1.22,0.63,0.6);

  glVertex3f(1.27,0.63,.6);
  glVertex3f(1.25,0.5,0.6);        //quad back window
  glVertex3f(1.65,0.5,0.6);
  glVertex3f(1.67,0.63,0.6);

  glColor3f(0.5,0.5,0);
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.5,.6);       //first separation
  glVertex3f(0.75,0.5,0.6);
  glVertex3f(0.77,0.65,0.6);

  glVertex3f(1.2,0.65,0.6);
  glVertex3f(1.2,0.5,.6);       //second separation
  glVertex3f(1.25,0.5,0.6);
  glVertex3f(1.27,0.65,0.6);

  glVertex3f(1.65,0.65,0.6);
  glVertex3f(1.65,0.5,.6);
  glVertex3f(1.7,0.5,0.6);
  glVertex3f(1.7,0.65,0.6);
  glEnd();


 //**************************************************************
  glBegin(GL_QUADS);

  /* top of cube*/
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);        //quad front window
  glVertex3f(0.7, 0.65, 0.2);
  glVertex3f( 0.7,0.65,0.6);

  glVertex3f(1.7,0.65,.6);
  glVertex3f(1.7,0.65,0.2);        //quad back window
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(1.8,0.5,0.6);

  if(wheelflag)
  {
  	  glPushMatrix();
  	  glTranslatef(0.0,0,0);
  	  glColor3f(0.5,.2,0.3);
  	  glBegin(GL_QUADS);
  	  for(i=0;i<200;i+=0.2)
  	  {
  		  glVertex3f(-100+i,0,1);
  		  glVertex3f(-99.9+i,0,1);
  		  glVertex3f(-99.9+i,0.2,1);
  		  glVertex3f(-100+i,0.2,1);
  		  i+=0.5;
  	  }
  	  for(i=0;i<200;i+=0.2)
  	  {
  		  glVertex3f(-100+i,0,0);
  		  glVertex3f(-99.9+i,0,0);
  		  glVertex3f(-99.9+i,0.2,0);
  		  glVertex3f(-100+i,0.2,0);
  		  i+=0.5;
  	  }
  	  glEnd();
  	  glPopMatrix();
  }
//*************************************************************************************************
glBegin(GL_TRIANGLES);                /* start drawing the cube.*/

  /* top of cube*/
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f( 0.7,0.65,0.6);       //tri front window
  glVertex3f(0.7,0.5,0.6);

  glVertex3f( 0.6, 0.5,0.2);
  glVertex3f( 0.7,0.65,0.2);       //tri front window
  glVertex3f(0.7,0.5,0.2);

  glVertex3f( 1.7, 0.65,0.2);
  glVertex3f( 1.8,0.5,0.2);       //tri back window
  glVertex3f( 1.7,0.5,0.2);

  glVertex3f( 1.7, 0.65,0.6);
  glVertex3f( 1.8,0.5,0.6);       //tri back window
  glVertex3f(1.7,0.5,0.6);

glEnd();
//************IGNITION SYSTEM**********************************
// glPushMatrix();
//    glColor3f(0.7,0.7,0.7);
//    glTranslatef(1.65,0.2,0.3);
//    glRotatef(90.0,0,1,0);
//    gluCylinder(t,0.02,0.03,.5,10,10);
// glPopMatrix();
//********************WHEEL*********************************************

glColor3f(0.7,0.7,0.7);
glPushMatrix();
  glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.62);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(0.6,0.2,0.18);
  glVertex3f(0.6+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.18);
  glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(theta=0;theta<360;theta=theta+20)
	  {
  glVertex3f(1.7,0.2,0.62);
 glVertex3f(1.7+(0.08*(cos(((theta+angle)*3.14)/180))),0.2+(0.08*(sin(((theta+angle)*3.14)/180))),0.62);
	  }
glEnd();
  glTranslatef(0.6,0.2,0.6);
  glColor3f(0,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,-0.4);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(1.1,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,0.4);
  glutSolidTorus(0.025,0.07,10,25);
  glPopMatrix();
//*************************************************************
  glPopMatrix();
  glEnable(GL_DEPTH_TEST);
  glutPostRedisplay();
  glutSwapBuffers();
}


//------------------------------------------------------------------------------


void redraw (void)
{
  int v;

  glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable (GL_DEPTH_TEST);

  glLoadIdentity ();

  glTranslatef (0, 0, -3);

  glDisable (GL_LIGHTING);


  glPushMatrix ();
  glTranslatef (d[0], d[1], d[2]);    // Move box down X axis.
  glScalef (1, 1, .5);
  Draw_Box ();
  glPopMatrix ();
 
  glutSwapBuffers();
}

//------------------------------------------------------------------------------


int main (int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(900, 600);
  glutInitWindowPosition (300, 300);
  glutInitDisplayMode    (GLUT_DEPTH | GLUT_DOUBLE);

  glutCreateWindow ("Orbital Font Demo");
  glutDisplayFunc  (   redraw   );
  glutKeyboardFunc (  Keyboard  );

  glClearColor (0.1, 0.0, 0.1, 1.0);

  glMatrixMode   (GL_PROJECTION);
  gluPerspective (60, 1.5, 1, 10);
  glMatrixMode   (GL_MODELVIEW);
  glutMainLoop   ();

  return 1;
}
//------------------------------------------------------------------------------
