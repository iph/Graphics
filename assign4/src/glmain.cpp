/**************************************************************************
File: glmain.c
Does: basic lighting and modeling for cs1566 hw4 Modeler
Author: Steven Lauck, based on some hwa
Date: 01/08/09
**************************************************************************/

#include "glmain.h"
#include "Shape.h"
#include "Scene.h"
#define my_assert(X,Y) ((X)?(void) 0:(printf("error:%s in %s at %d", Y, __FILE__, __LINE__), myabort()))

#define min(a,b) ((a) < (b)? a:b)
#define FALSE 0 
#define TRUE  1
#define MAX_LIGHTS  8
#define NUM_OBJECTS 8



extern GLfloat colors [][3]; 

GLfloat vertices_axes[][4] = {
	{0.0, 0.0, 0.0, 1.0},  /* origin */ 
	{5.0, 0.0, 0.0, 1.0},  /* maxx */ 
	{0.0, 5.0, 0.0, 1.0}, /* maxy */ 
	{0.0, 0.0, 5.0, 1.0}  /* maxz */ 

};
Scene * scene;
//TRUE or FALSE
int firstPersonView;

void myabort(void) {
  abort();
  exit(1); /* exit so g++ knows we don't return. */
} 

int main(int argc, char** argv)
{ 
  setbuf(stdout, NULL);   /* for writing to stdout asap */
  glutInit(&argc, argv);

  my_setup(argc, argv);  
  glut_setup();
  gl_setup();

  glutMainLoop();
  return(0);
}


void glut_setup (){

  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
  
  glutInitWindowSize(700,700);
  glutInitWindowPosition(20,20);
  glutCreateWindow("CS1566 Project 4");

  /* set up callback functions */
  glutDisplayFunc(my_display);
  glutReshapeFunc(my_reshape);
  glutMouseFunc(my_mouse);
  glutMotionFunc(my_mouse_drag);
  glutKeyboardFunc(my_keyboard);
  glutIdleFunc( my_idle );	

  return;
}

void gl_setup(void) {

  // enable depth handling (z-buffer)
  glEnable(GL_DEPTH_TEST);

  // enable auto normalize
  glEnable(GL_NORMALIZE);

  // define the background color 
  glClearColor(0,0,0,1);

  glMatrixMode(GL_PROJECTION) ;
  glLoadIdentity() ;
  gluPerspective( 40, 1.0, 1, 200.0);
  glMatrixMode(GL_MODELVIEW) ;
  glLoadIdentity() ;  // init modelview to identity

  // toggle to smooth shading (instead of flat)
  glShadeModel(GL_SMOOTH); 
 // lighting_setup();


  return ;
}

void my_setup(int argc, char **argv){

  firstPersonView = 1;
  //EX: ./glmain spec3
  my_assert(argc >1, "need to supply a spec file");
  scene = new Scene(argv[1]);
  return;
}



void my_reshape(int w, int h) {
  // ensure a square view port
  glViewport(0,0,min(w,h),min(w,h)) ;
  return ;
}


void my_keyboard( unsigned char key, int x, int y ) {
  
  switch( key ) {
  case ' ':
    //code to switch between first person view and back as appropriate
    glutPostRedisplay();
    break;
  case 'd':
    scene->cam->rotate(1,0,1,0);
    glutPostRedisplay() ;
    break;
  case 'b':
	scene->drawNorms();
	 glutPostRedisplay() ;

	break;
  case 'a':
    scene->cam->rotate(-1, 0, 1, 0);
    glutPostRedisplay() ;
    break;
  case 'w':
    scene->cam->translate(0,0,-1);
    glutPostRedisplay();
    break;
  case 's':
   scene->cam->translate(0,0,1);
    glutPostRedisplay();
    break;
  case 'q': 
  case 'Q':
    exit(0) ;
    break ;	
  default: break;
  }
  
  return ;
}

void my_mouse_drag(int x, int y) {
}



void my_raytrace(int mousex, int mousey)
{

	double modelViewMatrix[16];
	double projMatrix[16];
	int viewport[4];
	double clickPoint[3];

	// first we need to get the modelview matrix, the projection matrix, and the viewport
	glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
	glGetIntegerv(GL_VIEWPORT, viewport);

	// gluUnProject with a Z value of 1 will find the point on the far clipping plane
	// corresponding the the mouse click. This is not the same as the vector
	// representing the click.
	gluUnProject(mousex, (viewport[3]-mousey), 1.0, modelViewMatrix, projMatrix, viewport, &clickPoint[0], &clickPoint[1], &clickPoint[2]);

	// Now we need a vector representing the click. It should start at the camera
	// position. We can subtract the click point, we will get the vector
	Vertex far(clickPoint[0],clickPoint[1],clickPoint[2]);
	 scene->intersect(far);		

}

void my_mouse(int button, int state, int mousex, int mousey) {

  switch( button ) {
	
  case GLUT_LEFT_BUTTON:
    if( state == GLUT_DOWN ) {		
		my_raytrace(mousex, mousey);
		glutPostRedisplay();

    }
    
    if( state == GLUT_UP ) {
    }
    break ;

  case GLUT_RIGHT_BUTTON:
    if ( state == GLUT_DOWN ) {
    }
    
    if( state == GLUT_UP ) {
    }
    break ;
  }
  

  
  return ;
}


/***********************************
 FUNCTION: draw_axes
 ARGS: none
 RETURN: none
 DOES: draws main X, Y, Z axes
************************************/
void draw_axes( void ) {
  
}



void my_display() {

  // clear all pixels, reset depth 
  glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT );
  
  glLoadIdentity();
  //setup the camera (1st person? 3rd person?)

  gluLookAt(scene->cam->camLocation.x,scene->cam->camLocation.y, scene->cam->camLocation.z,
	    scene->cam->lookAt.x, scene->cam->lookAt.y, scene->cam->lookAt.z,
	    scene->cam->up.x, scene->cam->up.y, scene->cam->up.z);
  //update the flashlight to follow the person
  //draw the objects
  draw_axes();
  scene->display();
  glutSwapBuffers();
}

void my_idle(void) {
  //EC idea: Make the flashlight flicker a bit (random flicker strength) when the user is idle.
  return ;
}
