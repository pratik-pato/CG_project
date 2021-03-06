
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

GLfloat  xAngle = 45, yAngle = 0.0, zAngle = 0.0;


//------------------------------------------------------------------------

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
  glScalef (0.2, 0.2, 0.2);
  Draw_Box ();
  glPopMatrix ();

  glPushMatrix ();
  glTranslatef (d[0], d[1], (d[2]-2.0f));    // Move box down X axis.
  glScalef (0.2, 0.2, 0.2);
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
  //glutKeyboardFunc (  Keyboard  );

  glClearColor (0.1, 0.0, 0.1, 1.0);

  glMatrixMode   (GL_PROJECTION);
  gluPerspective (60, 1.5, 1, 10);
  glMatrixMode   (GL_MODELVIEW);
  glutMainLoop   ();

  return 1;
}
//------------------------------------------------------------------------------
