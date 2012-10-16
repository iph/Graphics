#include "Cube.h"
#include "Shape.h"
#include <stdio.h>
Cube::Cube(int renderModeInit, int initsize){
	renderMode = renderModeInit;
	size = initsize;
	normDisplay = 0;
	make();
	makeNorm();
}
void Cube::draw(){
	drawTriangle(vertices_cube, 4,5,1,BLUE);
  drawTriangle(vertices_cube, 0,4,1,BLUE);
  drawTriangle(vertices_cube, 5,6,2,CYAN);
  drawTriangle(vertices_cube, 1,5,2,CYAN);
  drawTriangle(vertices_cube, 3,2,6,YELLOW);
  drawTriangle(vertices_cube, 7,3,6,YELLOW);
  drawTriangle(vertices_cube, 0,3,7,MAGENTA);
  drawTriangle(vertices_cube, 4,0,7,MAGENTA);
	drawTriangle(vertices_cube, 0,3,1, BLUE);
	drawTriangle(vertices_cube, 1,3,2, BLUE);
	drawTriangle(vertices_cube, 4,7,5, BLUE);
	drawTriangle(vertices_cube, 5,7, 6, BLUE); 
	if(normDisplay == 1){
		printf("\n%f\n", verticesNorm[7].x);
		drawNorms();
	}
}
void Cube::drawNorms(){
		glColor3f(1.0, 1.0, 1.0);
		for(int i = 0; i < 8; i++){
			glBegin(GL_LINES);
					glVertex4f(vertices_cube[i].x, vertices_cube[i].y, vertices_cube[i].z, vertices_cube[i].w() );
					glVertex4f(verticesNorm[i].x, verticesNorm[i].y, verticesNorm[i].z, verticesNorm[i].w());
			glEnd();	
	}
}
void Cube::makeNorm(){
	for(int i = 0; i < 8; i++){
		verticesNorm[i].remake(vertices_cube[i].x*2,vertices_cube[i].y*2, vertices_cube[i].z*2);
	}
}
void Cube::make(){
	GLfloat multiplier = size/2;
	vertices_cube[0].remake(-1.0*multiplier, 1.0*multiplier, 1.0*multiplier); //{-1,1,1,1}
	vertices_cube[1].remake(1.0*multiplier, 1.0*multiplier, 1.0*multiplier); //{1,1,1,1}
	vertices_cube[2].remake(1.0*multiplier, 1.0*multiplier, -1.0*multiplier); //{1,1,-1,1}
	vertices_cube[3].remake(-1.0*multiplier, 1.0*multiplier, -1.0*multiplier);//{-1,1,-1,1},
  vertices_cube[4].remake(-1.0*multiplier, -1.0*multiplier, 1.0*multiplier);//{-1,-1,1,1}, 
	vertices_cube[5].remake(1.0*multiplier, -1.0*multiplier, 1.0*multiplier);//{1,-1,1,1}, 
	vertices_cube[6].remake(1.0*multiplier, -1.0*multiplier, -1.0*multiplier);//{1,-1,-1,1}, 
	vertices_cube[7].remake(-1.0*multiplier, -1.0*multiplier, -1.0*multiplier);//{-1,-1,-1,1}


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
	printf("renderer: %d", renderMode);
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

