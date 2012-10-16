#include "Enemy.h"
#include "Vertex.h"
#include <math.h>
/*GLfloat enemy_l[] = {0,0,20};
GLfloat enemy_at[] = {0,0,-1};
GLfloat enemy_up[] = {0,1,0};*/

Enemy::Enemy(int renderModeInit, int initsize): Cube(renderModeInit, initsize)
{
    remake(1, 2);
    numShots = 1;
}
Enemy::~Enemy(){
    
}
Vect* Enemy::raytrace(Camera * c)     // Sphere c is the player's bounding "box"
{
    Vect * d = NULL;
    if ((sqrt(pow((center.x-c->camLocation.x),2)+pow((center.y-c->camLocation.y),2)+pow((center.z-c->camLocation.z), 2)) <= 100) && (numShots > 0)) {
        cout << "shoot" << endl;
        d = new Vect(c->camLocation, center);
        numShots--;
    }
    return d;
}
