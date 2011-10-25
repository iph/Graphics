#include "Shape.h"
#include "Vertex.h"
#include <stdio.h>
#include <iostream>

using namespace std;
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
/**************************************************
* Function: Translate
* args: xpos- se
*	ypos- se
*	zpos- se
* Use: will translate the real vertices the positions input
* Return: Nothing
***************************************************/
void Shape::translate(float xpos, float ypos, float zpos){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			verts[i][j].x += xpos;
			verts[i][j].y += ypos;
			verts[i][j].z += zpos;
			vertsNorm[i][j].x += xpos;
			vertsNorm[i][j].z += zpos;
			vertsNorm[i][j].y += ypos;
		}
	}
	center.x +=xpos;
	center.y += ypos;
	center.z += zpos;

}
/****************************************
* Function: scale
* args: xScale-se
*	yScale-se
*	zScale-se
* Use: Will scale based on the inputs given
* Return: Nothing
**********************************************/
void Shape::scale(float xScale, float yScale, float zScale){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			verts[i][j].x *= xScale;
			verts[i][j].y *= yScale;
			verts[i][j].z *= zScale;
			vertsNorm[i][j].x *= 1/xScale;
			vertsNorm[i][j].y *= 1/yScale;
			vertsNorm[i][j].z *= 1/zScale;
		}
	}
	center.x *=xScale;
	center.y *=yScale;
	center.z *=zScale;
}
/*****************************************
* Function: rotate
* Args: deg- degrees to rotate by
* 	x- to rotate about the x
*	y- to rotate about the y
*	z- to rotate about the z
* Return: Nothing
****************************************/
void Shape::rotate(float deg, int x, int y, int z){
	deg = deg*PI/180; 
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			if(x == 1){
				GLfloat ypos = verts[i][j].y;
				GLfloat zpos = verts[i][j].z;
				GLfloat yposn = vertsNorm[i][j].y;
				GLfloat zposn = vertsNorm[i][j].z;
				verts[i][j].y = ypos*cos(deg) - zpos*sin(deg);
				verts[i][j].z = ypos*sin(deg) + zpos*cos(deg);
				vertsNorm[i][j].y = yposn*cos(deg) - zposn*sin(deg);
				vertsNorm[i][j].z = yposn*sin(deg) + zposn*cos(deg);

			}
			if(y == 1){
				GLfloat xpos = verts[i][j].x;
				GLfloat zpos = verts[i][j].z;
				verts[i][j].x = xpos*cos(deg) - zpos*sin(deg);
				verts[i][j].z = xpos*sin(deg) + zpos*cos(deg);
				xpos = vertsNorm[i][j].x;
				zpos = vertsNorm[i][j].z;
				vertsNorm[i][j].x = xpos*cos(deg) - zpos*sin(deg);
				vertsNorm[i][j].z = xpos*sin(deg) + zpos*cos(deg);
	
			}
			if(z == 1){

				GLfloat xpos = verts[i][j].x;
				GLfloat ypos = verts[i][j].y;
				verts[i][j].x = xpos*cos(deg) - ypos*sin(deg); 
				verts[i][j].y = xpos*sin(deg) + ypos*cos(deg);
				xpos = vertsNorm[i][j].x;
				ypos = vertsNorm[i][j].y;
				vertsNorm[i][j].x = xpos*cos(deg) - ypos*sin(deg); 
				vertsNorm[i][j].y = xpos*sin(deg) + ypos*cos(deg);
	
			}
		}
	}
	if(x == 1){
		GLfloat ypos = center.y;
		GLfloat zpos = center.z;
		center.y = ypos*cos(deg) - zpos*sin(deg);
		center.z = ypos*sin(deg) + zpos*cos(deg);
	}
	if(y == 1){
		GLfloat xpos = center.x;
		GLfloat zpos = center.z;
		center.x = xpos*cos(deg) - zpos*sin(deg);
		center.z = xpos*sin(deg) + zpos*cos(deg);
	}
	if(z == 1){
		GLfloat xpos = center.x;
		GLfloat ypos = center.y;
		center.x = xpos*cos(deg) - ypos*sin(deg); 
		center.y = xpos*sin(deg) + ypos*cos(deg);
	}
}

void Shape::axisRotate(float deg){
	Vertex centTemp(center.x, center.y, center.z);
	translate(-center.x, -center.y, -center.z);//Translate to origin
	Vertex origin(0,0,0);
	bool para = false;
	//Build movement matrix
	axis = chooseAxis();
	Vect * ax = new Vect(origin, axis);
	Vect y(0,1.0, 0);
	Vect * v = Vect::unitVector(*ax);
	if(v->isParallel(y)){
		v->x += .0000000001;
	}	
	Vect * u = Vect::unitVector(*(Vect::crossProduct(*v, y)));
	Vect * n = Vect::unitVector(*(Vect::crossProduct(*u, *v)));
	//cout<< *ax << endl;
	//cout << *v << "and length " <<v->length() << endl;
	//cout << *u << "and length " <<u->length() <<  endl;
	//cout << *n << "and length " <<n->length() <<  endl;
	//Align the global axis to the local axis:
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			GLfloat x = verts[i][j].x;
			GLfloat y = verts[i][j].y;
			GLfloat z = verts[i][j].z;
			verts[i][j].x = u->x*x + u->y*y + u->z*z;
			verts[i][j].y = v->x*x + v->y*y + v->z*z;
			verts[i][j].z = n->x*x + n->y*y + n->z*z;
			x = vertsNorm[i][j].x;
			y = vertsNorm[i][j].y;
			z = vertsNorm[i][j].z;
			vertsNorm[i][j].x = u->x*x + u->y*y + u->z*z;
			vertsNorm[i][j].y = v->x*x + v->y*y + v->z*z;
			vertsNorm[i][j].z = n->x*x + n->y*y + n->z*z;
		}
	}
	//Rotate the amount needed.
	
	rotate(deg, 0, 1, 0);
	if(!para){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			GLfloat x = verts[i][j].x;
			GLfloat y = verts[i][j].y;
			GLfloat z = verts[i][j].z;
			verts[i][j].x = u->x*x + v->x*y + n->x*z;
			verts[i][j].y = u->y*x + v->y*y + n->y*z;
			verts[i][j].z = u->z*x + v->z*y + n->z*z;
			x = vertsNorm[i][j].x;
			y = vertsNorm[i][j].y;
			z = vertsNorm[i][j].z;
			vertsNorm[i][j].x = u->x*x + v->x*y + n->x*z;
			vertsNorm[i][j].y = u->y*x + v->y*y + n->y*z;
			vertsNorm[i][j].z = u->z*x + v->z*y + n->z*z;

		}
	}
	}
	translate(centTemp.x, centTemp.y, centTemp.z);
}
Vertex Shape::chooseAxis(){
	//Use to choose axis in each shape.
	return verts[rs-1][vs-1];
}
void Shape::changeNormDisplay(int flag){
	normDisplay = flag;
}
void Shape::makeNorms(){
	//Create average normal///////////////
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			vertsNorm[i][j].remake(verts[i][j].x*2, verts[i][j].y*2, verts[i][j].z*2);
			//vertsNorm[i][j].normalize();
		}
	}
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
//		makeNorms();
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

