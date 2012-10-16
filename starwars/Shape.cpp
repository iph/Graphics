#include "Shape.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Sphere.h"
using namespace std;
void Shape::changeVertical(int newVS){
	if(newVS < 1){
		return;
	}
	//Deleting the array////////////
	for(int i = 0; i < rs; i++){
		delete []verts[i];
	}
	delete [] verts;

/////////////////////////////

//Creating new array///////////////
	vs = newVS;
	verts = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
	}
	make();

}

void Shape::makeFaces(){	
	for(int i= 0; i < rs-1; i++){
		for(int j = 0; j < vs-1; j++){
			faces[i*(rs-1)+j].remake(verts[(i+1)%rs][j],verts[(i+1)%rs][(j+1)%vs],verts[i][j],verts[i][(j+1)%vs]);
		}
	}



}
void Shape::changeRow(int newRS){

	if(newRS < 1){
		return;
	}
	//Deleting the array////////////
	for(int i = 0; i < rs; i++){
		delete []verts[i];
	}
	delete [] verts;
	/////////////////////////////

//Creating new array///////////////
	rs = newRS;
	verts = new Vertex*[rs];
	for(int i = 0; i < rs; i++){
		verts[i]=new Vertex[vs];
	}
	make();
}
void Shape::translate(float xpos, float ypos, float zpos, Vertex * v){
	v->x +=xpos;
	v->y += ypos;
	v->z += zpos;
}
void Shape::rotate(float deg, int x, int y, int z, Vertex * v){
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

void Shape::scale(float xScale, float yScale, float zScale, Vertex * v){
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
void Shape::translate(float xpos, float ypos, float zpos){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			verts[i][j].x += xpos;
			verts[i][j].y += ypos;
			verts[i][j].z += zpos;
		}
	}
	center.x +=xpos;
	center.y += ypos;
	center.z += zpos;

}
/****************************************
* Function: scale
* args: xScale-se
*	yScale-se
*	zScale-se
* Use: Will scale based on the inputs given
* Return: Nothing
**********************************************/
void Shape::scale(float xScale, float yScale, float zScale){
	cout << "SCALED1" << endl;

	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			verts[i][j].x *= xScale;
			verts[i][j].y *= yScale;
			verts[i][j].z *= zScale;

		}
	}
	center.x *=xScale;
	center.y *=yScale;
	center.z *=zScale;
}
/*****************************************
* Function: rotate
* Args: deg- degrees to rotate by
* 	x- to rotate about the x
*	y- to rotate about the y
*	z- to rotate about the z
* Return: Nothing
****************************************/
void Shape::rotate(float deg, int x, int y, int z){
	deg = deg*(float)PI/180.0f; 
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			if(x == 1){
				GLfloat ypos = verts[i][j].y;
				GLfloat zpos = verts[i][j].z;

				verts[i][j].y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
				verts[i][j].z = ypos*(float)sin(deg) + zpos*(float)cos(deg);


			}
			if(y == 1){
				GLfloat xpos = verts[i][j].x;
				GLfloat zpos = verts[i][j].z;
				verts[i][j].x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
				verts[i][j].z = xpos*(float)sin(deg) + zpos*(float)cos(deg);

	
			}
			if(z == 1){

				GLfloat xpos = verts[i][j].x;
				GLfloat ypos = verts[i][j].y;
				verts[i][j].x = xpos*(float)cos(deg) - ypos*(float)sin(deg); 
				verts[i][j].y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
	
			}
		}
	}
	if(x == 1){
		GLfloat ypos = center.y;
		GLfloat zpos = center.z;
		center.y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		center.z = ypos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(y == 1){
		GLfloat xpos = center.x;
		GLfloat zpos = center.z;
		center.x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		center.z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(z == 1){
		GLfloat xpos = center.x;
		GLfloat ypos = center.y;
		center.x = xpos*(float)cos(deg) - ypos*(float)sin(deg); 
		center.y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
	}
}

void Shape::axisRotate(float deg){
	Vertex centTemp(center.x, center.y, center.z);
	translate(-center.x, -center.y, -center.z);//Translate to origin
	Vertex origin(0,0,0);
	bool para = false;
	//Build movement matrix
	//axis = chooseAxis();
	Vect * ax = new Vect(origin, axis);
	Vect y(0.0f,1.0f,0.0f);
	Vect * v = Vect::unitVector(*ax);
	if(v->isParallel(y)){
		v->x += .0000000001f;
	}	
	Vect * u = Vect::unitVector(*(Vect::crossProduct(*v, y)));
	Vect * n = Vect::unitVector(*(Vect::crossProduct(*u, *v)));
	//Align the global axis to the local axis:
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			GLfloat x = verts[i][j].x;
			GLfloat y = verts[i][j].y;
			GLfloat z = verts[i][j].z;
			verts[i][j].x = u->x*x + u->y*y + u->z*z;
			verts[i][j].y = v->x*x + v->y*y + v->z*z;
			verts[i][j].z = n->x*x + n->y*y + n->z*z;
			x = vertsNorm[i][j].x;
			y = vertsNorm[i][j].y;
			z = vertsNorm[i][j].z;
			vertsNorm[i][j].x = u->x*x + u->y*y + u->z*z;
			vertsNorm[i][j].y = v->x*x + v->y*y + v->z*z;
			vertsNorm[i][j].z = n->x*x + n->y*y + n->z*z;
		}
	}
	//Rotate the amount needed.
	
	rotate(deg, 0, 1, 0);
	if(!para){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
			GLfloat x = verts[i][j].x;
			GLfloat y = verts[i][j].y;
			GLfloat z = verts[i][j].z;
			verts[i][j].x = u->x*x + v->x*y + n->x*z;
			verts[i][j].y = u->y*x + v->y*y + n->y*z;
			verts[i][j].z = u->z*x + v->z*y + n->z*z;
			x = vertsNorm[i][j].x;
			y = vertsNorm[i][j].y;
			z = vertsNorm[i][j].z;
			vertsNorm[i][j].x = u->x*x + v->x*y + n->x*z;
			vertsNorm[i][j].y = u->y*x + v->y*y + n->y*z;
			vertsNorm[i][j].z = u->z*x + v->z*y + n->z*z;

		}
	}
	}
	translate(centTemp.x, centTemp.y, centTemp.z);
}

void Shape::changeNormDisplay(int flag){
	normDisplay = flag;
}
void Shape::makeNorms(){

}
//Helper function
float Shape::length(Vertex *norm){
	return (float)sqrt(norm->x*norm->x+ norm->y*norm->y+ norm->z*norm->z);
}

//Helper function
void Shape::crossProduct( Vertex *cross, Vertex *p0, Vertex *p1, Vertex *p2){
	Vertex vUp(p1->x-p0->x, p1->y-p0->y, p1->x-p0->y);
	Vertex vSide(p2->x-p0->x, p2->y-p0->y, p2->x-p0->y);
	cross->remake((vUp.y*vSide.z-vUp.z*vSide.y), (-(vUp.x*vSide.z-vUp.z*vSide.x)), (vUp.x*vSide.y-vUp.y*vSide.x));
}


void Shape::drawNorms(){
	for(int i = 0; i < rs; i++){
		for(int j = 0; j < vs; j++){
				glColor3f((float)(1.0*i)/(float)rs,0.0f,((float)(rs*1.0-1.0*i)/(float)rs));
				vertsNorm[i][j].normalize();
				glBegin(GL_LINES);
						glVertex4f(verts[i][j].x, verts[i][j].y, verts[i][j].z, verts[i][j].w() );
						glVertex4f((verts[i][j].x+vertsNorm[i][j].x), (verts[i][j].y+vertsNorm[i][j].y),(verts[i][j].z+vertsNorm[i][j].z), vertsNorm[i][j].w());
				glEnd();	
		}
	}
		
}

//Changes render
void Shape::changeRender(int newRender){
	renderMode = newRender;
}

//Draws
void Shape::draw(){
	for(int i= 0; i < rs-1; i++){
		for(int j = 0; j < vs-1; j++){
		makeFaces();
		faces[i*(rs-1)+j].draw();			
		}
	}
	if(normDisplay ==1){
		drawNorms();
	}
}
GLfloat colors [][3] = {
  {0.0f, 0.0f, 0.0f},  /* black   */
  {0.6f, 0.6f, 0.6f},  /* red     */
  {1.0f, 1.0f, 0.0f},  /* yellow  */
  {1.0f, 0.0f, 1.0f},  /* magenta */
  {0.0f, 1.0f, 0.0f},  /* green   */
  {0.0f, 1.0f, 1.0f},  /* cyan    */
  {0.0f, 0.0f, 1.0f},  /* blue    */
  {0.5f, 0.5f, 0.5f},  /* 50%grey */
  {1.0f, 1.0f, 1.0f}   /* white   */
};
//Makes it so faces are faces
Shape::Shape(int rs, int vs, int colorMode){
	faces = new Face[(rs-1)*(vs-1)];
	//faceNum = (rs-1)*(vs-1);

	colorize(colorMode, rs, vs);
}
Shape::Shape(int rs, int vs, int colorMode, string l){
	faces = new Face[(rs-1)*(vs-1)];
	//faceNum = (rs-1)*(vs-1);

	colorize(colorMode, rs, vs);
	name = l;
}
/********************
Makes it so you can color individual shapes.
*/
void Shape::colorize(int colorMode, int rs, int vs){

			float r = 0;
			float g = 0;
			float b = 0;
	for(int i = 0; i < rs -1; i++){
		for(int j = 0; j < vs-1; j++){
			int rando = rand() % 50;	

			if(colorMode == 1){
				r = ((float)(109.0+rando)/255.0f);
				g = r;
				b = r;
			}
			else{
				int splitter;
				splitter = colorMode/100000;
				r = splitter/255.0f*i/(rs-1);
				//splitter = (colorMode/ 1000)%256;
				g = 1.0f*(rs-1-i)/(rs-1);
				b = (colorMode%256)/255.0f*i/(rs-1);
			}
			faces[i*(rs-1)+j].changeColor(r, g, b, 1);	
			if(colorMode == 1 && i > 25){
				faces[i*(rs-1)+j].changeColor(129.0f/255, 129.0f/255, 129.0f/255, 129.0f/255);	
				if(i > 26){
					faces[i*(rs-1)+j].changeColor(135.0f/255, 135.0f/255, 135.0f/255.0f, 1);	
				}
			}
		}
	}
/*
		if(colorMode == 1){
			for(int i = rs-1; i >((rs-5)%rs); i--){
				for(int j = 0; j < vs-1; j++){
					faces[i*(rs-1)+j].changeColor(.8, .8, .8, 1);	
				}
			}
		}
	*/
	
}
	ostream& operator<<(ostream& output, const Shape &p){
		output<<"I am a " << p.name ;
		return output;
	}
void Shape::pushIntersect(Vertex location, vector<Shape *> * intersections){
	scale(scal[0], scal[1], scal[2], &location);
	rotate(rot[0], 1, 0 , 0, &location);
	rotate(rot[1], 0, 1 , 0, &location);
	rotate(rot[2], 0, 0 , 1, &location);
	translate(trans[0], trans[1], trans[2], &location);

	Shape * a = new Sphere(.05f, 10, 10, GL_POLYGON, 200200200);
	a->translate(location.x, location.y, location.z);
	intersections->push_back(a);		

	
}
