
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
PROGRAM  = glhello
OBJ      = glhello.o 


$(PROGRAM): $(OBJ) 
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJ)  $(LIB) 

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(PROGRAM)
	/bin/rm -f core
