#include "House.h"
#include "Shape.h"
#include <stdio.h>
/*
Function Shape--drawQuad
	Use: Mostly for the predefined shapes that use it, all the dynamic ones use draw() to do what they have to.

*/
void House::drawQuad(GLfloat vertices[][4], int iv1, int iv2, int iv3, int iv4, int ic) {
  glBegin(renderMode); 
  {
    glColor3fv(colors[ic]);
    /*note the explicit use of homogeneous coords below: glVertex4f*/
    glVertex4fv(vertices[iv1]);
    glVertex4fv(vertices[iv2]);
    glVertex4fv(vertices[iv3]);
    glVertex4fv(vertices[iv4]);
  }
  glEnd();
}

//Initializes house arrays.
GLfloat House::vertices_house[9][4] = {
  		{0,2,0,1}, 
  		{-1,1,1,1}, {1,1,1,1}, {1,1,-1,1}, {-1,1,-1,1},
  		{-1,-1,1,1}, {1,-1,1,1}, {1,-1,-1,1}, {-1,-1,-1,1}
	};


House::House(int renderModeInit){
	renderMode = renderModeInit;
}
void House::draw(){
	drawTriangle(vertices_house,0,1,2,RED);
	drawTriangle(vertices_house,0,2,3,GREEN);
	drawTriangle(vertices_house,0,3,4,WHITE);
	drawTriangle(vertices_house,0,4,1,GREY);
	drawQuad(vertices_house,2,1,5,6, BLUE);
	drawTriangle(vertices_house,2,6,3, CYAN);
	drawTriangle(vertices_house,3,6,7, CYAN);
	drawTriangle(vertices_house,3,7,8, YELLOW);
	drawTriangle(vertices_house,8,3,4, YELLOW);
	drawTriangle(vertices_house,4,8,1, MAGENTA);
	drawTriangle(vertices_house,1,8,5, MAGENTA);
	printf("rendermode: %d\n", renderMode);
}

void House::drawTriangle(GLfloat vertices[][4], int iv1, int iv2, int iv3, int ic) {
  glBegin(renderMode); 
  {
    glColor3fv(colors[ic]);
    /*note the explicit use of homogeneous coords below: glVertex4f*/
    glVertex4fv(vertices[iv1]);
    glVertex4fv(vertices[iv2]);
    glVertex4fv(vertices[iv3]);
  }
  glEnd();
}

