#pragma once

class Rotation
{
	private:
		int xPos;
		int yPos;
		int xRot;
		int yRot;

	public:
		void init(int, int);
		void rotate(int, int);
		int getXRot();
		int getYRot();
};
