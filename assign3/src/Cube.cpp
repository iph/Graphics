#include "Cube.h"
#include "Shape.h"
#include <stdio.h>
Cube::Cube(int renderModeInit, int initsize){
	center.remake(0,0,0);
	renderMode = renderModeInit;
	size = initsize;
	rs = 1;
	vs = 8;
	verts = new Vertex *[1];
	vertsNorm = new Vertex *[1];
	for(int i = 0; i < 1; i++){
		verts[i] = new Vertex[8];
		vertsNorm[i] = new Vertex[8];
	}
	normDisplay = 0;
	make();
	makeNorm();
}
void Cube::draw(){
	drawTriangle(verts[0], 4,5,1,GREY);
  drawTriangle(verts[0], 0,4,1,BLUE);
  drawTriangle(verts[0], 5,6,2,CYAN);
  drawTriangle(verts[0], 1,5,2,CYAN);
  drawTriangle(verts[0], 3,2,6,YELLOW);
  drawTriangle(verts[0], 7,3,6,YELLOW);
  drawTriangle(verts[0], 0,3,7,MAGENTA);
  drawTriangle(verts[0], 4,0,7,MAGENTA);
	drawTriangle(verts[0], 0,3,1, WHITE);
	drawTriangle(verts[0], 1,3,2, BLUE);
	drawTriangle(verts[0], 4,7,5, BLUE);
	drawTriangle(verts[0], 5,7,6, BLUE); 
	if(normDisplay == 1){
//		makeNorm();
		drawNorms();
	}
}
void Cube::drawNorms(){
	
		glColor3f(.5, .5, .5);
		for(int i = 0; i < 8; i++){
			glBegin(GL_LINES);
					glVertex4f(verts[0][i].x, verts[0][i].y, verts[0][i].z, verts[0][i].w() );
					glVertex4f(vertsNorm[0][i].x, vertsNorm[0][i].y, vertsNorm[0][i].z, vertsNorm[0][i].w());
			glEnd();	
	}
}
void Cube::makeNorm(){
	//cout << "Center: " << center << endl;	
for(int i = 0; i < 8; i++){
		//cout <<"Vert"<< i << ": " <<verts[0][i] << endl;	
		vertsNorm[0][i].remake((verts[0][i].x)*2,(verts[0][i].y)*2, (verts[0][i].z)*2);
	}
}
void Cube::make(){
	GLfloat multiplier = size/2;
	verts[0][0].remake(-1.0*multiplier, 1.0*multiplier, 1.0*multiplier); //{-1,1,1,1}
	verts[0][1].remake(1.0*multiplier, 1.0*multiplier, 1.0*multiplier); //{1,1,1,1}
	verts[0][2].remake(1.0*multiplier, 1.0*multiplier, -1.0*multiplier); //{1,1,-1,1}
	verts[0][3].remake(-1.0*multiplier, 1.0*multiplier, -1.0*multiplier);//{-1,1,-1,1},
  verts[0][4].remake(-1.0*multiplier, -1.0*multiplier, 1.0*multiplier);//{-1,-1,1,1}, 
	verts[0][5].remake(1.0*multiplier, -1.0*multiplier, 1.0*multiplier);//{1,-1,1,1}, 
	verts[0][6].remake(1.0*multiplier, -1.0*multiplier, -1.0*multiplier);//{1,-1,-1,1}, 
	verts[0][7].remake(-1.0*multiplier, -1.0*multiplier, -1.0*multiplier);//{-1,-1,-1,1}


}
void Cube::drawQuad(Vertex vertices[], int iv1, int iv2, int iv3, int iv4, int ic){

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
void Cube::drawTriangle(Vertex vertices[], int iv1, int iv2, int iv3, int ic){
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

