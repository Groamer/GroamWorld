#include "stdafx.h"
#include "stb.h"
#define STB_IMAGE_IMPLEMENTATION
#include "rotation.h"
#include "movement.h"
#include "rawModel.h"
#include <iostream>
#include <freeglut.h>

Rotation rotation;
Movement movement;
RawModel rawModel;

float walkPace = 0.5;
int width = 1280;
int height = 720;
bool keys[255];

void init()
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("GroamWorld");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(width / 2, height / 2);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	memset(keys, 0, sizeof(keys));
	rotation.init(width, height);
	movement.init();
	rawModel.init();
}

void display() 
{
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (float)width/height, 0.1, 30);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rotation.getXRot(), 1, 0, 0);
	glRotatef(rotation.getYRot(), 0, 1, 0);
	glTranslatef(movement.getXPos(), 0.0, movement.getYPos());
	
	rawModel.setGround(0.25);
	//rawModel.setCube(4);

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouseMotion(int x, int y)
{
	glutWarpPointer(width / 2, height / 2);
	rotation.rotate(x, y);
}

void keyboardEvent(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);

	keys[key] = true;
}

void keyboardCheck(unsigned char key, int x, int y)
{
	keys[key] = false;
}

void idle()
{
	if (keys['w'])
		movement.walk(walkPace, 90, rotation.getYRot());

	if (keys['s'])
		movement.walk(walkPace, 270, rotation.getYRot());

	if (keys['a'])
		movement.walk(walkPace, 0, rotation.getYRot());

	if (keys['d'])
		movement.walk(walkPace, 180, rotation.getYRot());

	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	init();

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboardEvent);
	glutKeyboardUpFunc(keyboardCheck);
	glutMainLoop();

	return 0;
}