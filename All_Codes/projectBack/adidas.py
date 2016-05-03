import pygame
from pygame.locals import *

from OpenGL.GL import *
from OpenGL.GLU import *

verticies = (
    (-0.7, 0, -1),
    (-0.3, 0, -1),
    (-0.6, 0.6, -2),
    (-0.8, 0.2, -1),
    (-0.1,0,-1),
    (0.3,0,-1),
    (-0.2,1.3,-2),
    (-0.45,0.8,-1),
    (0.5,0,-1),
    (0.9,0,-1),
    (0.22,2.1,-2),
    (-0.1,1.47,-1)
    )

edges = (
    (0,1),
    (0,3),
    (1,2),
    (2,3),
    (4,5),
    (4,7),
    (5,6),
    (6,7),
    (8,9),
    (8,11),
    (9,10),
    (10,11)
    )

colors = (
        (1,0,0),
        (1,0,0))


surfaces = (
    (0,1,2,3),
    (4,5,6,7),
    (8,9,10,11)
    )        

def logo():
    
    glBegin(GL_QUADS)
    for surface in surfaces:
            x = 0
            for vertex in surface:
                   glColor3fv(colors[x])
                   glVertex3fv(verticies[vertex])
    glEnd()

    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()


def main():
    pygame.init()
    display = (800,600)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(0.0,0.0, -5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
        glClearColor(1,1,1,0)
        glColor3f(0,0,0)
        logo()
        pygame.display.flip()


main()
