#include<GL/glut.h>
GLfloat xRotated, yRotated, zRotated;
void init(void)
{
  glClearColor(0,0,0,0);

}

void DrawCube(void)
{

  glMatrixMode(GL_MODELVIEW);
  // clear the drawing buffer.
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  
  glTranslatef(0.0,3.5,-15.5);
  glRotatef(10.0, 1.0, 0.0, 0.0);
  glBegin(GL_QUADS);        // Draw The Cube Using quads
  
  glVertex3f( 5.0f, -4.8f,-5.0f);    // Top Right Of The Quad (Top)
  glVertex3f(-5.0f, -4.8f,-5.0f);    // Top Left Of The Quad (Top)
  glVertex3f(-5.0f, -4.8f, 5.0f);    // Bottom Left Of The Quad (Top)
  glVertex3f( 5.0f, -4.8f, 5.0f);    // Bottom Right Of The Quad (Top)
  
  glVertex3f( 5.0f,-5.0f, 5.0f);    // Top Right Of The Quad (Bottom)
  glVertex3f(-5.0f,-5.0f, 5.0f);    // Top Left Of The Quad (Bottom)
  glVertex3f(-5.0f,-5.0f,-5.0f);    // Bottom Left Of The Quad (Bottom)
  glVertex3f( 5.0f,-5.0f,-5.0f);    // Bottom Right Of The Quad (Bottom)

  glColor3f(1.0f,0.5f,0.0f);
  glVertex3f( 5.0f, -4.8f, 5.0f);    // Top Right Of The Quad (Front)
  glVertex3f(-5.0f, -4.8f, 5.0f);    // Top Left Of The Quad (Front)
  glVertex3f(-5.0f,-5.0f, 5.0f);    // Bottom Left Of The Quad (Front)
  glVertex3f( 5.0f,-5.0f, 5.0f);    // Bottom Right Of The Quad (Front)

  
  glVertex3f( 5.0f,-5.0f,-5.0f);    // Top Right Of The Quad (Back)
  glVertex3f(-5.0f,-5.0f,-5.0f);    // Top Left Of The Quad (Back)
  glVertex3f(-5.0f, -4.8f,-5.0f);    // Bottom Left Of The Quad (Back)
  glVertex3f( 5.0f, -4.8f,-5.0f);    // Bottom Right Of The Quad (Back)
  
  glVertex3f(-5.0f, -4.8f, 5.0f);    // Top Right Of The Quad (Left)
  glVertex3f(-5.0f, -4.8f,-5.0f);    // Top Left Of The Quad (Left)
  glVertex3f(-5.0f,-5.0f,-5.0f);    // Bottom Left Of The Quad (Left)
  glVertex3f(-5.0f,-5.0f, 5.0f);    // Bottom Right Of The Quad (Left)
  
  glVertex3f( 5.0f, -4.8f,-5.0f);    // Top Right Of The Quad (Right)
  glVertex3f( 5.0f, -4.8f, 5.0f);    // Top Left Of The Quad (Right)
  glVertex3f( 5.0f,-5.0f, 5.0f);    // Bottom Left Of The Quad (Right)
  glVertex3f( 5.0f,-5.0f,-5.0f);    // Bottom Right Of The Quad (Right)
  glEnd();            // End Drawing The Cube
  glFlush();
}



void reshape(int x, int y)
{
  if (y == 0 || x == 0) return;  //Nothing is visible then, so return
  //Set a new projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  //Angle of view:40 degrees
  //Near clipping plane distance: 0.5
  //Far clipping plane distance: 20.0

  gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
  glMatrixMode(GL_MODELVIEW);
  glViewport(0,0,x,y);  //Use the whole window for rendering
}

int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(900,600);
  glutInitWindowPosition(300,300);
  glutCreateWindow(argv[0]);
  init();
  glutDisplayFunc(DrawCube);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}
