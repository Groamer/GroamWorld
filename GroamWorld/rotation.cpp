#include "stdafx.h"
#include "rotation.h"

void Rotation::init(int width, int height)
{
	xPos = width / 2;
	yPos = height / 2;
}

void Rotation::rotate(int width, int height)
{
	int xMov = width - xPos;
	int yMov = height - yPos;

	xRot = xRot + yMov;
	yRot = yRot + xMov;

	//keep xRot between -90 and 90 degrees
	if (xRot < -90)
	{
		xRot = -90;
	}
	if (xRot > 90)
	{
		xRot = 90;
	}

	//keep yRot between 0 and 360 degrees
	if (yRot < 0)
	{
		yRot += 360;
	}
	if (yRot >= 360)
	{
		yRot -= 360;
	}
}

int Rotation::getXRot()
{
	return xRot;
}

int Rotation::getYRot()
{
	return yRot;
}