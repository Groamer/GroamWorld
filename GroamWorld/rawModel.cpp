#include "stdafx.h"
#include "rawModel.h"

void RawModel::init()
{
	grass = new Texture("pavement_brick.png");
}

void RawModel::setCube(float size)
{
	glBegin(GL_QUADS);
		glColor3f(1, 1, 1);
		glVertex3f(-size, -size, -size);
		glVertex3f(size, -size, -size);
		glVertex3f(size, size, -size);
		glVertex3f(-size, size, -size);

		glColor3f(0, 0, 1);
		glVertex3f(-size, -size, size);
		glVertex3f(size, -size, size);
		glVertex3f(size, size, size);
		glVertex3f(-size, size, size);
		
		glColor3f(0, 1, 0);
		glVertex3f(-size, -size, -size);
		glVertex3f(-size, size, -size);
		glVertex3f(-size, size, size);
		glVertex3f(-size, -size, size);

		glColor3f(0, 1, 1);
		glVertex3f(size, -size, -size);
		glVertex3f(size, size, -size);
		glVertex3f(size, size, size);
		glVertex3f(size, -size, size);

		glColor3f(1, 0, 0);
		glVertex3f(-size, -size, -size);
		glVertex3f(size, -size, -size);
		glVertex3f(size, -size, size);
		glVertex3f(-size, -size, size);

		glColor3f(1, 1, 0);
		glVertex3f(-size, size, -size);
		glVertex3f(size, size, -size);
		glVertex3f(size, size, size);
		glVertex3f(-size, size, size);
	glEnd();
}

void RawModel::setGround(float size)
{
	grass->bind();

	float textureSize = 0.25;

	for (float i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			glPushMatrix();
			glTranslatef(i * textureSize * 2, 0.0, j * textureSize * 2);

			glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(-textureSize, -0.5, -textureSize);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(textureSize, -0.5, -textureSize);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(textureSize, -0.5, textureSize);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(-textureSize, -0.5, textureSize);
			glEnd();
			glDisable(GL_TEXTURE_2D);

			glPopMatrix();
		}
	}
}