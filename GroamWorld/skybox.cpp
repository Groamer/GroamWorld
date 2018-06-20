#include "stdafx.h"
#include "skybox.h"

void Skybox::init()
{
	skybox = new Texture("Textures/skybox.png");
}

void Skybox::draw()
{
	skybox->bind();

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
		//front
		glTexCoord2f(0.25, 0.666667);
			glVertex3f(-2.5, -2.5, -2.5);
		glTexCoord2f(0.5, 0.666667);
			glVertex3f(2.5, -2.5, -2.5);
		glTexCoord2f(0.5, 0.333333);
			glVertex3f(2.5, 2.5, -2.5);
		glTexCoord2f(0.25, 0.333333);
			glVertex3f(-2.5, 2.5, -2.5);

		//left
		glTexCoord2f(0.0, 0.666667);
			glVertex3f(-2.5, -2.5, 2.5);
		glTexCoord2f(0.25, 0.666667);
			glVertex3f(-2.5, -2.5, -2.5);
		glTexCoord2f(0.25, 0.333333);
			glVertex3f(-2.5, 2.5, -2.5);
		glTexCoord2f(0.0, 0.333333);
			glVertex3f(-2.5, 2.5, 2.5);

		//back
		glTexCoord2f(0.75, 0.666667);
			glVertex3f(2.5, -2.5, 2.5);
		glTexCoord2f(1.0, 0.666667);
			glVertex3f(-2.5, -2.5, 2.5);
		glTexCoord2f(1.0, 0.333333);
			glVertex3f(-2.5, 2.5, 2.5);
		glTexCoord2f(0.75, 0.333333);
			glVertex3f(2.5, 2.5, 2.5);

		//right
		glTexCoord2f(0.5, 0.666667);
			glVertex3f(2.5, -2.5, -2.5);
		glTexCoord2f(0.75, 0.666667);
			glVertex3f(2.5, -2.5, 2.5);
		glTexCoord2f(0.75, 0.333333);
			glVertex3f(2.5, 2.5, 2.5);
		glTexCoord2f(0.5, 0.333333);
			glVertex3f(2.5, 2.5, -2.5);

		//down
		glTexCoord2f(0.25, 1.0);
			glVertex3f(-2.5, -2.5, -2.5);
		glTexCoord2f(0.5, 1.0);
			glVertex3f(2.5, -2.5, -2.5);
		glTexCoord2f(0.5, 0.666667);
			glVertex3f(2.5, -2.5, 2.5);
		glTexCoord2f(0.25, 0.666667);
			glVertex3f(-2.5, -2.5, 2.5);

		//up
		glTexCoord2f(0.25, 0.333333);
			glVertex3f(-2.5, 2.5, -2.5);
		glTexCoord2f(0.5, 0.333333);
			glVertex3f(2.5, 2.5, -2.5);
		glTexCoord2f(0.5, 0.0);
			glVertex3f(2.5, 2.5, 2.5);
		glTexCoord2f(0.25, 0.0);
			glVertex3f(-2.5, 2.5, 2.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}