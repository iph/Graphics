#include "Shape.h"
#include "Vertex.h"
#include "Vect.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Shape::translate(float xpos, float ypos, float zpos, Vertex * v){
	v->x +=xpos;
	v->y += ypos;
	v->z += zpos;
}
void Shape::rotate(float deg, int x, int y, int z, Vertex * v){
	deg = deg*3.141592654/180;
	if(x == 1){
		GLfloat ypos = v->y;
		GLfloat zpos = v->z;
		v->y = ypos*cos(deg) - zpos*sin(deg);
		v->z = ypos*sin(deg) + zpos*cos(deg);
	}
	if(y == 1){
		GLfloat xpos = v->x;
		GLfloat zpos = v->z;
		v->x = xpos*cos(deg) - zpos*sin(deg);
		v->z = xpos*sin(deg) + zpos*cos(deg);
	}
	if(z == 1){
		GLfloat xpos = v->x;
		GLfloat ypos = v->y;
		v->x = xpos*cos(deg) - ypos*sin(deg); 
		v->y = xpos*sin(deg) + ypos*cos(deg);
	}
}

void Shape::scale(float xScale, float yScale, float zScale, Vertex * v){
	v->x *=xScale;
	v->y *=yScale;
	v->z *=zScale;
}



//Draws
void Shape::draw(){

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


float * Shape::intersect(Vertex p, Vect d, LITE * myLight, int numLight){
	Vertex dPoint(d.x, d.y, d.z);
	Vertex pSave(p.x, p.y, p.z);
	translate(-trans[0], -trans[1], -trans[2], &p);		
	scale(1/scal[0], 1/scal[1], 1/scal[2], &p);
	scale(1/scal[0], 1/scal[1], 1/scal[2], &dPoint);
	rotate(-rot[0], 1, 0 , 0, &p);
	rotate(-rot[1], 0, 1 , 0, &p);
	rotate(-rot[2], 0, 0 , 1, &p);

	rotate(-rot[0], 1, 0 , 0, &dPoint);
	rotate(-rot[1], 0, 1 , 0, &dPoint);
	rotate(-rot[2], 0, 0 , 1, &dPoint);


	

	d.x = dPoint.x;
	d.y = dPoint.y;
	d.z = dPoint.z;
 	d = *(Vect::unitVector(d));
	float intersectPoint = unitIntersect(p,d);	
	if(intersectPoint < 0){
		return 0;
	}
	else{ 

			//Create nUnit which is the normal of the unit sphere.
			Vertex nUnit((p.x+d.x*intersectPoint),(p.y+d.y*intersectPoint),(p.z+d.z*intersectPoint));
			Vertex pointTo(nUnit.x, nUnit.y, nUnit.z);
			//Transform back into world space.
			scale(1/scal[0], 1/scal[1], 1/scal[2], &nUnit);
			rotate(rot[0], 1, 0 , 0, &nUnit);
			rotate(rot[1], 0, 1 , 0, &nUnit);
			rotate(rot[2], 0, 0 , 1, &nUnit);
			scale(scal[0], scal[1], scal[2], &pointTo);
			rotate(rot[0], 1, 0 , 0, &pointTo);
			rotate(rot[1], 0, 1 , 0, &pointTo);
			rotate(rot[2], 0, 0 , 1, &pointTo);
			translate(trans[0], trans[1], trans[2], &pointTo);
			//Turn into vector.
			Vect * N = Vect::unitVector(*(new Vect(nUnit.x, nUnit.y, nUnit.z)));
			float * intensity = new float[3];
			intensity[0] = ka*amb[0];
			intensity[1] = ka*amb[1];
			intensity[2] = ka*amb[2];

			for(int i = 0; i < numLight; i++){
			Vertex light(myLight[i].pos[0],myLight[i].pos[1],myLight[i].pos[2]);
				Vect * L = Vect::unitVector(*(new Vect(pointTo, light)));
				//Dot product!
				float inflection= Vect::dotProduct(*N, *L);

				inflection *= kd;
				intensity[0] += (myLight[i].diff[0])*inflection*diff[0];
				intensity[1] += (myLight[i].diff[1])*inflection*diff[1];
				intensity[2] += (myLight[i].diff[2])*inflection*diff[2];
			}

			return intensity;
	}
}
float Shape::unitIntersect(Vertex p, Vect d){
	float a = Vect::dotProduct(d,d);
	float b = 2*Vect::dotProduct(p,d);
	float c = Vect::dotProduct(p,p) -1; 
	float tTest = (b*b)-(4*a*c);
	if(tTest < 0){
		return -1;
	}
	float t1,t2;
	t1 = (-b + sqrt(tTest))/(2*a);
	t2 = (-b - sqrt(tTest))/(2*a);
	if(t1 < 0){
		t1 = -1;
	}
	if(t2 < 0){
		t2 = -1;
	}
	float t = (t1 < t2)?t1:t2; //Min function
	return (t > 0) ? t : -1; //If t is less than 0, return 0 otherwise return t

}
	ostream& operator<<(ostream& output, const Shape &p){
		output<<"I am a " << p.name ;
		return output;
	}
