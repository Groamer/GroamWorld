#include "stdafx.h"
#include "movement.h"

void Movement::init()
{
	xPos = 0;
	yPos = 0;
}

void Movement::walk(float speed, int angle, float yRot)
{
	xPos += (float)cos((yRot + angle) / 180 * M_PI) * (0.01 * speed);
	yPos += (float)sin((yRot + angle) / 180 * M_PI) * (0.01 * speed);
}

float Movement::getXPos()
{
	return xPos;
}

float Movement::getYPos()
{
	return yPos;
}