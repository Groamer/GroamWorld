#include "stdafx.h"
#include "stb.h"
#define STB_IMAGE_IMPLEMENTATION
#include "rotation.h"
#include "movement.h"
#include "world.h"
#include "skybox.h"
#include <iostream>
#include <freeglut.h>

Rotation rotation;
Movement movement;
World world;
Skybox skybox;

GLfloat ambientColor[] = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat lightColor[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat lightPosition[] = { -80.0f, 100.0f, -90.0f, 1.0f };

float walkPace = 2.5f;
float lastFrameTime = 0.0f;
int width = 1280;
int height = 720;
bool keys[255];

void init()
{
	//Display settings
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("GroamWorld");

	//Mouse settings
	glutSetCursor(GLUT_CURSOR_NONE);
	glutWarpPointer(width / 2, height / 2);

	//Depth settings
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Lightning settings
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);

	//Keyboard settings
	memset(keys, 0, sizeof(keys));
	rotation.init(width, height);

	//Init custom classes
	movement.init(-5.0f, 0.0f, -5.0f);
	world.init();
	skybox.init();
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
	glRotatef(rotation.getXRot(), 1.0f, 0.0f, 0.0f);
	glRotatef(rotation.getYRot(), 0.0f, 1.0f, 0.0f);

	skybox.draw();

	glPushMatrix();

	glTranslatef(movement.getXPos(), -0.75f, movement.getZPos());

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	world.draw();

	glPopMatrix();

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
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;

	if (keys['w'])
		movement.walk(walkPace * deltaTime, 90, rotation.getYRot());

	if (keys['s'])
		movement.walk(walkPace * deltaTime, 270, rotation.getYRot());

	if (keys['a'])
		movement.walk(walkPace * deltaTime, 0, rotation.getYRot());

	if (keys['d'])
		movement.walk(walkPace * deltaTime, 180, rotation.getYRot());

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