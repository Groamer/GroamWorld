#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

class Movement
{
	private:
		float xPos;
		float yPos;
		float zPos;

	public:
		void init(float, float, float);
		void walk(float, int, int);

		float getXPos();
		float getYPos();
		float getZPos();
};