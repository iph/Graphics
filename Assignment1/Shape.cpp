#include "Shape.h"
#include <stdio.h>

#define CIRCLE 1
#define RECTANGLE 0

//Creates a new shape. Will have x co ordinates, y co ordinates
Shape::Shape(int newType, int newRadius){
	x = 0;
	y = 0;
	type = newType;
	radius = newRadius;
	drawAble = 0;
}
Shape::~Shape(){
	return;
}
void Shape::drawShape(float width, float height){
	if(drawAble == 0){
		return;
	}
	if(type == 1){
	 glColor3f(47.0/255,120.0/255,186.0) ;
		/* draw something */
		glBegin(GL_POLYGON);
		glVertex2f(x/height,(width-y)/width);
		int max = 30;
		for(int i = 0; i <= max; i++){
			float sincalc = 2*PI*i/max;
			float coscalc = sincalc;
			sincalc = y+ 20*sin(sincalc);
			coscalc = x + 20*cos(coscalc);
			sincalc = (width-sincalc)/width;
			coscalc = coscalc/height;
			glVertex2f(coscalc, sincalc);
		}
		glEnd();
	}
	if(type == 0){
	 glColor3f(0,1,0) ; //Sets the color to green.

	//Creates a square (rectangle), that is width and height long
	 glRectf( x/width, (width-y)/height, x/width + radius/width, (width-y)/height - radius/width);
	
	}
		return;
}
void Shape::changePoint(int new_x, int new_y){
	x = new_x;
	y = new_y;
}
void Shape::changeType(int newType){
	type = newType;
}

