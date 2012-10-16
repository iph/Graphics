#include <stdio.h>
#include <GL/glut.h>

class Shape;
void glutWindow(char *name, int width, int height); //Initializes the glutWindow with name, width, height
void main_display(void);
void reshape(int w, int h);
void idle(void);
void gl_setup(void);
void mouse(int button, int state, int mouseX, int mouseY);
void timeOut(int id);
