#ifndef PLAYER_H_
#define PLAYER_H_
#ifdef __APPLE__
#define imagePlayer "xwing.bmp"
#define deathImage "obi.bmp"
#define over "over.bmp"
#define win "win.bmp"
#else
#define imagePlayer "images/xwing.bmp"
#define deathImage "images/obi.bmp"
#define over "images/over.bmp"
#define win "images/win.bmp"
#include "Sphere.h"
#endif
#include "Camera.h"
#include "Cube.h"
#include "Face.h"
#include "Sphere.h"
class Player {
public:
	Player();
	virtual ~Player();
	void setWin();
	void setDeathTexture();
	void setOverTheTop();
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
	double speed;
	Sphere boundingBox;
private:
	int health;
};

#endif /* PLAYER_H_ */
