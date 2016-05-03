#include <GL/glut.h> 
#include <math.h>
char title[] = "3D Shapes";

void initGL() {
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClearDepth(1.0f);                  
  glEnable(GL_DEPTH_TEST);  
  glDepthFunc(GL_LEQUAL);
  glShadeModel(GL_SMOOTH);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  
  glLoadIdentity();
  glTranslatef(0.0f,-0.6f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-1.0f,2.0f,0.0f);
  glVertex3f(0.6f,2.0f,0.0f);
  glVertex3f(-1.0f,-0.7f,0.0f);
  glVertex3f(0.6f,-0.7f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(-1.0f,1.4f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_LINES);
  glVertex3f(0,0,0.0);
  glVertex3f(-1,-1,0.0);
  glEnd();

  glLoadIdentity();
  glTranslatef(0.6f,1.4f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_LINES);
  glVertex3f(0,0,0.0);
  glVertex3f(1,-1,0.0);
  glEnd();

  glLoadIdentity();
  glTranslatef(-0.8f,-1.3f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_LINES);
  glVertex3f(0,0,0.0);
  glVertex3f(0,-1,0.0);
  glEnd();

  glLoadIdentity();
  glTranslatef(0.4f,-1.3f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f); 
  glBegin(GL_LINES);
  glVertex3f(0,0,0.0);
  glVertex3f(0,-1,0.0);
  glEnd();
	

  glLoadIdentity();
  glTranslatef(-0.18f,1.7f,-6.0f);
  glColor3f(1.0f,0.0f,0.0f);
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.3,sin(2*3.14159*i/1000.0)*0.3,0);
    }
  glEnd();
  
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
  glutCreateWindow(title);        
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  initGL();      
  glutMainLoop();
  return 0;
}
