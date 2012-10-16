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

