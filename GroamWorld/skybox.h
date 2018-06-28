#pragma once
#include "texture.h"
#include <freeglut.h>

class Skybox
{
	private:
		Texture* front;
		Texture* back;
		Texture* left;
		Texture* right;
		Texture* top;
		Texture* bottom;

	public:
		void init();
		void draw();
};
