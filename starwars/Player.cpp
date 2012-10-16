/*
 * Player.cpp
 */

#include "Player.h"
#include "Texture.h"
GLfloat player_l[] = {0,0,20};
GLfloat player_at[] = {0,0,-1};
GLfloat player_up[] = {0,1,0};

Player::Player()
: rotateRight(false),
rotateLeft(false),
look(player_l, player_at,player_up),
boundingBox(1, 10, 10, 0, 0)
{
	  overlay.bottomRight.remake(-.5, .5, 18.8);
	  overlay.bottomLeft.remake(-.5, -.5, 18.8);
	  overlay.topRight.remake(.5, .5, 18.8);
	  overlay.topLeft.remake(.5, -.5, 18.8);

	//TODO: Figure out the camera coords of starting game.
	health = 100;
//	speed = 1;
}
Player::~Player(){

}
void Player::setTexture(){
	  unsigned int rawr = Texture::loadTexBMP(imagePlayer);
	  overlay.setTexture(rawr);
}
bool Player::hit(float x, float y, float z){
	// TODO: Check bounding box of ship with that of lasers/ outer objects
	return false;
}

bool Player::takeDamage(int amount){
	health -= amount;
	return health > 0; //Returns false when game is over
}
//void Player::moveForward(){
//	look.camLocation
//}

void Player::move(){
//	cout << look.lookAt << endl;

    Vertex loc(look.camLocation.x,look.camLocation.y,look.camLocation.z);
    look.translate(-look.camLocation.x, -look.camLocation.y, -look.camLocation.z);
    overlay.translate(-loc.x, -loc.y, -loc.z);
	///////////////////////////////////
	if(rotateLeft && rotateRight){}
	else if(rotateLeft){
	    look.rotate(2,0,0,1);
	    overlay.rotate(2,0,0,1);
	}
	else if(rotateRight){
	    look.rotate(-2,0,0,1);
	    overlay.rotate(-2,0,0,1);
	}
    overlay.translate(loc.x, loc.y, loc.z);
    look.translate(loc.x,loc.y,loc.z);
    overlay.translate(look.lookAt.x/4,look.lookAt.y/4,look.lookAt.z/4);
    look.translate(look.lookAt.x/4,look.lookAt.y/4,look.lookAt.z/4);


}

void Player::changeAngle(int upDown, int leftRight){
#ifdef __APPLE__
#else
	if(upDown < 0){
		upDown = -upDown/upDown;
	}
	else if(upDown > 0){
		upDown = upDown/upDown;
	}
	if(leftRight < 0){
		leftRight = -leftRight/leftRight;
	}
	else if(leftRight > 0){
		leftRight = leftRight/leftRight;
	}
#endif


    Vertex loc(look.camLocation.x,look.camLocation.y,look.camLocation.z);
    look.translate(-look.camLocation.x, -look.camLocation.y, -look.camLocation.z);
    overlay.translate(-loc.x, -loc.y, -loc.z);


          look.rotate(leftRight/15.0, 0, 1, 0);
          overlay.rotate(leftRight/15.0, 0, 1, 0);
          look.rotate(upDown/15.0, 1, 0, 0);
          overlay.rotate(upDown/15.0, 1, 0, 0);

    overlay.translate(loc.x, loc.y, loc.z);
    look.translate(loc.x,loc.y,loc.z);
}
void Player::draw(){
	overlay.draw();
}
