
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define  RADDEG  57.29577951f

float XUP[3] = {1,0,0}, XUN[3] = {-1, 0, 0},
  YUP[3] = {0,1,0}, YUN[3] = { 0,-1, 0},
  ZUP[3] = {0,0,1}, ZUN[3] = { 0, 0,-1},
  ORG[3] = {0,0,0};

int arr1[50] = {4, 3, 5, 1, 3, 2, 4, 4, 5, 1, 1, 1, 2, 5, 3, 2, 5, 5, 2, 3, 1, 1, 2, 5, 3, 2, 5, 5, 2, 3, 1, 1, 2, 5, 3, 2, 5, 5, 2, 3, 1, 1, 2, 5, 3, 2, 5, 5, 2, 3};

GLfloat origin[3] = {0,0,-20}; 

GLfloat viewangle = 0, tippangle = 0, traj[120][3];

GLfloat d[3] = {0, -1, 0};

GLfloat  xAngle = 45, yAngle = 0.0, zAngle = 0.0;

GLfloat vertices[][3] = {{-0.7f, -1.0f, -5.0f},{0.7f, -1.0f, -5.0f},{0.7f, 1.0f, -5.0f},{-0.7f, 1.0f, -5.0f},{-1.2f, 2.0f, -7.0f},
			 {1.2f, 2.0f, -7.0f},{1.2f, -1.7f, -7.0f},{-1.2f, -1.7f, -7.0f},
			 {1.2f,0.0f,-7.0f},{0.7,0.0f,-5.0f},{-1.2f,0.0f,-7.0f},{-0.7,0.0f,-5.0},{-1.0f, 4.0f, -7.0f},
			 {-0.8f, 5.0f, -7.0f},{1.0f, 4.0f, -7.0f},{0.8f, 5.0f, -7.0f},{-1.0f, -2.1f, -7.0f},{1.0f, -2.1f, -7.0f},
			 {1.0f, -2.3f, -9.0f},{-1.0f, -2.3f, -9.0f},{-1.2f, -1.9f, -9.0f},{1.2f, -1.9f, -9.0f},{1.4f, 2.0f, -9.0f},{-1.4f, 2.0f, -9.0f},
			 {-1.2f, 4.0f, -9.0f},{1.2f, 4.0f, -9.0f},{-0.8f, 5.0f, -9.0f},{0.8f, 5.0f, -9.0f},{0.0f,0.0f,0.0f}};



//------------------------------------------------------------------------
void reshaped(int w,int h){}

void colorcar( float x,float y,float z)
{glColor3d(x,y,z);
}

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
  
  // glBegin (GL_QUADS);

  // glColor3f  ( 0.0,  0.7, 0.1);     // Front - green
  // glVertex3f (-1.0,  1.0, 1.0);
  // glVertex3f ( 1.0,  1.0, 1.0);
  // glVertex3f ( 1.0, -1.0, 1.0);
  // glVertex3f (-1.0, -1.0, 1.0);

  // glColor3f  ( 0.9,  1.0,  0.0);    // Back  - yellow
  // glVertex3f (-1.0,  1.0, -1.0);
  // glVertex3f ( 1.0,  1.0, -1.0);
  // glVertex3f ( 1.0, -1.0, -1.0);
  // glVertex3f (-1.0, -1.0, -1.0);

  // glColor3f  ( 0.2, 0.2,  1.0);     // Top - blue
  // glVertex3f (-1.0, 1.0,  1.0);
  // glVertex3f ( 1.0, 1.0,  1.0);
  // glVertex3f ( 1.0, 1.0, -1.0);
  // glVertex3f (-1.0, 1.0, -1.0);

  // glColor3f  ( 0.7,  0.0,  0.1);    // Bottom - red
  // glVertex3f (-1.0, -1.0,  1.0);
  // glVertex3f ( 1.0, -1.0,  1.0);
  // glVertex3f ( 1.0, -1.0, -1.0);
  // glVertex3f (-1.0, -1.0, -1.0);

  // glEnd();
  // glTranslatef(0,0,0);
  
  glBegin(GL_POLYGON); //Begin roof
  colorcar(1.0,1.0,0.0);
  //back glass
  glVertex3fv(vertices[0]);
  glVertex3fv(vertices[1]);
  glVertex3fv(vertices[2]);
  glVertex3fv(vertices[3]);

  glEnd(); //End roof

  glBegin(GL_POLYGON); //Begin front wind sheild coordinates
  glColor3d(0.1, 0.5, 0.0);
  //Pentagon
  glVertex3fv(vertices[2]);
  glVertex3fv(vertices[3]);
  glVertex3fv(vertices[4]);
  glVertex3fv(vertices[5]);
  glEnd();


  glBegin(GL_POLYGON); //Begin back wind shield
  glColor3d(0.1, 0.5, 0.0);
  glVertex3fv(vertices[0]);
  glVertex3fv(vertices[1]);
  glVertex3fv(vertices[6]);
  glVertex3fv(vertices[7]);
  glEnd(); //End back wind shield



  glBegin(GL_POLYGON); //Begin front R window coordinates
  glColor3d(0.1, 0.5, 0.0);
  glVertex3fv(vertices[2]);
  glVertex3fv(vertices[5]);
  glVertex3fv(vertices[8]);
  glVertex3fv(vertices[9]);
  glEnd();

  glLineWidth(5.0f);// R window line
  glBegin(GL_LINES);
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[9]);
  glVertex3fv(vertices[8]);
  glEnd();


  glBegin(GL_POLYGON); //Begin back R window coordinates
  glColor3d(0.1, 0.5, 0.0);
  glVertex3fv(vertices[8]);
  glVertex3fv(vertices[9]);
  glVertex3fv(vertices[1]);
  glVertex3fv(vertices[6]);
  glEnd();

  glBegin(GL_POLYGON); //Begin back L window coordinates
  glColor3d(0.1, 0.5, 0.0);
  glVertex3fv(vertices[7]);
  glVertex3fv(vertices[0]);
  glVertex3fv(vertices[11]);
  glVertex3fv(vertices[10]);
  glEnd();

  glBegin(GL_POLYGON); //Begin front L window coordinates
  glColor3d(0.1, 0.5, 0.0);
  glVertex3fv(vertices[10]);
  glVertex3fv(vertices[11]);
  glVertex3fv(vertices[3]);
  glVertex3fv(vertices[4]);
  glEnd();

  glBegin(GL_POLYGON); //Begin front hood coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[4]);
  glVertex3fv(vertices[12]);
  glVertex3fv(vertices[13]);
  glVertex3fv(vertices[15]);
  glVertex3fv(vertices[14]);
  glVertex3fv(vertices[5]);
  glEnd();

  glBegin(GL_POLYGON); //Begin back hood coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[7]);
  glVertex3fv(vertices[16]);
  glVertex3fv(vertices[17]);
  glVertex3fv(vertices[6]);
  glEnd();

  glBegin(GL_POLYGON); //Begin back bumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[16]);
  glVertex3fv(vertices[17]);
  glVertex3fv(vertices[18]);
  glVertex3fv(vertices[19]);
  glEnd();

  glBegin(GL_POLYGON); //Begin back Lbumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[16]);
  glVertex3fv(vertices[19]);
  glVertex3fv(vertices[20]);
  glVertex3fv(vertices[7]);
  glEnd();

  glBegin(GL_POLYGON); //Begin back Rbumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[6]);
  glVertex3fv(vertices[21]);
  glVertex3fv(vertices[18]);
  glVertex3fv(vertices[17]);
  glEnd();

  glBegin(GL_POLYGON); //Begin Lside skirts coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[7]);
  glVertex3fv(vertices[20]);
  glVertex3fv(vertices[23]);
  glVertex3fv(vertices[4]);
  glEnd();

  glBegin(GL_POLYGON); //Begin Rside skirt coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[22]);
  glVertex3fv(vertices[5]);
  glVertex3fv(vertices[6]);
  glVertex3fv(vertices[21]);
  glEnd();

  glBegin(GL_POLYGON); //Begin Lfront bumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[23]);
  glVertex3fv(vertices[4]);
  glVertex3fv(vertices[12]);
  glVertex3fv(vertices[24]);
  glEnd();

  glBegin(GL_POLYGON); //Begin lF frnt bumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[24]);
  glVertex3fv(vertices[12]);
  glVertex3fv(vertices[13]);
  glVertex3fv(vertices[26]);
  glEnd();

  glBegin(GL_POLYGON); //Begin R frnt bumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[22]);
  glVertex3fv(vertices[5]);
  glVertex3fv(vertices[14]);
  glVertex3fv(vertices[25]);
  glEnd();

  glBegin(GL_POLYGON); //Begin rF frnt bumper coordinates
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[15]);
  glVertex3fv(vertices[27]);
  glVertex3fv(vertices[25]);
  glVertex3fv(vertices[14]);
  glEnd();


  glLineWidth(5.0f);// L window line
  glBegin(GL_LINES);
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[11]);
  glVertex3fv(vertices[10]);
  glEnd();

  glLineWidth(5.0f);//R front window line
  glBegin(GL_LINES);
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[2]);
  glVertex3fv(vertices[5]);
  glEnd();

  glLineWidth(5.0f);//L front window line
  glBegin(GL_LINES);
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[3]);
  glVertex3fv(vertices[4]);
  glEnd();

  glLineWidth(5.0f);//L back window line
  glBegin(GL_LINES);
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[0]);
  glVertex3fv(vertices[7]);
  glEnd();


  glLineWidth(5.0f);//R back window line
  glBegin(GL_LINES);
  colorcar(1.0,1.0,0.0);
  glVertex3fv(vertices[1]);
  glVertex3fv(vertices[6]);
  glEnd();

  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP); //Begin OUTLINE coordinates
  glColor3d(0.0, 0.0, 0.0);
  glVertex3fv(vertices[16]);
  glVertex3fv(vertices[17]);
  glVertex3fv(vertices[6]);
  glVertex3fv(vertices[8]);
  glVertex3fv(vertices[5]);
  glVertex3fv(vertices[14]);
  glVertex3fv(vertices[15]);
  glVertex3fv(vertices[13]);
  glVertex3fv(vertices[12]);
  glVertex3fv(vertices[4]);
  glVertex3fv(vertices[10]);
  glVertex3fv(vertices[7]);
  glVertex3fv(vertices[16]);
  glVertex3fv(vertices[17]);
  glEnd();


  glLineWidth(2.0f);
  glBegin(GL_LINE_LOOP); //Begin outer OUTLINE coordinates
  glColor3d(0.0, 0.0, 0.0);
  glVertex3fv(vertices[19]);
  glVertex3fv(vertices[18]);
  glVertex3fv(vertices[21]);
  glVertex3fv(vertices[22]);
  glVertex3fv(vertices[25]);
  glVertex3fv(vertices[27]);
  glVertex3fv(vertices[26]);
  glVertex3fv(vertices[24]);
  glVertex3fv(vertices[23]);
  glVertex3fv(vertices[20]);
  glVertex3fv(vertices[19]);
  glEnd();

  glutSwapBuffers();
  glFlush();

}

void loadcar(void)
{
  glPushMatrix ();
  //glTranslatef (origin[0], origin[1], origin[2]);    // Move box down X axis.
  //  
  glRotatef( 90,1, 0, 0 );
  glRotatef( 90,0, 1, 0 );
  glRotatef( -180,0, 0, 1 );
  //glScalef (0.2, 0.2, 0.2);
  //glutSolidSphere(0.2,30,30);
  Draw_Box ();
  //obstacles(arr1,10);
  glPopMatrix ();
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
	  
	  glTranslatef (-6.0f, -2, d[2]+9);
	  loadcar ();
	}
      if(arr[i]==2)
      	{
      	  i++;
      	  sz--;
      	  glTranslatef (-3.0f, d[1], d[2]+9);
	  loadcar ();
      	}
      if(arr[i]==3)
      	{
      	  i++;
      	  sz--;
      	  glTranslatef (0.0f, d[1], d[2]+9);
	  loadcar ();
      	}
      if(arr[i]==4)
      	{
      	  i++;
      	  sz--;
      	  glTranslatef (3.0f, d[1], d[2]+9);
	  loadcar ();
      	}
      if(arr[i]==5)
      	{
      	  i++;
      	  sz--;
      	  glTranslatef (6.0f, d[1], d[2]+9);
	  loadcar ();
      	}
  
    }

}
void move(void)
{
  origin[1]-=0.1;  
  origin[2]+=0.1;  
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
