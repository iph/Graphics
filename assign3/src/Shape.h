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


#include <stdlib.h>
#define _USE_MATH_DEFINES //cause vs is dumb :-(
#include <math.h>
#include <glut.h>
#include "Vertex.h"
#include "Vect.h"
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

extern GLfloat colors[][3];
class Shape{
public:
	Shape();
	virtual void draw();
	virtual void make(){};
	Vertex **verts;
	Vertex **vertsNorm;
	Vertex center;
	Vertex axis; 
	void changeNormDisplay(int flag);
	void translate(float xpos, float ypos, float zpos);
	void rotate(float deg, int x, int y, int z);
	void scale(float xScale, float yScale, float zScale);
	int getNormDisplay(){ return normDisplay;};
	void axisRotate(float deg);
	void changeVertical(int newVS);
	void changeRow(int newRS);
	void changeRender(int newMode);
	void crossProduct( Vertex *cross,Vertex *p0, Vertex *p1, Vertex *p2);
	int getVS(){ return vs;};
	int getRS(){ return rs; };
	int renderMode;
	float length(Vertex * norm);
protected:
	virtual void makeNorms();
	virtual void drawNorms();
	virtual Vertex chooseAxis();
	int rs;
	int vs;
	int normDisplay;
};
#endif
