#include "stdafx.h"
#include "vertex.h"

#include <iostream>

Vertex::Vertex(Vector a, Vector b, Vector c)
{
	triangle = true;

	planeA.vX = a.getX();
	planeA.vY = a.getY();
	planeA.vZ = a.getZ();

	planeB.vX = b.getX();
	planeB.vY = b.getY();
	planeB.vZ = b.getZ();

	planeC.vX = c.getX();
	planeC.vY = c.getY();
	planeC.vZ = c.getZ();
}

Vertex::Vertex(Vector a, Vector b, Vector c, Vector d)
{
	triangle = false;

	planeA.vX = a.getX();
	planeA.vY = a.getY();
	planeA.vZ = a.getZ();

	planeB.vX = b.getX();
	planeB.vY = b.getY();
	planeB.vZ = b.getZ();

	planeC.vX = c.getX();
	planeC.vY = c.getY();
	planeC.vZ = c.getZ();

	planeD.vX = d.getX();
	planeD.vY = d.getY();
	planeD.vZ = d.getZ();

	//std::cout << "quad Plane A: " << file << std::endl;
}

void Vertex::draw()
{
	if (triangle)
	{
		glBegin(GL_TRIANGLES);
			glVertex3f(planeA.vX, planeA.vY, planeA.vZ);
			glVertex3f(planeB.vX, planeB.vY, planeB.vZ);
			glVertex3f(planeC.vX, planeC.vY, planeC.vZ);
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
			glVertex3f(planeA.vX, planeA.vY, planeA.vZ);
			glVertex3f(planeB.vX, planeB.vY, planeB.vZ);
			glVertex3f(planeC.vX, planeC.vY, planeC.vZ);
			glVertex3f(planeD.vX, planeD.vY, planeD.vZ);
		glEnd();
	}
}