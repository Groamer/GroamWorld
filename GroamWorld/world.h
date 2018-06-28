#pragma once
#include "texture.h"
#include "model.h"
#include <freeglut.h>

class World
{
	private:
		float rotate;

		Model* statue;
		Model* windmill;
		Model* chapel;

		Texture* grass;
		Texture* wall;
		Texture* wall_shattered;
		Texture* brick;
		Texture* brick_small;

		void cube(float, float, float, float, float, float, Texture);
		bool floatBigger(float, float);
		bool floatEquals(float, float);

	public:
		void init();
		void draw();
};