#include<stdio.h>
#include "Vertex.h"

/*
Constructor--
Parameters: None

Use: For arrays / data structures to initialize at the start. Will set point to (0,0,0)
Use Vertex::remake(x,y,z) to remake to specified vertex.
*/
Vertex::Vertex(){
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

/*
Constructor--
Parameters: X, Y ,Z

Use: For creating your own vertex from the start.
*/
Vertex::Vertex(GLfloat initX, GLfloat initY, GLfloat initZ){
	x = initX; 
	y = initY; 
	z = initZ;
}
/*
Function--
Parameters: x,y,z

Use: Will reset all the points to the ones specified
*/
void Vertex::remake(GLfloat makeX, GLfloat makeY, GLfloat makeZ){
	x = makeX;
	y = makeY;
	z = makeZ;
}
GLfloat *Vertex::getVertex(){
	GLfloat * verts = new GLfloat[4];
	verts[0] = x;
	verts[1] = y;
	verts[2] = z;
	verts[3] = 1;	
	//printf("Vert 1: %f, 2: %f, 3: %f, 4: %f\n", verts[0], verts[1], verts[2], verts[3]);
	return verts;
}
