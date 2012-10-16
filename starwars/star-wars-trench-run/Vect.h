#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include<glut.h>
#endif
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
		static float dotProduct(Vect a, Vect b);
		static float dotProduct(Vertex a, Vect b);
		static float dotProduct(Vertex a, Vertex b);
		static float dotProduct(Vect a, Vertex b);
		static Vect * unitVector(Vect a);
		static Vect * crossProduct(Vect a, Vect b);
		GLfloat x, y, z;
};
#endif
