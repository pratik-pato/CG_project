import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

vertices = (
    (0, 2.3, 0), #0
    (1.4, 1, 0), #1
    (1.2, -1.2, 0), #2
    (-1.2, -1.2, 0), #3
    (-1.4, 1, 0), #4
    (0.4,1.2,0), #5
    (0.5,0.2,0), #6
    (0,-0.4,0), #7 
    (-0.5,0.2,0), #8 
    (-0.4,1.2,0), #9
    (0.0,0.5,0.3), #10
    (0.0,0.5,-0.3) 
    )

edges = (

    (0,5),
    (5,1),
    (1,6),
    (6,2),
    (2,7),
    (7,3),
    (3,8),
    (8,4),
    (4,9),
    (9,0),

    (10,1),
    (10,2),
    (10,3),
    (10,4),
    (10,5),
    (10,6),
    (10,7),
    (10,8),
    (10,9),
    (10,0),

    (11,1),
    (11,2),
    (11,3),
    (11,4),
    (11,5),
    (11,6),
    (11,7),
    (11,8),
    (11,9),
    (11,0) 
)

def Star():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(vertices[vertex])
    glEnd()
    #glColor3f(218,165,32)

def main():
    pygame.init()
    display = (850,650)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)
    gluPerspective(60, (display[0]/display[1]), 0.1, 50.0)
    glTranslatef(0.0,0.0,-5)
    
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        Star()
        pygame.display.flip()
        
        '''glRotatef(1, 3, 1, 0)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        Star()
        pygame.display.flip()
        pygame.time.wait(10)'''
main()
