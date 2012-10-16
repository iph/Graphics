#include "Cube.h"
Cube::Cube(int renderModeInit, int initsize): Shape(1,8,1){
	center.remake(0,0,0);
	renderMode = renderModeInit;
	size = initsize;
	rs = 1;
	vs = 8;
	//faceNum = 6;
	//faces = new Face[6];
	rects = new Rectangle[6];

	make();
}
void Cube::draw(){
	for(int i = 0; i < 6; i++){
		rects[i].draw();
	}
}

void Cube::makeNorm(){

}
void Cube::make(){
	GLfloat multiplier = size;

	//Front face
	rects[0].setScale(size, size, size);
	rects[0].setRotate(0,0,0);
	rects[0].setTranslate(0,0,.5);
	//Back face
	rects[1].setScale(size, size, size);
	rects[1].setRotate(0,0,0);
	rects[1].setTranslate(0,0,-.5);

	//Left face
	rects[2].setScale(size, size, size);
	rects[2].setRotate(0,90,0);
	rects[2].setTranslate(.5,0,0);

	//Right face
	rects[3].setScale(size, size, size);
	rects[3].setRotate(0,-90,0);
	rects[3].setTranslate(-.5,0,0);

	//Top face
	rects[4].setScale(size, size, size);
	rects[4].setRotate(90,0,0);
	rects[4].setTranslate(0,.5,0);

	//Bottom face
	rects[5].setScale(size, size, size);
	rects[5].setRotate(90,0,0);
	rects[5].setTranslate(0,-.5,0);
}

void Cube::translate(float xpos, float ypos, float zpos){
	for(int i = 0; i < 6; i++){
//		rects[i].translate(xpos,ypos,zpos);
		rects[i].trans[0] = rects[i].trans[0]+xpos;
		rects[i].trans[1] = rects[i].trans[1]+ypos;
		rects[i].trans[2] = rects[i].trans[2]+zpos;
	}
}
void Cube::rotate(float deg, int x, int y, int z){
	for(int i = 0; i < 6; i++){
	//	rects[i].rotate(deg,x,y,z);
		rects[i].rot[0] = rects[i].rot[0]+x;
		rects[i].rot[1] = rects[i].rot[1]+y;
		rects[i].rot[2] = rects[i].rot[2]+z;
	}
}
void Cube::scale(float xScale, float yScale, float zScale){
	for(int i = 0; i < 6; i++){
		//rects[i].scale(xScale,yScale,zScale);
		rects[i].scal[0] = rects[i].scal[0]*xScale;
		rects[i].scal[1] = rects[i].scal[1]*yScale;
		rects[i].scal[2] = rects[i].scal[2]*zScale;
	}
}
void Cube::translate(float xpos, float ypos, float zpos, Vertex * v){
	v->x +=xpos;
	v->y += ypos;
	v->z += zpos;
}
void Cube::rotate(float deg, int x, int y, int z, Vertex * v){
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
void Cube::setTexture(unsigned t){
	for(int i = 0; i < 6; i++){
		rects[i].setTexture(t);
	}
}
void Cube::scale(float xScale, float yScale, float zScale, Vertex * v){
	v->x *=xScale;
	v->y *=yScale;
	v->z *=zScale;
}

bool Cube::intersect(Vertex p, Vect d, vector<Shape *> * intersects){
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
bool Cube::intersectUnit(Vertex p, Vect d, vector<Shape *> * intersects){
	float t;
	Vertex result;
	
	if(d.x != 0){
		t = (-.5f-p.x)/d.x;
		if(t >= 0){
			result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
			if(result.y <= .5 && result.y >= -.5 && result.z <= .5 && result.z >=-.5){
			//pushIntersect(result,intersects);
		}
	}
		t = (.5f-p.x)/d.x;
		if(t >= 0){
			result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
			if(result.y <= .5 && result.y >= -.5 && result.z <= .5 && result.z >=-.5){
			//pushIntersect(result, intersects);
		}
	}


	}
	if(d.y != 0){
		t = (-.5f-p.y)/d.y;
		if(t >= 0){
			result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
			if(result.x <= .5 && result.x >= -.5 && result.z <= .5 && result.z >=-.5){
			//pushIntersect(result, intersects);
		}
	}
		t = (.5f-p.y)/d.y;
		if(t >= 0){
			result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
			if(result.x <= .5 && result.x >= -.5 && result.z <= .5 && result.z >=-.5){
			//pushIntersect(result, intersects);
		}
	}
	}

	if(d.z != 0){
			t = (-.5f-p.z)/d.z;
			if(t>= 0){

				result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
				if(result.x <= .5 && result.x >= -.5 && result.y <= .5 && result.y >=-.5){
					return true;
				}
			}
			t = (.5f-p.z)/d.z;
			if(t >= 0){
				result.remake((p.x+d.x*t), (p.y+d.y*t), (p.z+d.z*t));
				if(result.x <= .5 && result.x >= -.5 && result.y <= .5 && result.y >=-.5){
					return true;
					//pushIntersect(result, intersects);
				}

			}
	}


	return false;
}
