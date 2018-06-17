#include "stdafx.h"
#include "movement.h"

void Movement::init()
{
	xPos = 0;
	yPos = 0;
}

void Movement::move(int angle, float yRot)
{
	float speed = 0.01;

	xPos += (float)cos((yRot + angle) / 180 * M_PI) * speed;
	yPos += (float)sin((yRot + angle) / 180 * M_PI) * speed;
}

float Movement::getXPos()
{
	return xPos;
}

float Movement::getYPos()
{
	return yPos;
}