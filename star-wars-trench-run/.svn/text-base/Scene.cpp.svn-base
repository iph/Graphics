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
		for(int i = 0; i < enemies.size(); i++){
			enemies[i]->changeNormDisplay((enemies[i]->getNormDisplay()+1)%2);
		}
		for(int i = 0; i < shots.size(); i++){
			shots[i]->changeNormDisplay((shots[i]->getNormDisplay()+1)%2);
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
		for (unsigned int i = 0; i < enemies.size(); i++){
			enemies[i]->draw();
		}
		for (unsigned int i = 0; i < shots.size(); i++){
			shots[i]->draw();
		}
		for(unsigned int i = 0; i < intersects.size(); i++){
			intersects[i]->draw();
		}
		if(drawRay){
//			cout << "x" << x << endl;

		}	
	}
void Scene::parseScene(string sceneText){
    
    //Enemies
    char enemy1[300] = "2 (-2.5 -7.75 -300 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy2[300] = "2 (-1.7 -.5 -105 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy3[300] = "2 (1.7 -.5 -165 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy4[300] = "2 (0 4 -348 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy5[300] = "2 (0 -4 -348 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy6[300] = "2 (4 -2.5 -620 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy7[300] = "2 (-5 -.75 -620 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy8[300] = "2 (6 -7.75 -720 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy9[300] = "2 (5 -7.75 -780 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy10[300] = "2 (-6 -7.75 -720 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy11[300] = "2 (-5 -7.75 -780 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char enemy12[300] = "2 (-6 -7.75 -920 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy13[300] = "2 (-3 -7.75 -920 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy14[300] = "2 (0 -7.75 -920 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy15[300] = "2 (3 -7.75 -920 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy16[300] = "2 (6 -7.75 -920 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char enemy17[300] = "2 (-5 -7.75 -940 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy18[300] = "2 (-2 -7.75 -940 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy19[300] = "2 (2 -7.75 -940 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char enemy20[300] = "2 (5 -7.75 -940 1.0) (1 2.5 2 1.0) (180 180 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    //Trench
    char trench1lw[300] = "4 (-7.5 0 -50 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench1rw[300] = "4 (7.5 0 -50 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench1bw[300] = "4 (0 -9 -50 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench2lw[300] = "4 (-7.5 0 -150 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench2rw[300] = "4 (7.5 0 -150 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench2bw[300] = "4 (0 -9 -150 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench3lw[300] = "4 (-7.5 0 -250 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench3rw[300] = "4 (7.5 0 -250 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench3bw[300] = "4 (0 -9 -250 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench4lw[300] = "4 (-7.5 0 -350 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench4rw[300] = "4 (7.5 0 -350 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench4bw[300] = "4 (0 -9 -350 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench5lw[300] = "4 (-7.5 0 -450 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench5rw[300] = "4 (7.5 0 -450 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench5bw[300] = "4 (0 -9 -450 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench6lw[300] = "4 (-7.5 0 -550 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench6rw[300] = "4 (7.5 0 -550 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench6bw[300] = "4 (0 -9 -550 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench7lw[300] = "4 (-7.5 0 -650 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench7rw[300] = "4 (7.5 0 -650 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench7bw[300] = "4 (0 -9 -650 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench8lw[300] = "4 (-7.5 0 -750 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench8rw[300] = "4 (7.5 0 -750 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench8bw[300] = "4 (0 -9 -750 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench9lw[300] = "4 (-7.5 0 -850 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench9rw[300] = "4 (7.5 0 -850 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench9bw[300] = "4 (0 -9 -850 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench10lw[300] = "4 (-7.5 0 -950 1.0) (100 18 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench10rw[300] = "4 (7.5 0 -950 1.0) (100 18 1 1.0) (0 -90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char trench10bw[300] = "4 (0 -9 -950 1.0) (15 100 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char finallw[300] = "4 (-10 -3 -1025 1.0) (50 24 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char finalrw[300] = "4 (10 -3 -1025 1.0) (50 24 1 1.0) (0 90 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char finalbw[300] = "4 (0 -12 -1025 1.0) (20 50 1 1.0) (-90 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char finalw[300] = "4 (0 -3 -1050 1.0) (20 24 1 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    //Obtacles
    char obstacle1[300] = "1 (0 -5.5 -140 1.0) (15 7 100 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";

    char obstacle2[300] = "1 (0 4.5 -255 1.0) (15 9 3.9 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle3[300] = "1 (3.75 0 -255 1.0) (7.5 18 4 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char obstacle4[300] = "1 (0 -7 -348 1.0) (15 4 3.9 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle5[300] = "1 (-5.5 0 -348 1.0) (4 18 4 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle6[300] = "1 (0 7 -348 1.0) (15 4 3.9 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle7[300] = "1 (5.5 0 -348 1.0) (4 18 4 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle8[300] = "1 (0 0 -348 1.0) (15 4 3.9 1) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char obstacle9[300] = "1 (2.5 0 -450 1.0) (10 18 70 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char obstacle10[300] = "1 (-5.5 -5.5 -560 1.0) (4 7 150 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle11[300] = "1 (0 -6.5 -560 1.0) (15 5 149.9 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle12[300] = "1 (0 6.5 -560 1.0) (15 5 149.9 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char obstacle13[300] = "1 (0 6.5 -800 1.0) (15 5 30 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle14[300] = "1 (0 -5 -800 1.0) (15 8 30 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    char obstacle15[300] = "1 (0 5 -830 1.0) (15 5 30 1.0) (-10 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle16[300] = "1 (0 -10 -830 1.0) (15 8 30 1.0) (-10 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle17[300] = "1 (0 1 -950 1.0) (15 2 100 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    char obstacle18[300] = "1 (0 8 -950 1.0) (15 2 100 1.0) (0 0 0 1) (0.5) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0) (1.0 1.0 1.0 1.0)";
    
    
    parseEnemy(enemy1);
    parseEnemy(enemy2);
    parseEnemy(enemy3);
    parseEnemy(enemy4);
    parseEnemy(enemy5);
    parseEnemy(enemy6);
    parseEnemy(enemy7);
    parseEnemy(enemy8);
    parseEnemy(enemy9);
    parseEnemy(enemy10);
    parseEnemy(enemy11);
    parseEnemy(enemy12);
    parseEnemy(enemy13);
    parseEnemy(enemy14);
    parseEnemy(enemy15);
    parseEnemy(enemy16);
    parseEnemy(enemy17);
    parseEnemy(enemy18);
    parseEnemy(enemy19);
    parseEnemy(enemy20);

    parseObject(trench1lw);
    parseObject(trench1rw);
    parseObject(trench1bw);
    parseObject(trench2lw);
    parseObject(trench2rw);
    parseObject(trench2bw);
    parseObject(trench3lw);
    parseObject(trench3rw);
    parseObject(trench3bw);
    parseObject(trench4lw);
    parseObject(trench4rw);
    parseObject(trench4bw);
    parseObject(trench5lw);
    parseObject(trench5rw);
    parseObject(trench5bw);
    parseObject(trench6lw);
    parseObject(trench6rw);
    parseObject(trench6bw);
    parseObject(trench7lw);
    parseObject(trench7rw);
    parseObject(trench7bw);
    parseObject(trench8lw);
    parseObject(trench8rw);
    parseObject(trench8bw);
    parseObject(trench9lw);
    parseObject(trench9rw);
    parseObject(trench9bw);
    parseObject(trench10lw);
    parseObject(trench10rw);
    parseObject(trench10bw);
    parseObject(finallw);
    parseObject(finalrw);
    parseObject(finalbw);
 //   parseObject(finalw);
   
    parseObject(obstacle1);
    parseObject(obstacle2);
    parseObject(obstacle3);
    parseObject(obstacle4);
    parseObject(obstacle5);
    parseObject(obstacle6);
    parseObject(obstacle7);
    parseObject(obstacle8);
    parseObject(obstacle9);
    parseObject(obstacle10);
    parseObject(obstacle11);
    parseObject(obstacle12);
    parseObject(obstacle13);
    parseObject(obstacle14);
    parseObject(obstacle15);
    parseObject(obstacle16);
    parseObject(obstacle17);
    parseObject(obstacle18);
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
      case 1: //Obstacle wall
          cout << "Obstacle" << endl;
          curr = new Cube(1,1);
          break;
	case 3:
		curr = new Sphere(1, 2, 3, GL_POLYGON);
		break;
	case 4://Trench wall
		cout << "Trench Wall" << endl;
		curr = new Rectangle(4,4, texture);

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

void Scene::parseEnemy(char * buffer){
    Enemy * curr;
    char *pshape, *pshine, *pemi, *pamb, *pdiff, *pspec, *ptranslate, *pscale, *protate;
    pshape  = strtok(buffer, " ");
    curr = new Enemy(GL_POLYGON, 1);
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
    curr->center.x = curr->trans[0];
    curr->center.y = curr->trans[1];
    curr->center.z = curr->trans[2];
    // use switch to create your objects, cube given as example 
    printf("read object\n");
	enemies.push_back(curr);
}


void Scene::myabort(void) {
  abort();
  exit(1); /* exit so g++ knows we don't return. */
} 
bool Scene::intersect(Vertex far, Camera camer){

	bool inter = false;
	drawRay = true;
	Vertex p = camer.camLocation;
	Vect * d = Vect::unitVector(*(new Vect(p, far)));
	for(int i = 0; i < shapes.size(); i++){
		if(shapes[i]->intersect(p,*d, &intersects)){
			inter = true;
			cout << "HIT OBJECT " << i << endl;
            break;
		}
	}
	return inter;
}
bool Scene::intersect(Vertex p, Vect d){
	bool inter = false;
	for(int i = 0; i < shapes.size(); i++){
		if(shapes[i]->intersect(p,d, &intersects)){
			Vertex pStar(p.x, p.y, p.z);
			pStar.x += d.x;
			pStar.y += d.y;
			pStar.z += d.z;
			if(!shapes[i]->intersect(pStar,d, &intersects)){
				inter = true;
				break;
			}

		}
	}
	for(int i = 0; i < enemies.size(); i++){
		if(enemies[i]->intersect(p,d, &intersects)){
			Vertex pStar(p.x, p.y, p.z);
			pStar.x += d.x;
			pStar.y += d.y;
			pStar.z += d.z;
			if(!enemies[i]->intersect(pStar,d, &intersects)){
				inter = true;
				break;
			}

		}
	}
	return inter;

}
void Scene::loadTexture() {
	cout << shapes.size() << endl;
    texture = Texture::loadTexBMP(wallTexture);
    for(int j = 0; j < shapes.size(); j++){
		shapes[j]->setTexture(texture);
    }
    for(int j = 0; j < enemies.size(); j++){
		enemies[j]->setTexture(texture);
    }

}

