#include "stdafx.h"
#include "movement.h"

void Movement::init(float x, float y, float z)
{
	xPos = x;
	zPos = z;
}

void Movement::walk(float speed, int angle, float yRot)
{
	xPos += (float)cos((yRot + angle) / 180 * M_PI) * (0.01 * speed);
	zPos += (float)sin((yRot + angle) / 180 * M_PI) * (0.01 * speed);
}

float Movement::getXPos()
{
	return xPos;
}

float Movement::getZPos()
{
	return zPos;
}