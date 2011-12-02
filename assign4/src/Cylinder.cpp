#include "Cylinder.h"
#include<math.h>
Cylinder::Cylinder(float r, float h, int rs_i, int vs_i, int render)
:Shape(rs_i, vs_i, 156040){
	center.remake(0,0,0);
	normDisplay = 0;
	radius = r;
	height = h;
	rs = rs_i;
	vs = vs_i;
	renderMode = render;
	verts = new Vertex *[rs];
	vertsNorm = new Vertex *[rs];
	for(int i = 0; i < rs; i++){
		verts[i] = new Vertex[vs];
		vertsNorm[i] = new Vertex[vs];
	}
	make();
	makeNorms();
}

void Cylinder::make(){
	for(int i = 0; i < rs; i++)
	{

		for(int j = 0; j < vs; j++)
		{
		float theta = 2*PI*j/(vs-1);
			float alpha = height*i/(rs-1);
			verts[i][j].remake(radius*sin(theta), (-height/2+alpha), radius*cos(theta));

		}
	}

}
void Cylinder::makeNorms(){
	
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			vertsNorm[i][j].remake(verts[i][j].x*2, 0, verts[i][j].z*2);
			vertsNorm[i][j].normalize();
		}
	}
}
bool Cylinder::intersect(Vertex p, Vect d, vector <Shape *> * intersects){
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
		
	return unitIntersect(p,d, intersects);	



}	
bool Cylinder::unitIntersect(Vertex p, Vect d, vector <Shape *> * intersects){
	Vect * dp = Vect::unitVector(d);
	float a = dp->x*dp->x+dp->z*dp->z;
	float b = 2*(p.x*dp->x+p.z*dp->z);
	float c = p.x*p.x+p.z*p.z-1;
	float tTest = b*b-4*a*c;
	if(tTest < 0){
		cout << "WHAT?"<<endl;
		return false;
	}
	float t1,t2;
	t1 = (-b + sqrt(tTest))/(2*a);
	t2 = (-b - sqrt(tTest))/(2*a);
	Vertex nay((p.x+t1*dp->x), (p.y+t1*dp->y), (p.z+t1*dp->z));

	if(t1 >= 0 && (nay.y >= -.5 && nay.y <= .5)){
		pushIntersect(nay, intersects);
	}
	Vertex nay2((p.x+t2*dp->x), (p.y+t2*dp->y), (p.z+t2*dp->z));
	if(t2 >= 0&& (nay2.y>=-.5 && nay2.y <= .5)){
		pushIntersect(nay2, intersects);
	}
	return true;

}	
