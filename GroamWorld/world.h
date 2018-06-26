#pragma once
#include "texture.h"
#include "model.h"
#include <freeglut.h>

class World
{
	private:
		Texture* grass;
		Texture* brick;
		Texture* brick_small;
		Texture* stone;

		Model* fountain;

		void cube(float, float, float, float, float, float, Texture);
		bool floatBigger(float, float);
		bool floatEquals(float, float);

	public:
		void init();
		void draw();
};