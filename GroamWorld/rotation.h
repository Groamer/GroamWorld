#pragma once

class Rotation
{
	private:
		int xPos;
		int yPos;
		float xRot;
		float yRot;
	public:
		void init(int, int);
		void rotate(int, int);
		float getXRot();
		float getYRot();
};
