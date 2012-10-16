#ifndef PLAYER_H_
#define PLAYER_H_
#ifdef __APPLE__
#define imagePlayer "xwing.bmp"
#else
#define imagePlayer "images/xwing.bmp"
#include "Sphere.h"
#endif
#include "Camera.h"
#include "Cube.h"
#include "Face.h"
class Player {
public:
	Player();
	virtual ~Player();
	bool hit(float x, float y, float z);
	bool takeDamage(int amount);
	void move();
	bool rotateRight;
	bool rotateLeft;
	Camera look;
	Face overlay;
	void draw();
	void setTexture();
	void changeAngle(int upDown, int leftRight);

private:
	int health;
	int speed;
	Sphere boundingBox;
};

#endif /* PLAYER_H_ */
