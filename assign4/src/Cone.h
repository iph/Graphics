#include "Shape.h"

#ifndef __CONE_HEADER__
#define __CONE_HEADER__

class Cone: public Shape{
	public:
		Cone(float r, float height, int rs_i, int vs_i, int render);
		void make();
	private:
		float radius;
		float height;
};

#endif
