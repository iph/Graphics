#include "Shape.h"

#ifndef __TORUS_HEADER__
#define __TORUS_HEADER__

class Torus: public Shape{
	public:
		Torus(float r, float r2, int rs_i, int vs_i, int render);
		void make();
		void draw();
	private:
		float radius1;
		float radius2;
};

#endif
