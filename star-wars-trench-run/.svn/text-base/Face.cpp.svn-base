#include "Face.h"
#include "Texture.h"
#include<math.h>


		Face::Face(){
			renderMode = GL_QUADS;
			texture = 0;
		}
		Face::Face(Vertex tl, Vertex tr,Vertex bl,Vertex br,int render){
			renderMode = render;
			topLeft = tl;
			topRight = tr;
			bottomLeft = bl;
			bottomRight = br;
			texture = 0;
			//textOn = false;
		}
		void Face::draw(){
			if(texture == 0){
				glColor3f(r,g,b);
				glBegin(renderMode);
				glVertex3f(topLeft.x, topLeft.y, topLeft.z);
				glVertex3f(bottomLeft.x, bottomLeft.y, bottomLeft.z);
				glVertex3f(bottomRight.x, bottomRight.y, bottomRight.z);
				glVertex3f(topRight.x, topRight.y, topRight.z);

				glEnd();
			}
			else{
				  glEnable(GL_TEXTURE_2D);
				  glEnable (GL_BLEND);
				  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				    /* using the current texture */
				  glBindTexture(GL_TEXTURE_2D,texture);

				    /* Cube */
				  glColor3f(1,1,1);
				glBegin(GL_QUADS);

					glTexCoord2f(1,0); glVertex3f(topLeft.x, topLeft.y, topLeft.z);
					glTexCoord2f(0,0); glVertex3f(bottomLeft.x, bottomLeft.y, bottomLeft.z);
					glTexCoord2f(0,1); glVertex3f(bottomRight.x, bottomRight.y, bottomRight.z);
					glTexCoord2f(1,1); glVertex3f(topRight.x, topRight.y, topRight.z);
				glEnd();
			  glDisable(GL_TEXTURE_2D);
			}

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

void Face::translate(float xpos, float ypos, float zpos){
	translate(xpos,ypos,zpos, &topLeft);
	translate(xpos,ypos,zpos, &topRight);
	translate(xpos,ypos,zpos, &bottomLeft);
	translate(xpos,ypos,zpos, &bottomRight);
}
void Face::translate(float xpos, float ypos, float zpos, Vertex * v){
	v->x +=xpos;
	v->y += ypos;
	v->z += zpos;
}
void Face::rotate(float deg, int x, int y, int z){
	rotate(deg,x,y,z, &topLeft);
	rotate(deg,x,y,z, &topRight);
	rotate(deg,x,y,z, &bottomLeft);
	rotate(deg,x,y,z, &bottomRight);
}
void Face::rotate(float deg, int x, int y, int z, Vertex * v){
	deg = 2*deg*3.141592654f/180.0f;
	if(x == 1){
		GLfloat ypos = v->y;
		GLfloat zpos = v->z;
		v->y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		v->z = ypos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(y == 1){
		GLfloat xpos = v->x;
		GLfloat zpos = v->z;
		v->x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		v->z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(z == 1){
		GLfloat xpos = v->x;
		GLfloat ypos = v->y;
		v->x = xpos*(float)cos(deg) - ypos*(float)sin(deg); 
		v->y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
	}
}
void Face::scale(float xScale, float yScale, float zScale){
	scale(xScale,yScale,zScale, &bottomLeft);
	scale(xScale,yScale,zScale, &bottomRight);
	scale(xScale,yScale,zScale, &topLeft);
	scale(xScale,yScale,zScale, &topRight);
}
void Face::scale(float xScale, float yScale, float zScale, Vertex * v){
	v->x *=xScale;
	v->y *=yScale;
	v->z *=zScale;
}
void Face::setTexture(unsigned int t){
	texture = t;
}
