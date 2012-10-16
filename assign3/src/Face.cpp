#include "Face.h"
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
