#include "Shape.h"
#include "Scene.h"
#include "Sphere.h"
#include "Vertex.h"
#include "Rectangle.h"
#include <stdlib.h>
#include "Camera.h"
#include "Cube.h"
#include "Enemy.h"
#include "Texture.h"
#include <stdio.h>
#include<string.h>
#define my_assert(X,Y) ((X)?(void) 0:(printf("error:%s in %s at %d", Y, __FILE__, __LINE__), myabort()))

	void Scene::drawNorms(){
		for(int i = 0; i < shapes.size(); i++){
			shapes[i]->changeNormDisplay((shapes[i]->getNormDisplay()+1)%2);
		}
	}


	Scene::Scene(string sceneText){
	    texture = Texture::loadTexBMP(wallTexture);

		//shapes.push_back(new Sphere(1.0,15,15, GL_POLYGON));
		num_lights = 0;
		drawRay = false;
		parseScene(sceneText);
		drawRay = 0;
	}
	ostream& operator<<(ostream& output, const Scene &p){
		output << "Scene has" ;
		return output;
	}
	void Scene::display(){
		//Sphere rawr(10.0, 15,15, GL_POLYGON);
		for (unsigned int i = 0; i < shapes.size(); i++){
		//	cout<<"SHAPE:"<< shapes[i]<< endl;
//    glMaterialfv(GL_FRONT, GL_AMBIENT, shapes[i]->amb);
 //   glMaterialfv(GL_FRONT, GL_DIFFUSE, shapes[i]->diff);
   // glMaterialfv(GL_FRONT, GL_SPECULAR, shapes[i]->spec);
   // glMaterialfv(GL_FRONT, GL_SHININESS, &shapes[i]->shine);
	glDisable(GL_LIGHTING);
			shapes[i]->draw();
		}
		for(unsigned int i = 0; i < intersects.size(); i++){
			intersects[i]->draw();
		}
		if(drawRay){
//			cout << "x" << x << endl;

		}	
	}
void Scene::parseScene(string sceneText){
        char buffer1[300] = "2 (0 -3.5 -200 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer2[300] = "1 (0 0 0 1.0) (10 15 1000 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer3[300] = "1 (0 3.4 0 1.0) (5.2 2.2 2 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer4[300] = "1 (1.4 0 0 1.0) (2 5.2 2 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer11[300] = "4 (0 0 .5 1.0) (1 1 1 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer12[300] = "4 (0 0 -.5 1.0) (1 1 1 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer13[300] = "4 (.5 0 0 1.0) (100 15 1.0 1.0) (0 80 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer14[300] = "4 (0 0 0 1.0) (1 1 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer15[300] = "1 (0 0 0 1.0) (1 1 1 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer16[300] = "4 (0 -.5 0 1.0) (1 1 1 1.0) (90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";


        char buffer6[300] = "1 (0 -2.25 -60 1.0) (5.2 5.5 100 1.0) (0 0 180 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer7[300] = "2 (-1.7 1.75 -40 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer8[300] = "2 (1.7 1.75 -80 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer9[300] = "2 (1.7 1.75 -105 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
        char buffer10[300] = "1 (500 0 -500 1.0) (10 15 1000 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";

        // char buffer5[300] = "c (0 0 20 1) (0 0 -1 1) ( 0 1 0 1)";
        parseObject(buffer2);
      /*  parseObject(buffer2);
        parseObject(buffer3);
        parseObject(buffer4);
        parseObject(buffer6);
        parseObject(buffer7);
        parseObject(buffer8);
        parseObject(buffer9);*/
    //    parseObject(buffer11);
    //    parseObject(buffer12);
        parseObject(buffer13);
     //   parseObject(buffer14);
        parseObject(buffer15);
        parseObject(buffer16);

       // parseObject(buffer10);

      //  parseCamerabuffer5);
    }


void Scene::parseFloats(char *buffer, GLfloat nums[]) {
  int i;
  char *ps;

  ps = strtok(buffer, " ");
  for (i=0; ps; i++) {
    nums[i] = (float)atof(ps);
    ps = strtok(NULL, " ");
    //printf("read %f ",nums[i]);
  }

}
void Scene::lightingSetup(){
 int i;
  GLfloat globalAmb[]     = {.1f, .1f, .1f, .1f};

  // create flashlight
//  GLfloat amb[] = {0.2, 0.2, 0.2, 1.0};
//  GLfloat dif[] = {0.8, 0.8, 0.8, 1.0};
//  GLfloat spec[] = {5.0, 5.0, 5.0, 1.0};

  //enable lighting
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glEnable(GL_COLOR_MATERIAL);

  // reflective propoerites -- global ambiant light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

 // setup properties of lighting
  for (i=1; i<=num_lights; i++) {
    glEnable(GL_LIGHT0+i);
    glLightfv(GL_LIGHT0+i, GL_AMBIENT, my_lights[i].amb);
    glLightfv(GL_LIGHT0+i, GL_DIFFUSE, my_lights[i].diff);
    glLightfv(GL_LIGHT0+i, GL_SPECULAR, my_lights[i].spec);
    glLightfv(GL_LIGHT0+i, GL_POSITION, my_lights[i].pos);
    if ((my_lights[i].dir[0] > 0) ||  (my_lights[i].dir[1] > 0) ||  (my_lights[i].dir[2] > 0)) {
      glLightf(GL_LIGHT0+i, GL_SPOT_CUTOFF, my_lights[i].angle);
      glLightfv(GL_LIGHT0+i, GL_SPOT_DIRECTION, my_lights[i].dir);
    }
  }
}
void Scene::parseLight(char * buffer){
  LITE *pl;
  char *pamb, *pdiff, *pspec, *ppos, *pdir, *pang;
  my_assert ((num_lights < MAX_LIGHTS), "too many lights");
  pl = &my_lights[++num_lights];

  strtok(buffer, "()");
  pamb  = strtok(NULL, "()");  strtok(NULL, "()"); 
  pdiff = strtok(NULL, "()");  strtok(NULL, "()"); 
  pspec = strtok(NULL, "()");  strtok(NULL, "()"); 
  ppos  = strtok(NULL, "()");  strtok(NULL, "()"); 
  pdir  = strtok(NULL, "()");  strtok(NULL, "()"); 
  pang  = strtok(NULL, "()");

  parseFloats(pamb, pl->amb);
  parseFloats(pdiff, pl->diff);
  parseFloats(pspec, pl->spec);
  parseFloats(ppos, pl->pos);
  if (pdir) {
    parseFloats(pdir, pl->dir);
    pl->angle = (float)atof(pang);
    //printf("angle %f\n", pl->angle);
  }
  else
    pl->dir[0]= pl->dir[1]= pl->dir[2] =0;
  printf("read light\n");

}
void Scene::parseCamera(char * buffer){
  GLfloat pos[4];
	GLfloat at[4];
	GLfloat up[4];
  char *ppos, *plook, *pup;

  strtok(buffer, "()");
  ppos  = strtok(NULL, "()");  strtok(NULL, "()"); 
  plook  = strtok(NULL, "()");  strtok(NULL, "()"); 
  pup  = strtok(NULL, "()");  strtok(NULL, "()"); 

  parseFloats(ppos, pos);
  parseFloats(plook, at);
  parseFloats(pup, up);
	cam = new Camera(pos, at, up); 
}
void Scene::parseObject(char * buffer){
  Shape * curr;
  char *pshape, *pshine, *pemi, *pamb, *pdiff, *pspec, *ptranslate, *pscale, *protate;
  pshape  = strtok(buffer, " ");
   int shapeNum = atoi(pshape); 
  //printf("pshape is %s\n",pshape);
  switch (shapeNum){
      case 1: //cube
          curr = new Cube(GL_POLYGON, 1);
          break;
      case 2: //cube
          curr = new Enemy(GL_POLYGON, 1);
          break;
	case 3:
		curr = new Sphere(1, 2, 3, GL_POLYGON);
		break;
	case 4:
		cout << "NEW RECTANGE" << endl;
		curr = new Rectangle(8,8, texture);

		break;
	default:
	//	curr = new Cube(GL_POLYGON, .5);
		break;
  }
  ptranslate    = strtok(NULL, "()");  strtok(NULL, "()");
  pscale        = strtok(NULL, "()");  strtok(NULL, "()"); 
  protate       = strtok(NULL, "()");  strtok(NULL, "()");  

  pshine  = strtok(NULL, "()");strtok(NULL, "()");
  //printf("pshine is %s\n",pshine);

 
  pemi    = strtok(NULL, "()");  strtok(NULL, "()");  
  pamb    = strtok(NULL, "()");  strtok(NULL, "()"); 
  pdiff   = strtok(NULL, "()");  strtok(NULL, "()"); 
  pspec   = strtok(NULL, "()");  strtok(NULL, "()"); 
  curr->shine = (float)atof(pshine);

  parseFloats(ptranslate, curr->trans);
  parseFloats(pscale, curr->scal);
  parseFloats(protate, curr->rot);

  parseFloats(pemi, curr->emi);
  parseFloats(pamb, curr->amb);
  parseFloats(pdiff, curr->diff);
  parseFloats(pspec, curr->spec);
curr->scale(curr->scal[0], curr->scal[1], curr->scal[2]);
curr->rotate(curr->rot[0], 1, 0 , 0);
curr->rotate(curr->rot[1], 0, 1 , 0);
curr->rotate(curr->rot[2], 0, 0 , 1);
curr->translate(curr->trans[0], curr->trans[1],curr->trans[2]);
  // use switch to create your objects, cube given as example 
  printf("read object\n");
	shapes.push_back(curr);
}


void Scene::myabort(void) {
  abort();
  exit(1); /* exit so g++ knows we don't return. */
} 
bool Scene::intersect(Vertex far, Camera camer){

	bool inter = false;
	drawRay = true;
	Vertex p = camer.camLocation;
	x = far.x;
	y = far.y;
	z = far.z;
	x2 = camer.camLocation.x;
	y2 = camer.camLocation.y;
	z2 = camer.camLocation.z;
	Vect * d = Vect::unitVector(*(new Vect(p, far)));
	for(int i = 0; i < shapes.size(); i++){
		if(shapes[i]->intersect(p,*d, &intersects)){
			inter = true;
			cout << "HIT" << endl;
		}
	}
	return inter;
}

void Scene::loadTexture() {

    texture = Texture::loadTexBMP(wallTexture);
    for(int j = 0; j < shapes.size(); j++){
		shapes[j]->setTexture(texture);
    }

}

