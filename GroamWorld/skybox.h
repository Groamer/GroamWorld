#pragma once
#include "texture.h"
#include <freeglut.h>
#include <freeglut.h>

class Skybox
{
	private:
		Texture* skybox;
	public:
		void init();
		void draw();
};
