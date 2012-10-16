#include "Shape.h"
#include "Vertex.h"
#include <stdio.h>
void Shape::changeVertical(int newVS){
	if(newVS < 1){
		return;
	}
	//Deleting the array////////////
	for(int i = 0; i < rs; i++){
		delete []verts[i];
	}
	delete [] verts;

/////////////////////////////

//Creating new array///////////////
	vs = newVS;
	verts = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
	}
	make();

}
void Shape::changeRow(int newRS){

	if(newRS < 1){
		return;
	}
	//Deleting the array////////////
	for(int i = 0; i < rs; i++){
		delete []verts[i];
	}
	delete [] verts;
	/////////////////////////////

//Creating new array///////////////
	rs = newRS;
	verts = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
	}
	make();
}

void Shape::changeNormDisplay(int flag){
	normDisplay = flag;
}
void Shape::makeNorms(){
	int i = 0;

	//Deletes old array.
	if(normDisplay == NULL){
		for(i = 0; i < rs; i++){
			delete []vertsNorm[i];
		}
			delete [] vertsNorm;
	}
	///////////////////////

	//Makes new array///////////////
	vertsNorm = new Vertex*[rs];
	for(i = 0; i < rs; i++){
		vertsNorm[i]=new Vertex[vs];
	}
	////////////////////////////////

	//Create average normal////////////////
	for(i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			Vertex cross;
/*		Doesn't fucking work.
			crossProduct(&cross, &verts[i][j+1], &verts[i+1][j+1], &verts[i][j]);
			vertsNorm[i][j].remake(vertsNorm[i][j].x+cross.x,vertsNorm[i][j].y+ cross.y, vertsNorm[i][j].z+ cross.z);
			vertsNorm[i+1][j].remake(vertsNorm[i+1][j].x+cross.x,vertsNorm[i+1][j].y+ cross.y, vertsNorm[i+1][j].z+ cross.z);
			vertsNorm[i][j+1].remake(vertsNorm[i][j+1].x+cross.x,vertsNorm[i][j+1].y+ cross.y, vertsNorm[i][j+1].z+ cross.z);
			vertsNorm[i+1][j+1].remake(vertsNorm[i+1][j+1].x+cross.x,vertsNorm[i+1][j+1].y+ cross.y, vertsNorm[i+1][j+1].z+ cross.z);*/
			vertsNorm[i][j].remake(verts[i][j].x*2.0, verts[i][j].y*2.0, verts[i][j].z*2.0);
		}
	}
/* Divide by length
	for(i = 0; i < rs-1; i++){
		for(int j = 0; j < vs-1; j++){
			float len = length(&vertsNorm[i][j]);
			vertsNorm[i][j].remake(vertsNorm[i][j].x/len,vertsNorm[i][j].y/len, vertsNorm[i][j].z/len);

		}
	}
*/
	
	
}

//Helper function
float Shape::length(Vertex *norm){
	return sqrt(norm->x*norm->x+ norm->y*norm->y+ norm->z*norm->z);
}

//Helper function
void Shape::crossProduct( Vertex *cross, Vertex *p0, Vertex *p1, Vertex *p2){
	Vertex vUp(p1->x-p0->x, p1->y-p0->y, p1->x-p0->y);
	Vertex vSide(p2->x-p0->x, p2->y-p0->y, p2->x-p0->y);
	cross->remake((vUp.y*vSide.z-vUp.z*vSide.y), (-(vUp.x*vSide.z-vUp.z*vSide.x)), (vUp.x*vSide.y-vUp.y*vSide.x));
}
void Shape::drawNorms(){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
				glColor3f((1.0*i)/rs,0,((rs*1.0-1.0*i)/rs));
				glBegin(GL_LINES);
						glVertex4f(verts[i][j].x, verts[i][j].y, verts[i][j].z, verts[i][j].w() );
						glVertex4f(vertsNorm[i][j].x, vertsNorm[i][j].y, vertsNorm[i][j].z, vertsNorm[i][j].w());
				glEnd();	
		}
	}
		
}
void Shape::changeRender(int newRender){
	renderMode = newRender;
}

void Shape::draw(){
	for(int i= 0; i < rs-1; i++){
		for(int j = 0; j < vs-1; j++){
	glColor3f((1.0*i)/rs,0,((rs*1.0-1.0*i)/rs));
	glBegin(renderMode);
			glVertex4fv(verts[i][j].getVertex());
			glVertex4fv(verts[(i+1)%rs][j].getVertex());
			glVertex4fv(verts[(i+1)%rs][(j+1)%vs].getVertex());
			glVertex4fv(verts[i][(j+1)%vs].getVertex());
	glEnd();			
		}
	}
	if(normDisplay ==1){
		makeNorms();
		drawNorms();
	}
}
GLfloat colors [][3] = {
  {0.0, 0.0, 0.0},  /* black   */
  {1.0, 0.0, 0.0},  /* red     */
  {1.0, 1.0, 0.0},  /* yellow  */
  {1.0, 0.0, 1.0},  /* magenta */
  {0.0, 1.0, 0.0},  /* green   */
  {0.0, 1.0, 1.0},  /* cyan    */
  {0.0, 0.0, 1.0},  /* blue    */
  {0.5, 0.5, 0.5},  /* 50%grey */
  {1.0, 1.0, 1.0}   /* white   */
};
Shape::Shape(){

}

