#include "Camera.h"

Camera::Camera(GLfloat * pos, GLfloat * at, GLfloat * up_i): camLocation(pos[0], pos[1], pos[2]), 
lookAt(at[0],at[1],at[2]), 
up(up_i[0], up_i[1], up_i[2]){}
void Camera::translate(float xpos, float ypos, float zpos){
	camLocation.x += xpos;
	camLocation.y += ypos;
	camLocation.z += zpos;
	//cout << "Z:"<<camLocation.z  << "Lookat:"<<lookAt.z<< endl;
	//cout << camLocation.z + lookAt.z << endl;
}
void Camera::rotate(float deg, int x, int y, int z){
	Vertex temp(camLocation.x, camLocation.y, camLocation.z);
	translate((float)-camLocation.x, (float)-camLocation.y, (float)-camLocation.z);
	deg = 3.141592654f*2/180 * deg;	
	if(x == 1){
		GLfloat ypos = camLocation.y;
		GLfloat zpos = camLocation.z;
		camLocation.y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		camLocation.z = ypos*(float)sin(deg) + zpos*(float)cos(deg);
		 ypos = lookAt.y;
		 zpos = lookAt.z;
		lookAt.y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		lookAt.z = ypos*(float)sin(deg) + zpos*(float)cos(deg);

	}
	if(y == 1){
		GLfloat xpos = camLocation.x;
		GLfloat zpos = camLocation.z;
		camLocation.x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		camLocation.z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
		
		 xpos = lookAt.x;
		 zpos = lookAt.z;
		lookAt.x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		lookAt.z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
			
	}
	if(z == 1){
		GLfloat xpos = camLocation.x;
		GLfloat ypos = camLocation.y;
		camLocation.x = xpos*(float)cos(deg) - ypos*(float)sin(deg); 
		camLocation.y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
		xpos = lookAt.x;
		ypos = lookAt.y;
		lookAt.x = xpos*(float)cos(deg) - ypos*(float)sin(deg); 
		lookAt.y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
		xpos = up.x;
		ypos = up.y;
		up.x = xpos*(float)cos(deg) - ypos*(float)sin(deg);
		up.y = xpos*(float)sin(deg) + ypos*(float)cos(deg);

	}
	translate((float)temp.x, (float)temp.y, (float)temp.z);
}
	
void Camera::updateLookAt(){

}
