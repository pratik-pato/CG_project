#include <GL/glut.h>  
#include <math.h>
char title[] = "3D Shapes";
const float DEG2RAD = 3.14159/180;
void initGL() {
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClearDepth(1.0f);                  
  glEnable(GL_DEPTH_TEST);  
  glDepthFunc(GL_LEQUAL);   
  glShadeModel(GL_SMOOTH);  
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
  int i;
  int triangleAmount = 4; //# of triangles used to draw circle

  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * 3.14;

  glBegin(GL_TRIANGLE_FAN);
  //glVertex2f(x, y); // center of circle
  for(i = 0; i <= triangleAmount;i++) {
    glVertex2f(
	       x + (radius * cos(i *  twicePi / triangleAmount)),
	       y + (radius * sin(i * twicePi / triangleAmount))
	       );
  }
  glEnd();
}



void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  glPushMatrix ();
  glColor3f(1.0, 0.0, 0.0);
  glTranslatef (0, 0, 0);    // Move box down X axis.
  //glScalef (0.2, 0.2, 0.2);
  glRotated(45, 0, 0,1);
  drawFilledCircle (0,0,0.5);
  glPopMatrix ();
  

  // glColor3f(1.0, 0.0, 0.0);
  // glBegin(GL_LINE_LOOP);

  // for (int i=0; i<1000 ; i++)
  //   {
  //     float degInRad = i*DEG2RAD;
  //     glVertex2f(cos(degInRad)*5,sin(degInRad)*5);
  //   }

  // glEnd();
  
  
  // Gllinewidth(2.5);
  // glColor3f(1.0, 0.0, 0.0);
  // glBegin(GL_LINES);
  // glVertex3f(0.0, 0.0, 0.0);
  // glVertex3f(15, 0, 0);
  // glEnd();
  
  glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {  
  if (height == 0) height = 1;  
  GLfloat aspect = (GLfloat)width / (GLfloat)height;

  glViewport(0, 0, width, height);


  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();           
  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(640, 480); 
  glutInitWindowPosition(50, 50);
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glutCreateWindow(title);       
  glutDisplayFunc(display);      
  //glutReshapeFunc(reshape);      
  //initGL();
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glutMainLoop();
  return 0;
}
