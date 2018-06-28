#include "stdafx.h"
#include "vertex.h"

Vertex::Vertex(Vector& vA, Vector& vB, Vector& vC, Vector& tA, Vector& tB, Vector& tC, Vector& nA, Vector& nB, Vector& nC)
{
	triangle = true;

	planeA = vA;
	planeB = vB;
	planeC = vC;

	textureA = tA;
	textureB = tB;
	textureC = tC;

	normalA = nA;
	normalB = nB;
	normalC = nC;
}

Vertex::Vertex(Vector& vA, Vector& vB, Vector& vC, Vector& vD, Vector& tA, Vector& tB, Vector& tC, Vector& tD, Vector& nA, Vector& nB, Vector& nC, Vector& nD)
{
	triangle = false;

	planeA = vA;
	planeB = vB;
	planeC = vC;
	planeD = vD;

	textureA = tA;
	textureB = tB;
	textureC = tC;
	textureD = tD;

	normalA = nA;
	normalB = nB;
	normalC = nC;
	normalD = nD;
}

void Vertex::draw()
{
	if (triangle)
	{
		glBegin(GL_TRIANGLES);
			glNormal3f(normalA.getX(), normalA.getY(), normalA.getZ());
			glTexCoord2f(textureA.getX(), -textureA.getY());
			glVertex3f(planeA.getX(), planeA.getY(), planeA.getZ());

			glNormal3f(normalB.getX(), normalB.getY(), normalB.getZ());
			glTexCoord2f(textureB.getX(), -textureB.getY());
			glVertex3f(planeB.getX(), planeB.getY(), planeB.getZ());

			glNormal3f(normalC.getX(), normalC.getY(), normalC.getZ());
			glTexCoord2f(textureC.getX(), -textureC.getY());
			glVertex3f(planeC.getX(), planeC.getY(), planeC.getZ());
		glEnd();
	}
	else
	{
		glBegin(GL_QUADS);
			glNormal3f(normalA.getX(), normalA.getY(), normalA.getZ());
			glTexCoord2f(textureA.getX(), -textureA.getY());
			glVertex3f(planeA.getX(), planeA.getY(), planeA.getZ());

			glNormal3f(normalB.getX(), normalB.getY(), normalB.getZ());
			glTexCoord2f(textureB.getX(), -textureB.getY());
			glVertex3f(planeB.getX(), planeB.getY(), planeB.getZ());

			glNormal3f(normalC.getX(), normalC.getY(), normalC.getZ());
			glTexCoord2f(textureC.getX(), -textureC.getY());
			glVertex3f(planeC.getX(), planeC.getY(), planeC.getZ());

			glNormal3f(normalD.getX(), normalD.getY(), normalD.getZ());
			glTexCoord2f(textureD.getX(), -textureD.getY());
			glVertex3f(planeD.getX(), planeD.getY(), planeD.getZ());
		glEnd();
	}
}