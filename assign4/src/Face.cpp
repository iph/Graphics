#include "Face.h"
#include<math.h>
#include <glut.h>
		Face::Face(){
			renderMode = GL_POLYGON;
		}
		Face::Face(Vertex tl, Vertex tr,Vertex bl,Vertex br,int render){
			renderMode = render;
			topLeft = tl;
			topRight = tr;
			bottomLeft = bl;
			bottomRight = br;
		}
		void Face::draw(){
			glColor3f(r,g,b);
			glBegin(renderMode);
				glVertex3f(bottomRight.x, bottomRight.y, bottomRight.z);				
				glVertex3f(topRight.x, topRight.y, topRight.z);
				glVertex3f(topLeft.x, topLeft.y, topLeft.z);
				glVertex3f(bottomLeft.x, bottomLeft.y, bottomLeft.z);
			glEnd();
		}
		void Face::changeColor(float red, float green, float blue, float alphan){
			r = red;
			b = blue;
			g = green;
			alpha = alphan;
		}
	void Face::remake(Vertex tl, Vertex tr, Vertex bl, Vertex br){
		topLeft = tl;
		topRight = tr;
		bottomLeft = bl;
		bottomRight = br;
	}	
void Face::translate(float xpos, float ypos, float zpos, Vertex * v){
	v->x +=xpos;
	v->y += ypos;
	v->z += zpos;
}
void Face::rotate(float deg, int x, int y, int z, Vertex * v){
	if(x == 1){
		GLfloat ypos = v->y;
		GLfloat zpos = v->z;
		v->y = ypos*cos(deg) - zpos*sin(deg);
		v->z = ypos*sin(deg) + zpos*cos(deg);
	}
	if(y == 1){
		GLfloat xpos = v->x;
		GLfloat zpos = v->z;
		v->x = xpos*cos(deg) - zpos*sin(deg);
		v->z = xpos*sin(deg) + zpos*cos(deg);
	}
	if(z == 1){
		GLfloat xpos = v->x;
		GLfloat ypos = v->y;
		v->x = xpos*cos(deg) - ypos*sin(deg); 
		v->y = xpos*sin(deg) + ypos*cos(deg);
	}
}

void Face::scale(float xScale, float yScale, float zScale, Vertex * v){
	v->x *=xScale;
	v->y *=yScale;
	v->z *=zScale;
}
