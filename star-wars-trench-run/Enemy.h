#include "Cube.h"
#include "Player.h"
#include "Sphere.h"
#ifndef ENEMY_H_
#define ENEMY_H_

extern GLfloat colors[][3];
class Enemy:public Cube {
public:
	Enemy(int renderModeInit, int initsize);
	virtual ~Enemy();
    Vect* raytrace(Camera * c);
private:
    int numShots;
	int health;
	int size;
	Vertex verticesNorm[8];
};

#endif /* ENEMY_H_ */
