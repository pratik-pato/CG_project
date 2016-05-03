import pygame
from pygame.locals import *

from math import*
from OpenGL.GL import *
from OpenGL.GLU import *

verticies = (
(0,0.7,0),
(0.1,0.1,0),
(0.55,-0.45,0),
(0,-0.1,0),
(-0.55,-0.45,0),
(-0.1,0.1,0),
(0.0,0.0,0.13),
(0.0,0.0,-0.13),
)

edges = (
(0,1),
(1,2),
(2,3), 
(3,4),
(4,5),
(5,0),


(6,1),
(6,2),
(6,3),
(6,4),
(6,5),
(6,0),

(7,0),(7,1),(7,2),(7,3),(7,4),(7,5)
    )

def circle():
 glBegin(GL_POINTS);
 for i in range(1000):
     glVertex3f(cos(2*3.14159*i/1000.0)*0.7,sin(2*3.14159*i/1000.0)*0.7,0)
 glEnd()



def logo():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()


def main():
    pygame.init()
    display = (800,800)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)
    glColor(0,1,0)
    glTranslatef(0.0,0.0,-5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        glRotate(1,0,1,0)
        logo()
	glRotate(1,1,0,0)
	circle()
        pygame.display.flip()

    

main()
