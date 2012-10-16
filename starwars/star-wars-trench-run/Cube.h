#include "Shape.h"

extern GLfloat colors[][3];
class Cube: public Shape{
public:
	Cube(int renderModeInit, int initsize);
	void draw();
	void make();
//	void drawNorms();
	void makeNorm();
	void drawQuad(Vertex vertices[], int iv1, int iv2, int iv3, int iv4, int ic);
	void drawTriangle(Vertex vertices[], int iv1, int iv2, int iv3, int ic);
	bool intersect(Vertex p, Vect d, vector <Shape *> * a);
	bool intersectUnit(Vertex p, Vect d, vector <Shape *> * a);

private:
	int size;
	Vertex verticesNorm[8];
};
