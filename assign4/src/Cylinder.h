#include "Shape.h"

#ifndef __CYLINDER_HEADER__
#define __CYLINDER_HEADER__

class Cylinder: public Shape{
	public:
		Cylinder(float r, float h, int rs_i, int vs_i, int render);
		void make();
		void makeNorms();
		bool intersect(Vertex p, Vect d, vector <Shape *> * f);			   
	    	bool unitIntersect(Vertex p, Vect d, vector <Shape *> * f);
	private:
		float radius;
		float height;
};

#endif
