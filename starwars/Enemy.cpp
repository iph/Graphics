#include "Enemy.h"

GLfloat enemy_l[] = {0,0,20};
GLfloat enemy_at[] = {0,0,-1};
GLfloat enemy_up[] = {0,1,0};

Enemy::Enemy(int renderModeInit, int initsize): Cube(renderModeInit, initsize)
{
}
Enemy::~Enemy(){
    
}
