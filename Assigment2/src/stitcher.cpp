/*******************************************************
FILE: stitcher.c
AUTHOR: gem, loosely based on random hwa skel
DATE: 01/24/08
DOES: skeleton for hmkw2 redux
PLATFORM: tested on osx, linux, and vs
********************************************************/
#include "Shape.h"
#include "Cylinder.h"
#include "House.h"
#include "Cube.h"
#include "Sphere.h"
#include "stitcher.h"
#include "Cone.h"
#include "Torus.h"
#include <stdio.h>
int theta_x;
int theta_y;
int crt_render_mode;
int crt_shape, crt_rs, crt_vs;
double cyl_height=3;
double cyl_ray=1;
double sph_ray=3;
//Shape designs[2] = {House(GL_LINE_LOOP), Cube(GL_LINE_LOOP, 2)};
Shape *design[6];
Shape * currentShape;

/*******************************************************
FUNCTION: main
ARGS: argc, argv
RETURN: 0
DOES: main function (duh!); starts GL, GLU, GLUT, then loops 
********************************************************/
int main(int argc, char **argv) {

  /* General initialization for GLUT and OpenGL
     Must be called first */
  glutInit( &argc, argv ) ;
  
  /* we define these setup procedures */
  glut_setup() ;  
  gl_setup() ;
	design[0] = new House(GL_LINE_LOOP);
	design[1] = new Cube(GL_LINE_LOOP, 2);
	design[2] = new Sphere(2, 10, 10, GL_LINE_LOOP);
	design[3] = new Cone(2,3, 10 , 10, GL_LINE_LOOP);
	design[4] = new Torus(1,3, 10 , 10, GL_LINE_LOOP);
	design[5] = new Cylinder(2,3, 10, 10, GL_LINE_LOOP);
  my_setup();

  /* go into the main event loop */
  glutMainLoop() ;

  return(0) ;
}


/*******************************************************
FUNCTION: glut_setup
ARGS: none
RETURN: none
DOES: sets up GLUT; done here because we like our 'main's tidy
********************************************************/
/* This function sets up the windowing related glut calls */
void glut_setup(void) {

  /* specify display mode -- here we ask for a double buffer and RGB coloring */
  /* NEW: tell display we care about depth now */
  glutInitDisplayMode (GLUT_DOUBLE |GLUT_RGB |GLUT_DEPTH);

  /* make a 400x400 window with the title of "Stitcher" placed at the top left corner */
  glutInitWindowSize(400,400);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Stitcher");

  /*initialize callback functions */
  glutDisplayFunc( my_display );
  glutReshapeFunc( my_reshape ); 
  glutMouseFunc( my_mouse);
  glutKeyboardFunc(my_keyboard);

  /*just for fun, uncomment the line below and observe the effect :-)
    Do you understand now why you shd use timer events, 
    and stay away from the idle event?  */
  //  glutIdleFunc( my_idle );
	
  glutTimerFunc( 20000, my_TimeOut, 0);/* schedule a my_TimeOut call with the ID 0 in 20 seconds from now */
  return ;
}


/*******************************************************
FUNCTION: gl_setup
ARGS: none
RETURN: none
DOES: sets up OpenGL (name starts with gl but not followed by capital letter, so it's ours)
********************************************************/
void gl_setup(void) {

  /* specifies a background color: black in this case */
  glClearColor(0,0,0,0) ;

  /* NEW: now we have to enable depth handling (z-buffer) */
  glEnable(GL_DEPTH_TEST);

  /* NEW: setup for 3d projection */
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  // perspective view
  gluPerspective( 20.0, 1.0, 1.0, 100.0);
  return;
}

/*******************************************************
FUNCTION: my_setup
ARGS: 
RETURN:
DOES: pre-computes staff and presets some values
********************************************************/
/*TODO EC: add make_torus etc.   */
void my_setup(void) {
  theta_x = 0;
  theta_y = 0;
	crt_shape = HOUSE;
  currentShape = design[0];
  crt_rs = 20;
  crt_vs = 10;

  return;
}

/*******************************************************
FUNCTION: my_reshape
ARGS: new window width and height 
RETURN:
DOES: remaps viewport to the Window Manager's window
********************************************************/
void my_reshape(int w, int h) {

  /* define viewport -- x, y, (origin is at lower left corner) width, height */
  glViewport (0, 0, min(w,h), min(w,h));
  return;
}


/*******************************************************
FUNCTION: my_keyboard
ARGS: key id, x, y
RETURN:
DOES: handles keyboard events
********************************************************/
/*TODO: expand to add asgn 2 keyboard events */
void my_keyboard( unsigned char key, int x, int y ) {
  
  switch( key ) {
	case 'v':
	case 'V':
		{
			currentShape->changeNormDisplay((currentShape->getNormDisplay()+1)%2);
			glutPostRedisplay(); 		
		}break;
	case ',':
	case '<':{
			if(crt_shape == CUBE || crt_shape == HOUSE){
					printf("NOPE\n");
					break;
			}
			currentShape->changeRow(currentShape->getRS()-1);
			glutPostRedisplay(); 		
	};break;
	case '_':
	case '-':{
			if(crt_shape == CUBE || crt_shape == HOUSE){
					printf("NOPE\n");
					break;
			}
			currentShape->changeVertical(currentShape->getVS()-1);
			glutPostRedisplay(); 		
		};break;

	case '=':
	case '+':{
			if(crt_shape == CUBE || crt_shape == HOUSE){
					printf("NOPE\n");
					break;
			}
			currentShape->changeVertical(currentShape->getVS()+1);
			glutPostRedisplay(); 		
		};break;
	case '.':
	case '>':{
			if(crt_shape == CUBE || crt_shape == HOUSE){
					printf("NOPE\n");
					break;
			}
			currentShape->changeRow(currentShape->getRS()+1);
			glutPostRedisplay(); 		
	};break;
  case 'y':
  case 'Y': {
    theta_y = (theta_y+2) %360;
    glutPostRedisplay(); 
  }; break;
  case 'x':
  case 'X': {
    theta_x = (theta_x+2) %360;
    glutPostRedisplay(); 
  }; break;
  case '@':
	case 'b':
  case '2': {
    crt_shape = CUBE;
    glutPostRedisplay();
  }; break;
  case '1':
	case 'h':
  case '!': {
    crt_shape = HOUSE;
    glutPostRedisplay();
  }; break;
	case '#':
	case 's':
	case '3':{
		crt_shape = SPHERE;
		glutPostRedisplay();
}; break;
	case '$':
	case 'n':
	case '4':{
		crt_shape = CONE;
		glutPostRedisplay();
}; break;
	case 'm':
	case '5':{
		crt_shape = TORUS;
		glutPostRedisplay();
	}break;
	case '6':{
		crt_shape = CYLINDER;
		glutPostRedisplay();
	};break;
 case 'q': 
  case 'Q':
    exit(0) ;
  default: break;
  }
  
  return ;
}


/*******************************************************
FUNCTION: my_mouse
ARGS: button, state, x, y
RETURN:
DOES: handles mouse events
********************************************************/
void my_mouse(int button, int state, int mousex, int mousey) {

  switch( button ) {
	
  case GLUT_LEFT_BUTTON:
    if( state == GLUT_DOWN ) {
      currentShape->changeRender(GL_LINE_LOOP);
      /* if you're not sure what glutPostRedisplay does for us,
	 try commenting out the line below; observe the effect.*/
      glutPostRedisplay();
    }
    if( state == GLUT_UP ) {
    }
    break ;

  case GLUT_RIGHT_BUTTON:
    if ( state == GLUT_DOWN ) {
      currentShape->changeRender(GL_POLYGON);
      glutPostRedisplay();
    }
    if( state == GLUT_UP ) {
    }
    break ;
  }
  
  return ;
}



/***********************************
  FUNCTION: draw_object 
  ARGS: shape to create (HOUSE, CUBE, CYLINDER, etc)
  RETURN: none
  DOES: draws an object from triangles
************************************/
/*TODO: expand according to assignment 2 specs*/
void draw_object(int shape) {

  switch(shape){
		case HOUSE: 
			currentShape = design[0];
			currentShape->draw();
			break;
		case CUBE: 
			printf("Got here\n");
			currentShape = design[1];
			currentShape->draw();
			break; 
		case SPHERE:
			currentShape = design[2];
			currentShape->draw(); 
			break;
		case CONE:
			currentShape = design[3];
			currentShape->draw(); 
			break;
		case TORUS:
			currentShape = design[4];
			currentShape->draw(); 
			break;
		case CYLINDER:
			currentShape = design[5];
			currentShape->draw(); 
			break;
		case MESH:
			break;

		default: 
			break;
		}

}



/***********************************
  FUNCTION: my_display
  ARGS: none
  RETURN: none
  DOES: main drawing function
************************************/
void my_display(void) {
	/* clear the buffer */
	/* NEW: now we have to clear depth as well */
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) ;

	glMatrixMode(GL_MODELVIEW) ;
	glLoadIdentity();
	gluLookAt(0.0, 5.0, 25.0,  // x,y,z coord of the camera 
		  0.0, 0.0, 0.0,  // x,y,z coord of the origin
		  0.0, 1.0, 0.0); // the direction of up (default is y-axis)

	glRotatef(theta_y,0,1,0);
	glRotatef(theta_x,1,0,0);
	draw_object(crt_shape);
	/* buffer is ready */
	glutSwapBuffers();

	return ;
}


/***********************************
  FUNCTION: my_idle
  ARGS: none
  RETURN: none
  DOES: handles the "idle" event
************************************/
void my_idle(void) {
	theta_y = (theta_y+2) %360;
	glutPostRedisplay();
	return ;
}


/***********************************
  FUNCTION: my_TimeOut
  ARGS: timer id
  RETURN: none
  DOES: handles "timer" events
************************************/
void my_TimeOut(int id) {
  /* right now, does nothing*/
  /* schedule next timer event, 20 secs from now */ 
  glutTimerFunc(20000, my_TimeOut, 0);

  return ;
}



