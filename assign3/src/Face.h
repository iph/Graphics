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
	private:
		float r,g,b, alpha;
		int renderMode;
		Vect force, velocity, position; //Do not use yet. 
		Vertex topRight, topLeft, bottomLeft, bottomRight;
		
};

#endif
