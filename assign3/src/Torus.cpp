#include "Torus.h"
#include<math.h>
Torus::Torus(float r, float r2, int rs_i, int vs_i, int render)
:Shape(rs_i,vs_i, 104240065){
	center.remake(0,0,0);
	radius1 = r;
	radius2 = r2;
	rs = rs_i;
	normDisplay = 0;
	vs = vs_i;
	renderMode = render;
	verts = new Vertex*[rs];
	vertsNorm = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
		vertsNorm[i] = new Vertex[vs];
	}
	make();
	makeNorms();
}
void Torus::draw(){
	for(int j = 0; j < vs-1; j++){
		for(int i= 0; i < rs-1; i++){

	glColor3f((1.0*i)/rs,0,((rs*1.0-1.0*i)/rs));
	glBegin(renderMode);
			glVertex4fv(verts[i][j].getVertex());
			glVertex4fv(verts[(i+1)%rs][j].getVertex());
			glVertex4fv(verts[(i+1)%rs][(j+1)%vs].getVertex());
			glVertex4fv(verts[i][(j+1)%vs].getVertex());
	glEnd();			
		}
	}
	if(normDisplay == 1){
		makeNorms();
		drawNorms();
	}
}
void Torus::make(){
	for(int i = 0; i < rs; i++)
	{

		for(int j = 0; j < vs; j++)
		{
		float theta = 2*PI/(rs-1)*i;
			float alpha = 2*PI/(vs-1)*j;
			verts[i][j].remake((radius1*cos(theta)+radius2)*cos(alpha),radius1*sin(theta),-(radius1*cos(theta)+radius2)*sin(alpha));

		}
	}

}


