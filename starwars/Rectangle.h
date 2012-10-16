#ifndef __RECTANGLE_HEADER__
#define __RECTANGLE_HEADER__

#include "Vect.h"
#include "Vertex.h"
#include "Shape.h"
#include "Rectangle.h"


class Rectangle: public Shape{
public:
	Rectangle();
    Rectangle(int rs_i, int vs_i, unsigned t);
    void remake(int rs_i, int vs_i, unsigned t);
    void make();
    void draw();
    void makeFaces();
    void setTranslate(float x, float y, float z);
    void setRotate(float x, float y, float z);
    void setScale(float x, float y, float z);

    bool intersect(Vertex p, Vect d, vector<Shape *> * intersects);
    bool intersectUnit(Vertex p, Vect d, vector<Shape *> * intersects);
    void setTexture(unsigned int t);
	void translate(float xpos, float ypos, float zpos);
	void rotate(float deg, int x, int y, int z);
	void scale(float xScale, float yScale, float zScale);
	void translate(float xpos, float ypos, float zpos, Vertex * v);
	void rotate(float deg, int x, int y, int z, Vertex * v);
	void scale(float xScale, float yScale, float zScale, Vertex * v);

};

#endif
