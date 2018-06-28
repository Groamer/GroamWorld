#include "stdafx.h"
#include "vector.h"

Vector::Vector()
{

}

Vector::Vector(float xCoor, float yCoor, float zCoor)
{
	x = xCoor;
	y = yCoor;
	z = zCoor;
}

float Vector::getX()
{
	return x;
}
float Vector::getY()
{
	return y;
}
float Vector::getZ()
{
	return z;
}