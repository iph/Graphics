#ifndef _RAY_TRACE_H_
#define _RAY_TRACE_H_

// platform specific includes
#ifdef __APPLE__
 #include <GLUT/glut.h>
 #include <OpenGL/gl.h>
 #include <OpenGL/glu.h>
#else
 #include <GL/glut.h>
 #include <GL/gl.h>
 #include <GL/glu.h>
#endif

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 1024

typedef struct color_s
{
	float r, g, b, a;
} color_t;

extern GLuint textureId;
extern color_t screen[WINDOW_WIDTH * WINDOW_HEIGHT];

void plotPixel(color_t *screen, int x, int y, float r, float g, float b, float a);

#endif
