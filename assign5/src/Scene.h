#include <glut.h>
#include <iostream>
#include <vector>
#include "Camera.h"
#include "Vertex.h"
using namespace std;
#ifndef __scene_HEADER__
#define __scene_HEADER__
#define MAX_LIGHTS 8
typedef struct _LITE{
  GLfloat amb[4];
  GLfloat diff[4];
  GLfloat spec[4];
  GLfloat pos[4];
  GLfloat dir[3];
  GLfloat angle;
}LITE;
class Shape;
class Scene{
	friend ostream& operator<<(ostream& output, const Vect& p);
	public:
		Scene(string sceneText);	
		LITE my_lights[MAX_LIGHTS];
		vector<Shape *> shapes;
		Camera * cam;
		void display();
		GLfloat lighting[4][4];
		float * intersect(Vertex far);
	private:	
		void parseScene(string sceneText);
		void parseObject(char * buffer);
		void myabort();
		void parseFloats(char *buffer,  GLfloat nums[]);	
		void parseLight(char * buffer);
		void parseCamera(char * buffer);
		int num_lights;
		float x,y,z,x2,y2,z2;
};
#endif
