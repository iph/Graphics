#include "Sphere.h"
#include<stdio.h>
#include<string>
#include<math.h>
 Sphere::Sphere(float r, int rs_i, int vs_i, int render, int color)
:Shape(rs_i,vs_i, color, "Sphere"){
	center.remake(0,0,0);
	vertsNorm = 0;
	normDisplay = 0;
	radius = r;
	rs = rs_i;
	vs = vs_i;
	renderMode = render;
	verts = new Vertex*[rs];
	vertsNorm = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
		vertsNorm[i]=new Vertex[vs];
	}
	make();
	makeNorms();

}
Sphere::Sphere(float r, int rs_i, int vs_i, int render)
:Shape(rs_i,vs_i, 1, "Sphere"){
	center.remake(0,0,0);
	vertsNorm = 0;
	normDisplay = 0;
	radius = r;
	rs = rs_i;
	vs = vs_i;
	renderMode = render;
	verts = new Vertex*[rs];
	vertsNorm = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
		vertsNorm[i]=new Vertex[vs];
	}
	make();
	makeNorms();
}
void Sphere::makeNorms(){
	int i = 0;
	if(normDisplay == 0){
		for(i = 0; i < rs; i++){
			delete []vertsNorm[i];
		}
			delete [] vertsNorm;
	}
	vertsNorm = new Vertex*[rs];
	for(i = 0; i < rs; i++){
		vertsNorm[i]=new Vertex[vs];
	}
	for(i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			vertsNorm[i][j].remake(verts[i][j].x*2.0, verts[i][j].y*2.0, verts[i][j].z*2.0);
			vertsNorm[i][j].normalize();
		}
	}
}
void Sphere::make(){
	for(int i = 0; i < rs; i++)
	{
		float theta = PI/(rs-1)*i - PI/2;
		for(int j = 0; j < vs; j++)
		{
			float alpha = 2*PI/(vs-1)*j;
			verts[i][j].remake(radius*cos(theta)*cos(alpha), radius*sin(theta), -radius*cos(theta)*sin(alpha));

		}
	}
}

bool Sphere::intersect(Vertex p, Vect d, vector<Shape *> * intersects){
	Vertex dPoint(d.x, d.y, d.z);
	translate(-trans[0], -trans[1], -trans[2], &p);		
	rotate(-rot[2], 0, 0 , 1, &p);
	rotate(-rot[1], 0, 1 , 0, &p);
	rotate(-rot[0], 1, 0 , 0, &p);

	rotate(-rot[2], 0, 0 , 1, &dPoint);
	rotate(-rot[1], 0, 1 , 0, &dPoint);
	rotate(-rot[0], 1, 0 , 0, &dPoint);
	
	scale(1/scal[0], 1/scal[1], 1/scal[2], &p);
	scale(1/scal[0], 1/scal[1], 1/scal[2], &dPoint);

	d.x = dPoint.x;
	d.y = dPoint.y;
	d.z = dPoint.z;

	//Vect * newD = Vect::unitVector(d);
		
	return intersectUnit(p,d, intersects);	
}
bool Sphere::intersectUnit(Vertex p, Vect d, vector<Shape *> * intersects){
	Vect * dp = Vect::unitVector(d);
	float a = Vect::dotProduct(*dp,*dp);
	float b = 2*Vect::dotProduct(p,*dp);
	float c = Vect::dotProduct(p,p) -1; 
	float tTest = b*b-4*a*c;
	if(tTest < 0){
		cout << "WHAT?"<<endl;
		return false;
	}
	float t1,t2;
	t1 = (-b + sqrt(tTest))/(2*a);
	t2 = (-b - sqrt(tTest))/(2*a);
	if(t1 >= 0){
		Vertex nay((p.x+t1*dp->x), (p.y+t1*dp->y), (p.z+t1*dp->z));
		pushIntersect(nay, intersects);
	}
	if(t2 >= 0){
		cout << "NEW INTERSECT" << endl;
		Vertex nay((p.x+t2*dp->x), (p.y+t2*dp->y), (p.z+t2*dp->z));
		pushIntersect(nay, intersects);
	}
	return true;
}
