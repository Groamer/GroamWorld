#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

class Movement
{
	private:
		float xPos;
		float yPos;
	public:
		void init();
		void walk(int, int, float);
		float getXPos();
		float getYPos();
};