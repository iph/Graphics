#include "Vect.h"
#include "Vertex.h"
#include <math.h>
#define ABS(a) (((a) < 0)?-(a):(a))
Vect::Vect(Vertex a, Vertex b){
//	float epsilon = .000001;
	x = b.x - a.x;
	y = b.y - a.y;
	z = b.z - a.z;
	
}
bool Vect::isParallel(Vect a){
		float epsilon = .000001f;
		if(((x-a.x) < epsilon && (y-a.y) < epsilon && (z-a.z)<epsilon)|| (ABS(x+a.x) < epsilon && ABS(y+a.y) < epsilon && ABS(z+a.z)<epsilon)  ){
			return true;
		}
		else{
			return false;
		}
	}
Vect::Vect(float _x, float _y, float _z ){
//	float epsilon = .000001;

		x = _x;
	

		y = _y;
	

		z = _z;
}

Vect::Vect(){
	x = 0;
	y = 0;
	z = 0;
}

ostream& operator<<(ostream& output, const Vect &p){
	output << "{" << p.x << ", " << p.y << ", " << p.z << "}";
	return output;
}

float Vect::length(){
	return (float)sqrt(x*x+y*y+z*z);
}

Vect * Vect::unitVector(Vect a){
	float l = a.length();
	return new Vect(a.x/l, a.y/l, a.z/l);
}

Vect * Vect::crossProduct(Vect a, Vect b){
	GLfloat x = a.y*b.z - a.z*b.y;
	GLfloat y = -(a.x*b.z - a.z*b.x);
	GLfloat z = a.x*b.y - a.y*b.x;

	return new Vect(x,y,z);
}
float Vect::dotProduct(Vect a, Vect b){
	float temp = a.x*b.x;
	temp += a.y*b.y;
	temp += a.z*b.z;
	return temp;
}
float Vect::dotProduct(Vertex a, Vect b){
	float temp = a.x*b.x;
	temp += a.y*b.y;
	temp += a.z*b.z;
	return temp;
}
float Vect::dotProduct(Vertex a, Vertex b){
	float temp = a.x*b.x;
	temp += a.y*b.y;
	temp += a.z*b.z;
	return temp;
}
float Vect::dotProduct(Vect a, Vertex b){
	float temp = a.x*b.x;
	temp += a.y*b.y;
	temp += a.z*b.z;
	return temp;
}
	
