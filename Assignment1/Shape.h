#include <GL/glut.h>
#include <math.h>
#define PI 3.141592654
#ifndef __SHAPE_HEADER__
#define __SHAPE_HEADER__

class Shape{
public:
	Shape(int type = 0, int radius = 50);
	virtual ~Shape();
	void drawShape(float width, float height);
	void changePoint(int x, int y);
	void changeType(int newType);
	int drawAble;
	int getX(){return x;};
	int getY(){return y;};
	int getRadius(){return radius;};
	int getType(){return type;};
private:
	int x;
	int y;
	int type;
	int radius;
};

#endif
