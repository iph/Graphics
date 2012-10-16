
#   TARGETS ...: TARGET-PATTERN: DEP-PATTERNS ...
#             COMMANDS
#
# `$<' is the automatic variable that holds the name of the
# prerequisite and `$@' is the automatic variable that holds the name of
# the target; 


# Basic stuff

CC       = gcc 
CFLAGS   = -O3 -Wall 
INC      = -I/usr/X11/include  -I/usr/include -I/usr/include/GL -I/usr/lib/include/GL 
LIB      = -L/usr/lib/X11 -L/usr/lib -lXi -lXmu -lGL -lglut -lGLU  -lm 
PROGRAM  = intersect
OBJ      = Enemy.o Player.o Texture.o Camera.o Scene.o Face.o Vect.o Shape.o Vertex.o Cube.o glmain.o Sphere.o Rectangle.o

all: $(PROGRAM)


$(PROGRAM): $(OBJ) 
	$(CC) $(CFLAGS) -g -o $(PROGRAM) $(OBJ)  $(LIB) 

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -g -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(PROGRAM)
	/bin/rm -f core
