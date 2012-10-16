#include "Shape.h"

extern GLfloat color[][4];
class Cube: public Shape{
public:
	Cube(int renderModeInit, int initsize);
	void draw();
	void make();
	void drawNorms();
	void makeNorm();
	void drawQuad(Vertex vertices[], int iv1, int iv2, int iv3, int iv4, int ic);
	void drawTriangle(Vertex vertices[], int iv1, int iv2, int iv3, int ic);
private:
	Vertex vertices_cube[8];
	int size;
	Vertex verticesNorm[8];
};
