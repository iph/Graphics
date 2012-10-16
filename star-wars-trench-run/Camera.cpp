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

		 ypos = up.y;
		 zpos = up.z;
		up.y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		up.z = ypos*(float)sin(deg) + zpos*(float)cos(deg);

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
		 xpos = up.x;
		 zpos = up.z;
		up.x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		up.z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
			
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

void Camera::arbitrary_rotate(float deg, int x_g, int y_g, int z_g) {
	float tx, ty, tz, temp1, temp2, temp3, norm;
    float u[3], v[3], n[3];
	tx = camLocation.x;
	ty = camLocation.y;
	tz = camLocation.z;
    translate(-camLocation.x, -camLocation.y, -camLocation.z);
	
	if((up.x == 0) && (up.y == 1) && (up.z == 0)) {
        //rotate(deg, x_g, y_g, z_g);
    }
    else {
    	cout << "Up before:" << up << endl;
    	//Build movement matrix
    	Vect * ax = new Vect(up.x, up.y, up.z);
    	Vect y(0, 1.0 , 0);
    	Vect * v = Vect::unitVector(*ax);
    	Vect * u = Vect::unitVector(*(Vect::crossProduct(*v, y)));
    	Vect * n = Vect::unitVector(*(Vect::crossProduct(*u, *v)));
		GLfloat x = lookAt.x;
		GLfloat yi = lookAt.y;
		GLfloat z = lookAt.z;
		lookAt.x = u->x*x + u->y*yi + u->z*z;
		lookAt.y = v->x*x + v->y*yi + v->z*z;
		lookAt.z = n->x*x + n->y*yi + n->z*z;
		x = up.x;
		yi = up.y;
		z = up.z;
		up.x = u->x*x + u->y*yi + u->z*z;
		up.y = v->x*x + v->y*yi + v->z*z;
		up.z = n->x*x + n->y*yi + n->z*z;
		cout << "up during " << up << endl;
		cout << *u << endl;
		cout << *v << endl;
		cout << *n << endl;

		rotate(deg, x_g, y_g, z_g);
		cout << "up during " << up << endl;

		cout << *u << endl;
		cout << *v << endl;
		cout << *n << endl;

		x = lookAt.x;
		yi = lookAt.y;
		z = lookAt.z;
		lookAt.x = u->x*x + v->x*yi + n->x*z;
		lookAt.y = u->y*x + v->y*yi + n->y*z;
		lookAt.z = u->x*x + v->z*yi + n->z*z;
		x = up.x;
		yi = up.y;
		z = up.z;
		up.x = u->x*x + v->x*yi + n->x*z;
		up.y = u->y*x + v->y*yi + n->y*z;
		up.z = u->z*x + v->z*yi + n->z*z;
		cout << "up after: " << up << endl;

        }

    translate(tx, ty, tz);
}
void Camera::rotate(float deg, int x, int y, int z, Vect * v){
	deg = deg*3.141592654f/180.0f;
	if(x == 1){
		GLfloat ypos = v->y;
		GLfloat zpos = v->z;
		v->y = ypos*(float)cos(deg) - zpos*(float)sin(deg);
		v->z = ypos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(y == 1){
		GLfloat xpos = v->x;
		GLfloat zpos = v->z;
		v->x = xpos*(float)cos(deg) - zpos*(float)sin(deg);
		v->z = xpos*(float)sin(deg) + zpos*(float)cos(deg);
	}
	if(z == 1){
		GLfloat xpos = v->x;
		GLfloat ypos = v->y;
		v->x = xpos*(float)cos(deg) - ypos*(float)sin(deg); 
		v->y = xpos*(float)sin(deg) + ypos*(float)cos(deg);
	}
}

void Camera::updateLookAt(){

}
