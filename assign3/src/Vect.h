#include <glut.h>
#include <iostream>
#include "Vertex.h"
using namespace std;
#ifndef __VECT_HEADER__
#define __VECT_HEADER__
class Vect{
	friend ostream& operator<<(ostream& output, const Vect& p);
	public:
		Vect(Vertex a, Vertex b);
		Vect(float _x, float _y, float _z );
		Vect();
		bool isParallel(Vect a);
  	float length();
		static Vect * unitVector(Vect a);
		static Vect * crossProduct(Vect a, Vect b);
		GLfloat x, y, z;
};
#endif
