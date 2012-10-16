#include "Camera.h"

Camera::Camera(GLfloat * pos, GLfloat * at, GLfloat * up_i): camLocation(pos[0], pos[1], pos[2]), 
lookAt(at[0],at[1],at[2]), 
direction(camLocation, lookAt), 
up(up_i[0], up_i[1], up_i[2]){}
void Camera::translate(float xpos, float ypos, float zpos){
	camLocation.x += xpos;
	camLocation.y += ypos;
	camLocation.z += zpos;
	lookAt.x += xpos;
	lookAt.y += ypos;
	lookAt.z += zpos;
}
void Camera::rotate(float deg, int x, int y, int z){
	Vertex temp(camLocation.x, camLocation.y, camLocation.z);
	translate(-camLocation.x, -camLocation.y, -camLocation.z);
	deg = 3.141592654*2/180 * deg;	
	if(x == 1){
		GLfloat ypos = camLocation.y;
		GLfloat zpos = camLocation.z;
		camLocation.y = ypos*cos(deg) - zpos*sin(deg);
		camLocation.z = ypos*sin(deg) + zpos*cos(deg);
		 ypos = lookAt.y;
		 zpos = lookAt.z;
		lookAt.y = ypos*cos(deg) - zpos*sin(deg);
		lookAt.z = ypos*sin(deg) + zpos*cos(deg);

	}
	if(y == 1){
		GLfloat xpos = camLocation.x;
		GLfloat zpos = camLocation.z;
		camLocation.x = xpos*cos(deg) - zpos*sin(deg);
		camLocation.z = xpos*sin(deg) + zpos*cos(deg);
		
		 xpos = lookAt.x;
		 zpos = lookAt.z;
		lookAt.x = xpos*cos(deg) - zpos*sin(deg);
		lookAt.z = xpos*sin(deg) + zpos*cos(deg);
			
	}
	if(z == 1){
		GLfloat xpos = camLocation.x;
		GLfloat ypos = camLocation.y;
		camLocation.x = xpos*cos(deg) - ypos*sin(deg); 
		camLocation.y = xpos*sin(deg) + ypos*cos(deg);
		 xpos = lookAt.x;
		 ypos = lookAt.y;
		lookAt.x = xpos*cos(deg) - ypos*sin(deg); 
		lookAt.y = xpos*sin(deg) + ypos*cos(deg);

	}
	translate(temp.x, temp.y, temp.z);
}
	
void Camera::updateLookAt(){

}
