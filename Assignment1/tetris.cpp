#include "tetris.h"
#include "Shape.h"
#include <math.h>
#define PI 3.141592654
float width = 400;
int currentShape = 0;
Shape p[25] = {Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1),Shape(), Shape(1) };
float height = 400;
int main(int argc, char ** argv){

	//Initializes glut.
	glutInit(&argc, argv);
	char rawr[5] = "rawr";
	glutWindow(rawr, width, height);

  /* we define these setup procedures */
  gl_setup() ;

  /* go into the main event loop */
  glutMainLoop() ;

	return 0;
}

void glutWindow(char *name, int width, int height){
	/* specify display mode -- here we ask for a double buffer and RGB coloring */
	glutInitDisplayMode (GLUT_DOUBLE |GLUT_RGB);

	glutInitWindowSize(width,height);
	glutInitWindowPosition(0,0);
	glutCreateWindow(name);

  /*initialize callback functions */
	glutDisplayFunc(main_display);
	glutReshapeFunc(reshape); 
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutTimerFunc(200, timeOut, 0);
}

/* This function sets up the initial states of OpenGL related enivornment */
void gl_setup(void) {

	  /* specifies a background color: black in this case */
	glClearColor(0,0,0,0) ;

	  /* setup for simple 2d projection */
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
  gluOrtho2D(0.0, 1.0, 0.0, 1.0); 

	return ;
}

void main_display(void){
  /* clear the buffer */
  glClear(GL_COLOR_BUFFER_BIT) ;
 		for(int i = 0; i < 25; i++){
		p[i].drawShape(width,height);
	}
  /* buffer is ready */
  glutSwapBuffers();
	
  return ;
}
//TODO: When clicked, creates a triangle, then a circle.
void mouse(int button, int state, int mouseX, int mouseY){
switch(button){
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN)  {    /* button pressed */
			//TODO: IF int = 1, then create Circle, otherwise rectangle.
			currentShape++;
			currentShape = currentShape % 25;
			p[currentShape].drawAble = 1;
			p[currentShape].changePoint(mouseX, mouseY);
			main_display();
    }

}


}

void reshape(int w, int h){

	/* define viewport -- x, y, (origin is at lower left corner) width, height */
	glViewport(0, 0, w, h); 
  
	return;
}

void idle(void){
	return;
}

void timeOut(int id) { 
	for(int i = 0; i < 25; i++){
			if((p[i].getType() == 0 && p[i].getY()+ p[i].getRadius() >= width) || (p[i].getType() == 1 && p[i].getY()+ p[i].getRadius()/2 >= width)){
				continue;
			}
			p[i].changePoint(p[i].getX(), p[i].getY() + 5);	
	}
main_display();
  glutTimerFunc(100, timeOut, 0);

}
