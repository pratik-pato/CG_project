.PHONY:runtest
all:final_duck bounce_squash bounce stick
CC=gcc
CFLAGS= -lglut -lGLU -lGL -lm
RM = rm -f

stick:stick_figure.cpp 
	  	  $(CC) $(CFLAGS) -o stick stick_figure.cpp 

bounce:bouncing.cpp 
	  	  $(CC) $(CFLAGS) -o bounce bouncing.cpp 

bounce_squash:bounce_squash.cpp 
	  	  $(CC) $(CFLAGS) -o bounce_squash bounce_squash.cpp 

final_duck:final_duck.cpp 
	  	  $(CC) $(CFLAGS) -o final_duck final_duck.cpp 
clean:
	$(RM) final_duck bounce_squash bounce stick
