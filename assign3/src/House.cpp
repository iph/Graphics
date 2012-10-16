#include "House.h"
#include "Shape.h"
#include <stdio.h>
/*
Function Shape--drawQuad
	Use: Mostly for the predefined shapes that use it, all the dynamic ones use draw() to do what they have to.

*/

House::House(int renderModeInit){
	renderMode = renderModeInit;
	vs = 9;
	rs = 1;
	center.remake(0,0,0);
	verts = new Vertex *[rs];
	vertsNorm = new Vertex *[rs];
	for(int i = 0; i < rs; i++){
		verts[i] = new Vertex[vs];
		vertsNorm[i] = new Vertex[vs];
	}
	verts[0][0].remake(0.0, 2.0, 0.0);
	verts[0][1].remake(-1.0, 1.0, 1.0);
	verts[0][2].remake(1.0, 1.0, 1.0);
	verts[0][3].remake(1.0, 1.0, -1.0);
	verts[0][4].remake(-1.0, 1.0, -1.0);
	verts[0][5].remake(-1.0, -1.0, 1.0);
	verts[0][6].remake(1.0, -1.0, 1.0);
	verts[0][7].remake(1.0, -1.0, -1.0);
	verts[0][8].remake(-1.0, -1.0, -1.0);
	makeNorms();

}
void House::draw(){
	drawTriangle(verts[0],0,1,2,RED);
	drawTriangle(verts[0],0,2,3,GREEN);
	drawTriangle(verts[0],0,3,4,WHITE);
	drawTriangle(verts[0],0,4,1,GREY);
	drawQuad(verts[0],2,1,5,6, BLUE);
	drawTriangle(verts[0],2,6,3, CYAN);
	drawTriangle(verts[0],3,6,7, CYAN);
	drawTriangle(verts[0],3,7,8, YELLOW);
	drawTriangle(verts[0],8,3,4, YELLOW);
	drawTriangle(verts[0],4,8,1, MAGENTA);
	drawTriangle(verts[0],1,8,5, MAGENTA);

}
Vertex House::chooseAxis(){
	return verts[0][0];
}
void House::drawQuad(Vertex vertices[], int iv1, int iv2, int iv3, int iv4, int ic){

	GLfloat ve1[4] = {vertices[iv1].x, vertices[iv1].y, vertices[iv1].z, 1}; 
	GLfloat * ve2 = vertices[iv2].getVertex();
	GLfloat * ve3 = vertices[iv3].getVertex();
	GLfloat * ve4 = vertices[iv4].getVertex();

	glBegin(renderMode); 
	{
		glColor3fv(colors[ic]);
		/*note the explicit use of homogeneous coords below: glVertex4f*/
		glVertex4fv(ve1);
		glVertex4fv(ve2);
		glVertex4fv(ve3);
		glVertex4fv(ve4);
	}
	glEnd();
	delete ve2;
	delete ve3;
	delete ve4;
}
void House::drawTriangle(Vertex vertices[], int iv1, int iv2, int iv3, int ic){
	GLfloat ve1[4] = {vertices[iv1].x, vertices[iv1].y, vertices[iv1].z, 1}; 
	GLfloat ve2[4] ={vertices[iv2].x, vertices[iv2].y, vertices[iv2].z, 1};
	GLfloat ve3[4] = {vertices[iv3].x, vertices[iv3].y, vertices[iv3].z, 1};
  glBegin(renderMode); 
  {
    glColor3fv(colors[ic]);
    /*note the explicit use of homogeneous coords below: glVertex4f*/
    glVertex4fv(ve1);
    glVertex4fv(ve2);
    glVertex4fv(ve3);
  }
  glEnd();

}

