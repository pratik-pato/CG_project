/*
 * OGL01Shape3D.cpp: 3D Shapes
 */

#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
/* Global variables */
char title[] = "3D Shapes";

/* Initialize OpenGL Graphics */
void initGL() {
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
  glClearDepth(1.0f);                   // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
  glShadeModel(GL_SMOOTH);   // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
  glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

  glLoadIdentity();//load identity matrix
  glTranslatef(0.0f,1.8f,-6.0f);//move forward 4 units
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of head
  glVertex3f(-0.5f,0.2f,0.0f);//first vertex
  glVertex3f(-0.3f,0.5f,0.0f);//second vertex
  glVertex3f(0.5f,0.1f,0.0f);//third vertex
  glVertex3f(0.8f,-0.5f,0.0f);//fourth vertex
  glVertex3f(-0.7f,-0.5f,0.0f);//fifth vertex
  glEnd();//end drawing of head


  
  glLoadIdentity();//load identity matrix
  glTranslatef(0.0f,-0.6f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //black
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of body
  glVertex3f(-0.4f,2.0f,0.0f);//first vertex
  glVertex3f(0.6f,2.0f,0.0f);//second vertex
  glVertex3f(1.0f,-0.2f,0.0f);//third vertex
  glVertex3f(0.2f,-0.8f,0.0f);//fourth vertex
  glVertex3f(-0.6f,-0.8f,0.0f);//fifth vertex
  glVertex3f(-1.2f,-0.25f,0.0f);//sixth vertex
  glEnd();//end drawing of body


  glLoadIdentity();//load identity matrix
  glTranslatef(0.0f,0.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of hand
  glVertex3f(-0.2f,0.5f,0.0f);//first vertex
  glVertex3f(0.2f,0.5f,0.0f);//second vertex
  glVertex3f(0.1f,-0.3f,0.0f);//third vertex
  glVertex3f(-0.1f,-0.2f,0.0f);//fourth vertex
  glEnd();//end drawing of hand

  glLoadIdentity();//load identity matrix
  glTranslatef(-0.9f,1.15f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of choch2
  glVertex3f(-0.35f,0.5f,0.0f);//first vertex
  glVertex3f(0.4f,0.6f,0.0f);//second vertex
  glVertex3f(0.3f,0.4f,0.0f);//third vertex
  glVertex3f(-0.35f,0.4f,0.0f);//fourth vertex
  glEnd();//end drawing of choch2

  glLoadIdentity();//load identity matrix
  glTranslatef(-0.9f,1.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of choch2
  glVertex3f(-0.3f,0.5f,0.0f);//first vertex
  glVertex3f(0.3f,0.5f,0.0f);//second vertex
  glVertex3f(0.3f,0.4f,0.0f);//third vertex
  glVertex3f(-0.25f,0.4f,0.0f);//fourth vertex
  glEnd();//end drawing of choch2


  //dot on hand
  glLoadIdentity();//load identity matrix
  glTranslatef(0.0f,0.35f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.1,sin(2*3.14159*i/1000.0)*0.1,0);
    }
  glEnd();

  //eye out
  glLoadIdentity();//load identity matrix
  glTranslatef(-0.2f,2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.1,sin(2*3.14159*i/1000.0)*0.1,0);
    }
  glEnd();

  //dot on eye
  glLoadIdentity();//load identity matrix
  glTranslatef(-0.2f,2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.01,sin(2*3.14159*i/1000.0)*0.01,0);
    }
  glEnd();

  //eye in
  glLoadIdentity();//load identity matrix
  glTranslatef(-0.2f,2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.07,sin(2*3.14159*i/1000.0)*0.07,0);
    }
  glEnd();


  //leg 1 circle
  glLoadIdentity();//load identity matrix
  glTranslatef(0.25f,-1.2f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*.07,sin(2*3.14159*i/1000.0)*0.07,0);
    }
  glEnd();

   //leg 2 circle
  glLoadIdentity();//load identity matrix
  glTranslatef(-0.65f,-1.18f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*.07,sin(2*3.14159*i/1000.0)*0.07,0);
    }
  glEnd();
  
  glLoadIdentity();//load identity matrix
  glTranslatef(0.2f,-1.6f,-6.0f);//move forward 4 units
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of leg1
  glVertex3f(-0.1f,0.5f,0.0f);//first vertex
  glVertex3f(0.2f,0.6f,0.0f);//second vertex
  glVertex3f(0.1f,-0.3f,0.0f);//third vertex
  glVertex3f(-0.1f,-0.2f,0.0f);//fourth vertex
  glEnd();//end drawing of leg1

  glLoadIdentity();//load identity matrix
  glTranslatef(-0.7f,-1.6f,-6.0f);//move forward 4 units
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of leg2
  glVertex3f(-0.07f,0.7f,0.0f);//first vertex
  glVertex3f(0.2f,0.6f,0.0f);//second vertex
  glVertex3f(0.1f,-0.3f,0.0f);//third vertex
  glVertex3f(-0.1f,-0.2f,0.0f);//fourth vertex
  glEnd();//end drawing of leg2

  glLoadIdentity();//load identity matrix
  glTranslatef(0.2f,-2.5f,-6.0f);//move forward 4 units
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of leg1.1
  glVertex3f(0.16f,0.87f,0.0f);//first vertex
  glVertex3f(0.1f,0.6f,0.0f);//second vertex
  glVertex3f(-0.5f,0.3f,0.0f);//third vertex
  glVertex3f(-0.6f,0.6f,0.0f);//fourth vertex
  glEnd();//end drawing of leg1.1

  glLoadIdentity();//load identity matrix
  glTranslatef(-0.7f,-2.5f,-6.0f);//move forward 4 units
  glColor3f(0.0f,0.0f,0.0f); //blue color
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);//begin drawing of leg1.1
  glVertex3f(0.16f,0.87f,0.0f);//first vertex
  glVertex3f(0.1f,0.6f,0.0f);//second vertex
  glVertex3f(-0.5f,0.3f,0.0f);//third vertex
  glVertex3f(-0.6f,0.6f,0.0f);//fourth vertex
  glEnd();//end drawing of leg1.1

  
  
  
  glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
  // Compute aspect ratio of the new window
  if (height == 0) height = 1;                // To prevent divide by 0
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  // Set the viewport to cover the new window
  glViewport(0, 0, width, height);

  // Set the aspect ratio of the clipping volume to match the viewport
  glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
  glLoadIdentity();             // Reset
  // Enable perspective projection with fovy, aspect, zNear and zFar
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
  glutInit(&argc, argv);            // Initialize GLUT
  glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
  glutInitWindowSize(640, 480);   // Set the window's initial width & height
  glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
  glutCreateWindow(title);          // Create window with the given title
  glutDisplayFunc(display);       // Register callback handler for window re-paint event
  glutReshapeFunc(reshape);       // Register callback handler for window re-size event
  initGL();                       // Our own OpenGL initialization
  glutMainLoop();                 // Enter the infinite event-processing loop
  return 0;
}
