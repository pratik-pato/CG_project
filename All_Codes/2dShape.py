import pygame
from OpenGL.GL import *
from OpenGL.GLU import *


from pygame.locals import *


from math import *
posx, posy = 0,0
sides = 32
radius = 1
glBegin(GL_POLYGON)
for i in range(100):
        cosine = radius * cos(i*2*pi/sides) + posx
        sine  = radius * sin(i*2*pi/sides) + posy

glVertex2f(cosine,sine)


verticies =((0.0, 1.1,0),  # head_part
            (0.3, 0.8,0),
            (0.8, 0.5,0)) 


edges = ((0,1),(1,2))


def doll():
    glBegin(GL_LINES)
    for edge in edges:
        for vertex in edge:
            glVertex3fv(verticies[vertex])
    glEnd()


def main():
    pygame.init()
    display = (1360,820)
    pygame.display.set_mode(display, DOUBLEBUF|OPENGL)

    gluPerspective(45, (display[0]/display[1]), 0.1, 50.0)

    glTranslatef(0.0,0.0, -5)

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
      
        doll()
        pygame.display.flip()


main()
