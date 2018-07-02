#include "stdafx.h"
#include "movement.h"

void Movement::init(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;
}

void Movement::walk(float speed, int angle, int yRot)
{
	xPos += (float)cos((float(yRot) + angle) / 180 * M_PI) * speed;
	zPos += (float)sin((float(yRot) + angle) / 180 * M_PI) * speed;
}

float Movement::getXPos()
{
	return xPos;
}

float Movement::getYPos()
{
	return yPos;
}

float Movement::getZPos()
{
	return zPos;
}