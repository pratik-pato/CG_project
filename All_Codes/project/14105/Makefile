.PHONY:runtest
all:penguin bounce_squash bounce stick smile
CC=gcc
CFLAGS= -lglut -lGLU -lGL -lm
RM = rm -f

stick:stick_figure.cpp 
	  	  $(CC) $(CFLAGS) -o stick stick_figure.cpp

smile:stick_smile.cpp 
	  	  $(CC) $(CFLAGS) -o smile stick_smile.cpp 

bounce:bouncing.cpp 
	  	  $(CC) $(CFLAGS) -o bounce bouncing.cpp 

bounce_squash:bounce_squash.cpp 
	  	  $(CC) $(CFLAGS) -o bounce_squash bounce_squash.cpp 

penguin:penguin.cpp 
	  	  $(CC) $(CFLAGS) -o penguin penguin.cpp 
clean:
	$(RM) penguin bounce_squash bounce stick smile
