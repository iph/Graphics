#include "Sphere.h"
#include<stdio.h>
#include<math.h>
Sphere::Sphere(float r, int rs_i, int vs_i, int render){
	vertsNorm = 0;
	normDisplay = 0;
	radius = r;
	rs = rs_i;
	vs = vs_i;
	renderMode = render;
	verts = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
	}
	make();
}
void Sphere::makeNorms(){
	int i = 0;
	if(normDisplay == NULL){
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

