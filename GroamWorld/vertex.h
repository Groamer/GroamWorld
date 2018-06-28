#pragma once
#include "vector.h"
#include <freeglut.h>

class Vertex
{
	private:
		bool triangle;

		Vector planeA;
		Vector planeB;
		Vector planeC;
		Vector planeD;

		Vector textureA;
		Vector textureB;
		Vector textureC;
		Vector textureD;

		Vector normalA;
		Vector normalB;
		Vector normalC;
		Vector normalD;

	public:
		Vertex(Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&);
		Vertex(Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&, Vector&);

		void draw();
};