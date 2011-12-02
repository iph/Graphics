#include "Shape.h"
extern GLfloat colors[][3];
class House: public Shape{
public:
	House(int renderModeInit);
	void draw();
	void drawQuad(Vertex vertices[], int iv1, int iv2, int iv3, int iv4, int ic);
	void drawTriangle(Vertex vertices[], int iv1, int iv2, int iv3, int ic);
	Vertex chooseAxis();
};
