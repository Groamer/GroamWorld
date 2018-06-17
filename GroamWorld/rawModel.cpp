#include "stdafx.h"
#include "rawModel.h"

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
	glBegin(GL_QUADS);

	glColor3f(0.1f, 1.0f, 0.2f);
	glVertex3f(-size, -1, -size);
	glVertex3f(size, -1, -size);
	glVertex3f(size, -1, size);
	glVertex3f(-size, -1, size);

	glEnd();
}