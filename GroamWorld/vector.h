#pragma once

class Vector
{
	private:
		float x, y, z;

	public:
		Vector();
		Vector(float, float, float);

		float getX();
		float getY();
		float getZ();
};
