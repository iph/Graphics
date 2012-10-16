
#   TARGETS ...: TARGET-PATTERN: DEP-PATTERNS ...
#             COMMANDS
#
# `$<' is the automatic variable that holds the name of the
# prerequisite and `$@' is the automatic variable that holds the name of
# the target; 


# Basic stuff

CC       = gcc 
CFLAGS   = -O3 -Wall -m32
INC      = -I/usr/local/include -I/usr/local/lib/include
LIB      = -L/usr/local/lib -lGL -lGLU -lglut
PROGRAM  = hellomouse
OBJ      = hellomouse.o 


$(PROGRAM): $(OBJ) 
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJ)  $(LIB) 

$(OBJ): %.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< 
	
clean:
	/bin/rm -f *.o
	/bin/rm -f $(PROGRAM)
	/bin/rm -f core
