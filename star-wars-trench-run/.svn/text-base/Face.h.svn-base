#include "Vertex.h"
#include "Vect.h"
#ifndef __FACE__HEADER__
#define __FACE__HEADER__ 
class Face{
	public:
		Face(Vertex tl, Vertex tr,Vertex bl,Vertex br, int render);
		Face();
		void remake(Vertex tl, Vertex tr, Vertex bl, Vertex br);
		void draw();
		void changeColor(float red, float blue, float green, float alphan);
		void translate(float xpos, float ypos, float zpos, Vertex * v);
		void translate(float xpos, float ypos, float zpos);
		void rotate(float deg, int x, int y, int z, Vertex * v);
		void rotate(float deg, int x, int y, int z);
		void scale(float xScale, float yScale, float zScale, Vertex * v);
		void scale(float xScale, float yScale, float zScale);

		Vertex topRight, topLeft, bottomLeft, bottomRight;
		void setTexture(unsigned int t);
		unsigned int texture;
		//bool textOn;

	private:
		float r,g,b, alpha;
		int renderMode;
		Vect force, velocity, position; //Do not use yet. 
		
};

#endif
