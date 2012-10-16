#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include<glut.h>
#endif
#ifndef __CAMERA_HEADER__
#define __CAMERA_HEADER__
#include "Vect.h"
#include "Vertex.h"
#include <math.h>
class Camera{
	public:
		Camera(GLfloat *pos, GLfloat * at, GLfloat * up_i);
		void translate(float xpos, float ypos, float zpos);
		void rotate(float deg, int x, int y, int z);
		void updateLookAt();	

		Vect up;
		Vect direction;
		Vertex camLocation;
		Vertex lookAt; 
		
};


#endif
