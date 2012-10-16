#include "Shape.h"
extern GLfloat color[][4];
class House: public Shape{
public:
	House(int renderModeInit);
	void draw();
	static GLfloat vertices_house[9][4];
	void drawQuad(GLfloat vertices[][4], int iv1, int iv2, int iv3, int iv4, int ic);
	void drawTriangle(GLfloat vertices[][4], int iv1, int iv2, int iv3, int ic);
};
