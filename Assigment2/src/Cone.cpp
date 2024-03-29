#include "Cone.h"
#include<math.h>
Cone::Cone(float r, float h, int rs_i, int vs_i, int render){
	normDisplay = 0;
	radius = r;
	height = h;
	rs = rs_i;
	vs = vs_i;
	renderMode = render;
	verts = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
	}
	make();
}

void Cone::make(){
	for(int i = 0; i < rs; i++)
	{
		float theta = 1.0/(rs-1)*i;
		for(int j = 0; j < vs; j++)
		{
			float alpha = 2*PI/(vs-1)*j;
			verts[i][j].remake(radius*cos(alpha)*(1.0-theta),height*theta,-radius*sin(alpha)*(1.0-theta));

		}
	}

}


