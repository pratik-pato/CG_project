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
  glTranslatef(0.0f,1.8f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.5f,0.2f,0.0f);
  glVertex3f(-0.3f,0.5f,0.0f);
  glVertex3f(0.5f,0.1f,0.0f);
  glVertex3f(0.8f,-0.5f,0.0f);
  glVertex3f(-0.7f,-0.5f,0.0f);
  glEnd();


  
  glLoadIdentity();
  glTranslatef(0.0f,-0.6f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.4f,2.0f,0.0f);
  glVertex3f(0.6f,2.0f,0.0f);
  glVertex3f(1.0f,-0.2f,0.0f);
  glVertex3f(0.2f,-0.8f,0.0f);
  glVertex3f(-0.6f,-0.8f,0.0f);
  glVertex3f(-1.2f,-0.25f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(0.0f,0.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.2f,0.5f,0.0f);
  glVertex3f(0.2f,0.5f,0.0f);
  glVertex3f(0.1f,-0.3f,0.0f);
  glVertex3f(-0.1f,-0.2f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(-0.9f,1.15f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.35f,0.5f,0.0f);
  glVertex3f(0.4f,0.6f,0.0f);
  glVertex3f(0.3f,0.4f,0.0f);
  glVertex3f(-0.35f,0.4f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(-0.9f,1.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.3f,0.5f,0.0f);
  glVertex3f(0.3f,0.5f,0.0f);
  glVertex3f(0.3f,0.4f,0.0f);
  glVertex3f(-0.25f,0.4f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(0.0f,0.35f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.1,sin(2*3.14159*i/1000.0)*0.1,0);
    }
  glEnd();

  
  glLoadIdentity();
  glTranslatef(-0.2f,2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.1,sin(2*3.14159*i/1000.0)*0.1,0);
    }
  glEnd();

  glLoadIdentity();
  glTranslatef(-0.2f,2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f);
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.01,sin(2*3.14159*i/1000.0)*0.01,0);
    }
  glEnd();

  
  glLoadIdentity();
  glTranslatef(-0.2f,2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*0.07,sin(2*3.14159*i/1000.0)*0.07,0);
    }
  glEnd();


    glLoadIdentity();
  glTranslatef(0.25f,-1.2f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f);
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*.07,sin(2*3.14159*i/1000.0)*0.07,0);
    }
  glEnd();

   
  glLoadIdentity();
  glTranslatef(-0.65f,-1.18f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glBegin(GL_POINTS);
  for(int i=0;i<1000;++i)
    {
      glVertex3f(cos(2*3.14159*i/1000.0)*.07,sin(2*3.14159*i/1000.0)*0.07,0);
    }
  glEnd();
  
  glLoadIdentity();
  glTranslatef(0.2f,-1.6f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f); 
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.1f,0.5f,0.0f);
  glVertex3f(0.2f,0.6f,0.0f);
  glVertex3f(0.1f,-0.3f,0.0f);
  glVertex3f(-0.1f,-0.2f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(-0.7f,-1.6f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(-0.07f,0.7f,0.0f);
  glVertex3f(0.2f,0.6f,0.0f);
  glVertex3f(0.1f,-0.3f,0.0f);
  glVertex3f(-0.1f,-0.2f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(0.2f,-2.5f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(0.16f,0.87f,0.0f);
  glVertex3f(0.1f,0.6f,0.0f);
  glVertex3f(-0.5f,0.3f,0.0f);
  glVertex3f(-0.6f,0.6f,0.0f);
  glEnd();

  glLoadIdentity();
  glTranslatef(-0.7f,-2.5f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex3f(0.16f,0.87f,0.0f);
  glVertex3f(0.1f,0.6f,0.0f);
  glVertex3f(-0.5f,0.3f,0.0f);
  glVertex3f(-0.6f,0.6f,0.0f);
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
