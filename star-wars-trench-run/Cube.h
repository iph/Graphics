#include "Shape.h"
#include "Rectangle.h"
#ifndef __CUBEHEADER__
#define __CUBEHEADER__

extern GLfloat colors[][3];
class Cube: public Shape{
public:
	Cube(int renderModeInit, int initsize);
	void draw();
	void make();
	Rectangle * rects;
//	void drawNorms();
    void remake(int rs_i, int vs_i);
	void makeNorm();
	void drawQuad(Vertex vertices[], int iv1, int iv2, int iv3, int iv4, int ic);
	void drawTriangle(Vertex vertices[], int iv1, int iv2, int iv3, int ic);
	bool intersect(Vertex p, Vect d, vector <Shape *> * a);
	bool intersectUnit(Vertex p, Vect d, vector <Shape *> * a);
	void translate(float xpos, float ypos, float zpos);
	void rotate(float deg, int x, int y, int z);
	void scale(float xScale, float yScale, float zScale);
	void translate(float xpos, float ypos, float zpos, Vertex * v);
	void rotate(float deg, int x, int y, int z, Vertex * v);
	void scale(float xScale, float yScale, float zScale, Vertex * v);
	void setTexture(unsigned int t);
private:
	int size;
	Vertex verticesNorm[8];
};

#endif
