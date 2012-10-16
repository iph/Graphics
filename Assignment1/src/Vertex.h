#include <glut.h>
#ifndef __SHAPE_HEADER__
#define __SHAPE_HEADER__

class Vertex{
	public:
		Vertex(GLfloat initX, GLfloat initY, GLfloat initZ);
		GLfloat x(){ return x;};
		GLfloat y(){ return y;};
		GLfloat z(){ return z;};
		GLfloat w(){ return 1;};
	private:
		int x;
		int y;
		int z;
};
#endif
