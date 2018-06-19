#pragma once
#include "texture.h"
#include <freeglut.h>

class RawModel
{
	private:
		Texture* grass;
	public:
		void init();
		void setCube(float);
		void setGround(float);
};