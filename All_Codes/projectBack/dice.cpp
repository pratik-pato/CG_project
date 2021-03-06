#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<unistd.h>
#include<math.h>
#define ESCAPE 27
int window;
float rcube = 0.0f;
void InitGL(int Width, int Height)
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);// Reset The Current Viewport And Perspective Transformation
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
  float i;
  int triangleAmount = 1000;
  GLfloat twicePi = 2.0f * 3.142;
  
  glEnable(GL_LINE_SMOOTH);
  glLineWidth(5.0);
  
  glBegin(GL_LINES);
  glColor3f(1.0, 0.0, 0.0);
  for(i = 0; i <= triangleAmount; i+=0.01)
    {
      glVertex3f( x, y , 0);
      glVertex3f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)),0);
    }
  
  glEnd();
  
}



/* The main drawing function. */
void DrawGLScene()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);// Clear The Screen And The Depth Buffer

  glLoadIdentity();// Reset the transformation matrix.
  glTranslatef(0.0f,0.0f,-7.0f);// Move Right 3 Units, and back into the screen 7

  glRotatef(rcube,1.0f,1.0f,1.0f);// Rotate The Cube On X, Y, and Z

  // draw a cube (6 quadrilaterals)
  glBegin(GL_QUADS);// start drawing the cube.

  // top of cube
  drawCircle(-1.0f, 1.0f, 0.3f);
  glLoadIdentity();
  glColor3f(1.0f,1.0f,1.0f);// Set The Color To Blue
  glVertex3f( 1.0f, 1.0f,-1.0f);// Top Right Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f,-1.0f);// Top Left Of The Quad (Top)
  glVertex3f(-1.0f, 1.0f, 1.0f);// Bottom Left Of The Quad (Top)
  glVertex3f( 1.0f, 1.0f, 1.0f);// Bottom Right Of The Quad (Top)

  // bottom of cube
  glColor3f(1.0f,1.0f,1.0f);// Set The Color To Orange
  glVertex3f( 1.0f,-1.0f, 1.0f);// Top Right Of The Quad (Bottom)
  glVertex3f(-1.0f,-1.0f, 1.0f);// Top Left Of The Quad (Bottom)
  glVertex3f(-1.0f,-1.0f,-1.0f);// Bottom Left Of The Quad (Bottom)
  glVertex3f( 1.0f,-1.0f,-1.0f);// Bottom Right Of The Quad (Bottom)

  // front of cube
  //drawCircle(-1.0f, 1.0f, 0.3f);
  glColor3f(1.0f,1.0f,1.0f);// Set The Color To Red
  glVertex3f( 1.0f, 1.0f, 1.0f);// Top Right Of The Quad (Front)
  glVertex3f(-1.0f, 1.0f, 1.0f);// Top Left Of The Quad (Front)
  glVertex3f(-1.0f,-1.0f, 1.0f);// Bottom Left Of The Quad (Front)
  glVertex3f( 1.0f,-1.0f, 1.0f);// Bottom Right Of The Quad (Front)

  // back of cube.
  //drawCircle(-1.0f, 1.0f, 0.3f);
  glColor3f(1.0f,1.0f,1.0f);// Set The Color To Yellow
  glVertex3f( 1.0f,-1.0f,-1.0f);// Top Right Of The Quad (Back)
  glVertex3f(-1.0f,-1.0f,-1.0f);// Top Left Of The Quad (Back)
  glVertex3f(-1.0f, 1.0f,-1.0f);// Bottom Left Of The Quad (Back)
  glVertex3f( 1.0f, 1.0f,-1.0f);// Bottom Right Of The Quad (Back)

  // left of cube
  
  //glClearColor(0,0,0,0);
  glColor3f(1.0f,1.0f,1.0f);// Blue
  glVertex3f(-1.0f, 1.0f, 1.0f);// Top Right Of The Quad (Left)
  glVertex3f(-1.0f, 1.0f,-1.0f);// Top Left Of The Quad (Left)
  glVertex3f(-1.0f,-1.0f,-1.0f);// Bottom Left Of The Quad (Left)
  glVertex3f(-1.0f,-1.0f, 1.0f);// Bottom Right Of The Quad (Left)

  // Right of cube
  glColor3f(1.0f,1.0f,1.0f);// Set The Color To Violet
  glVertex3f( 1.0f, 1.0f,-1.0f);        // Top Right Of The Quad (Right)
  glVertex3f( 1.0f, 1.0f, 1.0f);// Top Left Of The Quad (Right)
  glVertex3f( 1.0f,-1.0f, 1.0f);// Bottom Left Of The Quad (Right)
  glVertex3f( 1.0f,-1.0f,-1.0f);// Bottom Right Of The Quad (Right)
  glEnd();// Done Drawing The Cube

  rcube-=1.0f;// Decrease The Rotation Variable For The Cube

  // swap the buffers to display, since double buffering is used.
  glutSwapBuffers();
}

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y)
{
  /* avoid thrashing this call */
  usleep(100);

  /* If escape is pressed, kill everything. */
  if (key == ESCAPE)
    {
      /* shut down our window */
      glutDestroyWindow(window);

      /* exit the program...normal termination. */
      exit(0);
    }
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  window = glutCreateWindow("DICE_14105");
  glutDisplayFunc(DrawGLScene);
  glutFullScreen();
  glutIdleFunc(DrawGLScene);
  glutReshapeFunc(ReSizeGLScene);
  glutKeyboardFunc(keyPressed);
  InitGL(640, 480);
  glutMainLoop();

  return 1;
}
