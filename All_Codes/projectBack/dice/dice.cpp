#include <stdio.h>

#include <float.h>
#include <math.h>
#include <iostream>
#include <GL/glut.h>

using namespace std;
int angleX, angleY, angleZ=0;  
float spin;

static GLuint texture[6];      
GLuint LoadTextureRAW( const char * filename)
{
    GLuint texture;
  

 
    unsigned char* data;
    FILE * file;
  
    // open texture data
    file = fopen( filename, "rb" );
    if ( file == NULL ) return 0;
  
    // allocate buffer
  float width = 512;
  float height = 512;
    data = (unsigned char*)malloc( width * height * 3 );
  
    // read texture data
    fread( data, width * height * 3, 1, file );
    fclose( file );
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  
  glGenTextures(1, &texture);
  glBindTexture( GL_TEXTURE_2D, texture);
  
    // select modulate to mix texture with color for shading
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST );
  glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,GL_RGB , GL_UNSIGNED_BYTE, data);    // build our texture mipmaps
  
    // allocate a texture name
  
    // free buffer
    free( data );  
return texture;
}

void thiswillDrawCube(){
glEnable(GL_TEXTURE_2D);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
  float x0 = -1.0, y0 = -1, x1 = 1, y1 = 1, z0 = 1;
  float face[6][4][3] =  { {{x0, y0, z0}, {x1, y0, z0}, {x1, y1, z0}, {x0, y1, z0}},  //front
    {{x0, y1, -z0}, {x1, y1, -z0}, {x1, y0, -z0}, {x0, y0, -z0}},    //back
    {{x1, y0, z0}, {x1, y0, -z0}, {x1, y1, -z0}, {x1, y1, z0}},    //right
    {{x0, y0, z0}, {x0, y1, z0}, {x0, y1, -z0}, {x0, y0, -z0}},    //left
    {{x0, y1, z0}, {x1, y1, z0}, {x1, y1, -z0}, {x0, y1, -z0}},    //top
    {{x0, y0, z0}, {x0, y0, -z0}, {x1, y0, -z0}, {x1, y0, z0}}    //bottom
  };
  glEnable( GL_CULL_FACE );
  glCullFace ( GL_BACK );
  
  //glPushMatrix();
  glRotatef(35, 1.0, 0.0, 0.0);
  glRotatef(spin, 1.0, 1.0, 0.0);
  glRotatef( angleX, 1.0, 0.0, 0.0);      //rotate the cube along x-axis
  glRotatef( angleY, 0.0, 1.0, 0.0);      //rotate along y-axis  
  glRotatef( angleZ, 0.0, 0.0, 1.0);
  
  //rotate along z-axis
  glScalef(0.5, 0.5, 0.5);
  for ( int i = 0; i < 6; ++i ) {      //draw cube with texture images
    glBindTexture(GL_TEXTURE_2D, texture[i]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3fv ( face[i][0] );   
    glTexCoord2f(1.0, 0.0); glVertex3fv ( face[i][1] );  
    glTexCoord2f(1.0, 1.0); glVertex3fv ( face[i][2] );
    glTexCoord2f(0.0, 1.0); glVertex3fv ( face[i][3] );
    glEnd();
  }
  glFlush();
  //glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  glPushMatrix();
  thiswillDrawCube();
  glPopMatrix();
  glutSwapBuffers();
}
void spindDisplay(){
  spin = spin + 5;
  if (spin > 360)
  spin = spin -360;
  glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y)
{
  switch(key) {
    case 'x':
      angleX = ( angleX + 10 ) % 360;
      break;
    case 'X':
      angleX = ( angleX - 10 ) % 360;
      break;
    case 'y':
      angleY = ( angleY + 10 ) % 360;
      break;
    case 'Y':
      angleY = ( angleY - 10 ) % 360;
      break;
    case 'z':
      angleZ = ( angleZ + 10 ) % 360;
      break;
    case 'Z':
      angleZ = ( angleZ - 10 ) % 360;
      break;
    case 'r':
      spindDisplay();
      glutPostRedisplay();
    
      }
  glutPostRedisplay();
}


void init(void)                          
{
  glClearColor(.0, .0, 0.5, .6);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  texture[0] = LoadTextureRAW ("1.png");
  
  texture[1] = LoadTextureRAW ("1.png");
  
  texture[2] = LoadTextureRAW ("1.png");
  
  texture[3] = LoadTextureRAW ("1.png");

  texture[4] = LoadTextureRAW ("1.png");
  texture[5] = LoadTextureRAW ("1.png");
}
void mouse (int button, int state, int x, int y)            //mouse function...
{
  switch(button) {
    case GLUT_LEFT_BUTTON:
      if(state == GLUT_DOWN)
       glutIdleFunc(spindDisplay);
        
      break;
    case GLUT_RIGHT_BUTTON:
      if(state == GLUT_DOWN)
      {
    glutIdleFunc(NULL);
      }
      
      break;
    default:
      break;
  }
}


void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt ( 0, 0, 5.0,
         0, 0, 0,
         0, 50, 0 );
}
int main (int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1200, 600);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("3D CUBE");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}
