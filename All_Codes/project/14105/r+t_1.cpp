
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define  RADDEG  57.29577951f

float XUP[3] = {1,0,0}, XUN[3] = {-1, 0, 0},
  YUP[3] = {0,1,0}, YUN[3] = { 0,-1, 0},
  ZUP[3] = {0,0,1}, ZUN[3] = { 0, 0,-1},
  ORG[3] = {0,0,0};

int arr1[10] = {1,1,1,1,1,1,1,1,1,1};

GLfloat origin[3] = {0,0,-10}; 

GLfloat viewangle = 0, tippangle = 0, traj[120][3];

GLfloat d[3] = {0, -1, 0};

GLfloat  xAngle = 45, yAngle = 0.0, zAngle = 0.0;


//------------------------------------------------------------------------
void reshaped(int w,int h){}

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

void obstacles(int *arr,int sz)
{
  int i=0;
  while(sz!=0)
    {
      if(arr[i]==1)
	{
	  i++;
	  sz--;
	  
	  glTranslatef (-6.0f, -1, d[2]+9);
	  Draw_Box ();
	}
      // if(arr[i]==2)
      // 	{
      // 	  i++;
      // 	  sz--;
      // 	  glTranslatef (-3.0f, d[1], d[2]+9);
      // 	  Draw_Box ();
      // 	}
      // if(arr[i]==3)
      // 	{
      // 	  i++;
      // 	  sz--;
      // 	  glTranslatef (0.0f, d[1], d[2]+9);
      // 	  Draw_Box ();
      // 	}
      // if(arr[i]==4)
      // 	{
      // 	  i++;
      // 	  sz--;
      // 	  glTranslatef (3.0f, d[1], d[2]+9);
      // 	  Draw_Box ();
      // 	}
      // if(arr[i]==5)
      // 	{
      // 	  i++;
      // 	  sz--;
      // 	  glTranslatef (6.0f, d[1], d[2]+9);
      // 	  Draw_Box ();
      // 	}
  
    }

}
void move(void)
{
  origin[1]-=0.01;  
  origin[2]+=0.01;  
}
//------------------------------------------------------------------------------


void redraw (void)
{
  int v;

  ////q
  ////q

  glClear  (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable (GL_DEPTH_TEST);

  glLoadIdentity ();

  glTranslatef (0, 0, -3);
  
  glDisable (GL_LIGHTING);


  glPushMatrix ();
  glTranslatef (origin[0], origin[1], origin[2]);    // Move box down X axis.
  //glRotatef( 45,0, 0, 1 );
  glScalef (0.2, 0.2, 0.2);
  //glutSolidSphere(0.2,30,30);
  //Draw_Box ();
  obstacles(arr1,10);
  glPopMatrix ();
  move();

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
  glutIdleFunc(redraw);
  glutKeyboardFunc (  Keyboard  );

  glClearColor (0.1, 0.0, 0.1, 1.0);

  glMatrixMode   (GL_PROJECTION);
  gluPerspective (60, 1.5, 1, 10);
  glMatrixMode   (GL_MODELVIEW);
  glutReshapeFunc(reshaped);
  glutMainLoop   ();

  return 1;
}
//------------------------------------------------------------------------------
