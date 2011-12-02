#include <glut.h>
#include <iostream>
#ifndef __VERTEX_HEADER__
#define __VERTEX_HEADER__


using namespace std;
class Vertex{
	friend ostream& operator<<(ostream& output, const Vertex& p);
	public:
		Vertex();
		Vertex(GLfloat initX, GLfloat initY, GLfloat initZ);
		GLfloat x;
		GLfloat y;
		GLfloat z;
		GLfloat w(){ return 1;};
		void remake(GLfloat makeX, GLfloat makeY, GLfloat makeZ);
		GLfloat * getVertex();
		void normalize();
};
#endif
