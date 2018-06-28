#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

class Movement
{
	private:
		float xPos;
		float zPos;
	public:
		void init(float, float, float);
		void walk(float, int, float);
		float getXPos();
		float getZPos();
};