/***************************************************
FILE: stitcher.h
AUTHOR: gem, loosely based on hwa random skel
DATE: 01/24/08
DOES: header file for cs1566 Assignment 2 -- stitcher
PLATFORM: tested on osx, linux, and vs
***************************************************/

/**********
notes:
VS users: include gl/glut.h below instead of glut.h
OSX users: include glut/glut.h below instead of glut.j
**********/

#include "Face.h"
#include <stdlib.h>
#define _USE_MATH_DEFINES //cause vs is dumb :-(
#include <math.h>
#include "Vertex.h"
#include "Vect.h"
#include<vector>
#ifndef min //In VC++ 2008, Ryan got a warning about min redefinition, so let's not redefine it if something else already did; sigh
#define min(a,b) ((a) < (b)? a:b)
#endif
#ifndef __SHAPES_HEADER__
#define __SHAPES_HEADER__
#define BLACK   0
#define RED     1
#define YELLOW  2
#define MAGENTA 3
#define GREEN   4
#define CYAN    5
#define BLUE    6
#define GREY    7
#define WHITE   8
#define FALSE 0 
#define TRUE  1
#define MAX_RS 50
#define MAX_VS 50
#define PI 3.141592654
using namespace std;
extern GLfloat colors[][3];
class Shape{
	//friend ostream& operator<<(ostream& output, const Vect& p);
public:
	Shape(){};
	~Shape(){};
	Shape(int rs, int vs, int colorMode);
	Shape(int rs, int vs, int colorMode, string n);
	virtual void draw();
	virtual void make(){};
	virtual bool intersect(Vertex p, Vect d, vector <Shape *> * f){return false;};
	string name;
	//int faceNum;
	Vertex **verts;
	Vertex **vertsNorm;
	Vertex center;
	Vertex axis; 
	Face * faces;
	GLfloat shine;
	GLfloat emi[4];
	GLfloat amb[4];
	GLfloat diff[4];
	GLfloat spec[4];
	GLfloat trans[4];
	GLfloat rot[4];
	GLfloat scal[4];	
	void changeNormDisplay(int flag);
	virtual void makeFaces();
	virtual void translate(float xpos, float ypos, float zpos);
	virtual void rotate(float deg, int x, int y, int z);
	virtual void scale(float xScale, float yScale, float zScale);
	virtual void translate(float xpos, float ypos, float zpos, Vertex * v);
	virtual void rotate(float deg, int x, int y, int z, Vertex * v);
	virtual void scale(float xScale, float yScale, float zScale, Vertex * v);
	virtual void setTexture(unsigned int t){};
	int getNormDisplay(){ return normDisplay;};
	void axisRotate(float deg);
	void changeVertical(int newVS);
	void changeRow(int newRS);
	void changeRender(int newMode);
	void crossProduct( Vertex *cross,Vertex *p0, Vertex *p1, Vertex *p2);
	virtual bool isInside(Vertex p, Vect d){return false;};
	int getVS(){ return vs;};
	int getRS(){ return rs; };
	void pushIntersect(Vertex location, vector<Shape *> * intersections);
	int renderMode;
	float length(Vertex * norm);
protected:
	virtual void makeNorms();
	virtual void drawNorms();
	int rs;
	void colorize(int colorMode, int rs, int vs);
	int vs;
	int normDisplay;
};
#endif
