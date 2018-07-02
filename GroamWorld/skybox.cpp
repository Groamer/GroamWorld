#include "stdafx.h"
#include "skybox.h"

void Skybox::init()
{
	front = new Texture("Textures/Skybox/front.png");
	back = new Texture("Textures/Skybox/back.png");
	left = new Texture("Textures/Skybox/left.png");
	right = new Texture("Textures/Skybox/right.png");
	top = new Texture("Textures/Skybox/top.png");
	bottom = new Texture("Textures/Skybox/bottom.png");
}

void Skybox::draw()
{
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	//front side
	front->bind();
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 1.0f);
			glVertex3f(2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f);
			glVertex3f(2.5f, 2.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-2.5f, 2.5f, -2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//left side
	left->bind();
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-2.5f, -2.5f, 2.5f);
		glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-2.5f, 2.5f, -2.5f);
		glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-2.5f, 2.5f, 2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//back side
	back->bind();
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
			glVertex3f(2.5f, -2.5f, 2.5f);
		glTexCoord2f(0.0f, 1.0f);
			glVertex3f(-2.5f, -2.5f, 2.5f);
		glTexCoord2f(0.0f, 0.0f);
			glVertex3f(-2.5f, 2.5f, 2.5f);
		glTexCoord2f(1.0f, 0.0f);
			glVertex3f(2.5f, 2.5f, 2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//right side
	right->bind();
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
			glVertex3f(2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 1.0f);
			glVertex3f(2.5f, -2.5f, 2.5f);
		glTexCoord2f(0.0f, 0.0f);
			glVertex3f(2.5f, 2.5f, 2.5f);
		glTexCoord2f(1.0f, 0.0f);
			glVertex3f(2.5f, 2.5f, -2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//bottom side
	bottom->bind();
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 1.0f);
			glVertex3f(2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f);
			glVertex3f(2.5f, -2.5f, 2.5f);
		glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-2.5f, -2.5f, 2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//top side
	top->bind();
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);
			glVertex3f(-2.5f, 2.5f, -2.5f);
		glTexCoord2f(0.0f, 1.0f);
			glVertex3f(2.5f, 2.5f, -2.5f);
		glTexCoord2f(0.0f, 0.0f);
			glVertex3f(2.5f, 2.5f, 2.5f);
		glTexCoord2f(1.0f, 0.0f);
			glVertex3f(-2.5f, 2.5f, 2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
}