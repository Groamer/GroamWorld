#pragma once
#include "vector.h"
#include <freeglut.h>

class Vertex
{
	struct vec3D
	{
		float vX, vY, vZ;
	};

	private:
		bool triangle;
		vec3D planeA;
		vec3D planeB;
		vec3D planeC;
		vec3D planeD;

	public:
		Vertex(Vector, Vector, Vector);
		Vertex(Vector, Vector, Vector, Vector);

		void draw();
};