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
  glTranslatef(0.0f,-2.0f,-6.0f);
  glColor3f(0.0f,0.0f,0.0f);
  glBegin(GL_POINTS);
  for(int i=0;i<30000;++i)
    {
      glVertex3f(i,(),0);
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
