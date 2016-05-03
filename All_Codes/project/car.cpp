#include <stdlib.h> //Needed for "exit" function

//Include OpenGL header files, so that we can use OpenGL


#include <GL/glut.h>


#include<stdio.h>
void drawcar();

void keyspecial( int key, int x, int y );

GLfloat vertices[][3] = {{-0.7f, -1.0f, -5.0f},{0.7f, -1.0f, -5.0f},{0.7f, 1.0f, -5.0f},{-0.7f, 1.0f, -5.0f},{-1.2f, 2.0f, -7.0f},
			 {1.2f, 2.0f, -7.0f},{1.2f, -1.7f, -7.0f},{-1.2f, -1.7f, -7.0f},
			 {1.2f,0.0f,-7.0f},{0.7,0.0f,-5.0f},{-1.2f,0.0f,-7.0f},{-0.7,0.0f,-5.0},{-1.0f, 4.0f, -7.0f},
			 {-0.8f, 5.0f, -7.0f},{1.0f, 4.0f, -7.0f},{0.8f, 5.0f, -7.0f},{-1.0f, -2.1f, -7.0f},{1.0f, -2.1f, -7.0f},
			 {1.0f, -2.3f, -9.0f},{-1.0f, -2.3f, -9.0f},{-1.2f, -1.9f, -9.0f},{1.2f, -1.9f, -9.0f},{1.4f, 2.0f, -9.0f},{-1.4f, 2.0f, -9.0f},
			 {-1.2f, 4.0f, -9.0f},{1.2f, 4.0f, -9.0f},{-0.8f, 5.0f, -9.0f},{0.8f, 5.0f, -9.0f},{0.0f,0.0f,0.0f}};




//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
		    int x, int y) { //The current mouse coordinates
  switch (key) {
  case 27: //Escape key
    exit(0); //Exit the program
  }
}




void init()
{
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); //Reset the drawing perspective
  glOrtho(-25,25,-25,25,-25,25);
  glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
}
//Initializes 3D rendering
void initRendering() {

  //Makes 3D drawing work when something is in front of something else
  glEnable(GL_DEPTH_TEST);
}

//just a example part of background which is supposed to be stationary

void back() {

  glPushMatrix();
  glTranslatef(5,2,0);
  glBegin(GL_LINE_LOOP);
  glPointSize(5.0);
  glColor3d(1,0,1);
  glVertex3f(8,4,0);
  glVertex3f(2,4,0);
  glVertex3f(2,0,0);
  glVertex3f(8,0,0);
  glEnd();

  glutSwapBuffers();
  glFlush();
  glPopMatrix();
}



//Draws the 3D scene
void drawScene() {


  //Clear information from last draw
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  back();


  drawcar();

}


//just a color function
void colorcar( float x,float y,float z)
{glColor3d(x,y,z);
}


//car function
void drawcar()
{

  glTranslatef(0,0,0);

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
//below functions are used by the special key function
void translator()
{
  float x=vertices[28][0],y=vertices[28][1];

  glTranslatef(x,y+.4,0.0);
}

void tran()
{
  float x=vertices[28][0],y=vertices[28][1];

  glTranslatef(-x,-y+.4,0.0);
}

void translatorb()
{
  float x=vertices[28][0],y=vertices[28][1];

  glTranslatef(x,y-.4,0.0);
}

void tranb()
{
  float x=vertices[28][0],y=vertices[28][1];

  glTranslatef(-x,-y-.4,0.0);
}




void rotaterl()
{


  glRotatef(10,0,0,1);



}



void rotaterr()
{

  glRotatef(-10,0,0,1);


}


//keyboard interaction to move the car
void keyspecial( GLint key, GLint x, GLint y )
{
  if( key == GLUT_KEY_UP) // up
    {

      for(int i=0;i<29;i++)
	vertices[i][1]+=.50;

    }
  if( key == GLUT_KEY_DOWN) // down
    {
      for(int i=0;i<29;i++)
	vertices[i][1]-=.5;
    }


  //car turns left forward
  if(key ==GLUT_KEY_LEFT)
    {


      translator() ;
      rotaterl();
      tran();


    }
  //car turns right forward
  if(key ==GLUT_KEY_RIGHT)
    {
      translator() ;
      rotaterr();
      tran();

    }

  //car turns right backwards

  if(key == GLUT_KEY_F2 )
    {
      translatorb() ;
      rotaterl();
      tranb();



    }

  //car turns right backwards
  if(key == GLUT_KEY_F1 )
    {
      translatorb() ;
      rotaterr();
      tranb();


    }

  glutPostRedisplay(); // redraw everything to reflect the changes



}





int main(int argc, char** argv)
{



  //Initialize GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(1400, 800); //Set the window size
  glutInitWindowPosition(0,0);

  //Create the window
  glutCreateWindow("car");




  //Set handler functions for drawing, keypresses, and window resizes
  glutDisplayFunc(drawScene);




  glutKeyboardFunc(handleKeypress);
  glutSpecialFunc(keyspecial);
  init();
  initRendering(); //Initialize rendering
  glutMainLoop(); //Start the main loop. glutMainLoop doesn't return.
  return 0; //This line is never reached
} 
