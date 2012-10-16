#include "Scene.h"
#include "Shape.h"
#include "Vertex.h"
#include<stdlib.h>
#include "Camera.h"
#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
#define my_assert(X,Y) ((X)?(void) 0:(printf("error:%s in %s at %d", Y, __FILE__, __LINE__), myabort()))
	Scene::Scene(string sceneText){
		num_lights = 0;
		parseScene(sceneText);
	}
	ostream& operator<<(ostream& output, const Scene &p){
		output << " ";
		return output;
	}
	void Scene::display(){
		for (unsigned int i = 0; i < shapes.size(); i++){
			shapes[i]->draw();
		}
	}	
	void Scene::parseScene(string sceneText){
		char buffer[300];
  		FILE *fp;
		cout <<" yar:"<< sceneText << endl;
		fflush(stdout);
  		fp = fopen(sceneText.c_str(), "r");
  		my_assert(fp, "can't open spec");
		cout << "END HERE " << endl;
		fflush(stdout);
  		while(!feof(fp)){
    		fgets(buffer, 300, fp);
    		 //Used to suppress warning of fgets
				//Used to suppress warning of len
					printf("read line: %s\n", buffer);
    			switch (buffer[0]) {
    			case '#':
      			break;
    			case '1':
					case '2':
			 		case '3':
					case '4':
					case '5':
					case '6':
   	  		//read in the cubei
				printf("READING SHAPE\n");
	  		parseObject(buffer);
 	  		break;
			//etc

    			case 'l':
      			parseLight(buffer);
      			break;

    			case 'c':
      			parseCamera(buffer);
      			break;

    			default:
     			 break;
    		}
  	}

}


void Scene::parseFloats(char *buffer, GLfloat nums[]) {
  int i;
  char *ps;

  ps = strtok(buffer, " ");
  for (i=0; ps; i++) {
    nums[i] = atof(ps);
    ps = strtok(NULL, " ");

  }

}

void Scene::parseLight(char * buffer){
  LITE *pl;
  char *pamb, *pdiff, *pspec, *ppos, *pdir, *pang;
  my_assert ((num_lights < MAX_LIGHTS), "too many lights");
  pl = &my_lights[num_lights++];

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
    pl->angle = atof(pang);
    //printf("angle %f\n", pl->angle);
  }
  else
    pl->dir[0]= pl->dir[1]= pl->dir[2] =0;
  printf("read light %f, %f, %f\n", pl->diff[0], pl->diff[1], pl->diff[2]);

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

  at[0] += pos[0];
  at[1] += pos[1];
  at[2] += pos[2];

	cam = new Camera(pos, at, up); 
}
void Scene::parseObject(char * buffer){
  Shape * curr;
  char *pshape, *pshine, *pemi, *pamb, *pdiff, *pspec, *ptranslate, *pscale, *protate;
  pshape  = strtok(buffer, " ");
   int shapeNum = atoi(pshape); 
  switch (shapeNum){
	case 3:
		curr = new Shape();
		break;
	default:
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
  curr->shine = atof(pshine);

  parseFloats(ptranslate, curr->trans);
  parseFloats(pscale, curr->scal);
  parseFloats(protate, curr->rot);

  parseFloats(pemi, curr->emi);
  parseFloats(pamb, curr->amb);
  parseFloats(pdiff, curr->diff);
  parseFloats(pspec, curr->spec);

  printf("read object\n");
	shapes.push_back(curr);
}



float * Scene::intersect(Vertex far){
	bool inter = false;
	Vertex p = cam->camLocation;
	Vect * d = Vect::unitVector(*(new Vect(p, far)));
	for(int i = 0; i < shapes.size(); i++){
		float * intensity = shapes[i]->intersect(p, *d, my_lights, num_lights);
		if(intensity != 0){
			return intensity;
		}
	}
	return 0;
}
void Scene::myabort(void) {
  abort();
  exit(1); /* exit so g++ knows we don't return. */
} 

