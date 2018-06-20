#pragma once
#include "texture.h"
#include <freeglut.h>
#include <vector>

class RawModel
{
	private:
		Texture* grass;
	public:
		void init();
		void setCube(float);
		void setGround(float);
};