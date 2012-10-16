#include "Rectangle.h"
#include<stdio.h>
#include<string>
#include<math.h>
Rectangle::Rectangle(){
	center.remake(0,0,0);
	normDisplay = 0;
	rs = 4;
	vs = 4;
	//faceNum = (rs-1)*(vs-1);
	verts = new Vertex*[rs+1];
	faces = new Face[(rs+1)*(vs+1)];

	for(int i = 0; i < rs+1; i++){
		verts[i]=new Vertex[vs+1];
	}
	make();
	makeFaces();
	setTexture(0);

}
void Rectangle::remake(int rs_i, int vs_i, unsigned t){
	center.remake(0,0,0);
	normDisplay = 0;
	rs = rs_i;
	vs = vs_i;
	if(faces != 0){
		delete[] faces;
	}
	if(verts !=0){
		for(int i = 0; i < rs+1; i++){
			delete[] verts[i];
		}
		delete[] verts;
	}
	//faceNum = (rs-1)*(vs-1);
	verts = new Vertex*[rs+1];
	faces = new Face[(rs+1)*(vs+1)];
	for(int i = 0; i < rs+1; i++){
		verts[i]=new Vertex[vs+1];
	}
	make();
	makeFaces();
	setTexture(t);
}
void Rectangle::setTranslate(float x, float y, float z){
	trans[0] = x;
	trans[1] = y;
	trans[2] = z;
	translate(x,y,z);
}
void Rectangle::setRotate(float x, float y, float z){
	scal[0] = x;
	scal[1] = y;
	scal[2] = z;
	scale(x,y,z);
}
void Rectangle::setScale(float x, float y, float z){
	rot[0] = x;
	rot[1] = y;
	rot[2] = z;
	rotate(rot[0], 1, 0, 0);
	rotate(rot[1], 0, 1, 0);
	rotate(rot[1], 0, 0, 1);

}
Rectangle::Rectangle(int rs_i, int vs_i, unsigned t){
	center.remake(0,0,0);
	normDisplay = 0;
	rs = rs_i;
	vs = vs_i;
	//faceNum = (rs-1)*(vs-1);
	verts = new Vertex*[rs+1];
	faces = new Face[(rs+1)*(vs+1)];

	for(int i = 0; i < rs+1; i++){
		verts[i]=new Vertex[vs+1];
	}
	make();
	makeFaces();
	setTexture(t);

}
void Rectangle::draw(){
	for(int i= 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
		makeFaces();
		//cout << faces[i*(rs)+j].bottomLeft << endl;
		faces[i*(rs)+j].draw();
		}
	}
}
void Rectangle::makeFaces(){
	for(int i= 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			faces[i*(rs)+j].remake(verts[(i+1)%(rs+1)][j],verts[(i+1)%(rs+1)][(j+1)%(vs+1)],verts[i][j],verts[i][(j+1)%(vs+1)]);
		}
	}
}
void Rectangle::make(){
    float row = -.5f;
    float col = -.5f;
	for(int i = 0; i < rs+1; i++)
	{
        row = -.5f;

		for(int j = 0; j < vs+1; j++)
		{
			verts[i][j].remake(col, row, 0);
            row += 1.0f/vs;
		}
        col += 1.0f/rs;
	}
	makeFaces();
}
void Rectangle::translate(float xpos, float ypos, float zpos, Vertex * v){
	v->x +=xpos;
	v->y += ypos;
	v->z += zpos;
}
void Rectangle::rotate(float deg, int x, int y, int z, Vertex * v){
	deg = deg*3.141592654f/180.0f;
	if(x == 1){
		GLfloat ypos = v->y;
		GLfloat zpos = v->z;
		v->y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		v->z = ypos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(y == 1){
		GLfloat xpos = v->x;
		GLfloat zpos = v->z;
		v->x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		v->z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(z == 1){
		GLfloat xpos = v->x;
		GLfloat ypos = v->y;
		v->x = xpos*(float)cos(deg) - ypos*(float)sin(deg);
		v->y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
	}
}

void Rectangle::scale(float xScale, float yScale, float zScale, Vertex * v){
	v->x *=xScale;
	v->y *=yScale;
	v->z *=zScale;
}
/**************************************************
* Function: Translate
* args: xpos- se
*	ypos- se
*	zpos- se
* Use: will translate the real vertices the positions input
* Return: Nothing
***************************************************/
void Rectangle::translate(float xpos, float ypos, float zpos){
	for(int i = 0; i < rs+1; i++){
		for(int j = 0; j < vs+1; j++){
			translate(xpos, ypos, zpos, &verts[i][j]);
		}
	}
	translate(xpos, ypos, zpos, &center);


}
/****************************************
* Function: scale
* args: xScale-se
*	yScale-se
*	zScale-se
* Use: Will scale based on the inputs given
* Return: Nothing
**********************************************/
void Rectangle::scale(float xScale, float yScale, float zScale){
	cout << "SCALED" << endl;
	for(int i = 0; i < rs+1; i++){
		for(int j = 0; j < vs+1; j++){
			scale(xScale, yScale, zScale, &verts[i][j]);
		}
	}
	scale(xScale, yScale, zScale, &center);

}
/*****************************************
* Function: rotate
* Args: deg- degrees to rotate by
* 	x- to rotate about the x
*	y- to rotate about the y
*	z- to rotate about the z
* Return: Nothing
****************************************/
void Rectangle::rotate(float deg, int x, int y, int z){
	for(int i = 0; i < rs+1; i++){
		for(int j = 0; j < vs+1; j++){
			rotate(deg,x,y,z,&verts[i][j]);
		}
	}
	rotate(deg,x,y,z,&center);
}



bool Rectangle::intersect(Vertex p, Vect d, vector<Shape *> * intersects){
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
    
	Vect * newD = Vect::unitVector(d);
    
	return intersectUnit(p,*newD, intersects);
}
bool Rectangle::intersectUnit(Vertex p, Vect d, vector<Shape *> * intersects){
	float t;
    Vertex result;
	if(d.z != 0){
			t = (-p.z)/d.z;
			if(t>= 0){

				result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
				cout << result << endl;
				if(result.x <= .5 && result.x >= -.5 && result.y <= .5 && result.y >=-.5){
					return true;
				}
			}
	}
	return false;
}
void Rectangle::setTexture(unsigned int t){
	cout << "RS: " << rs<< " VS: " << vs << endl;
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			faces[i*(rs)+j].setTexture(t);
		}
	}
}
