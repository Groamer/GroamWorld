#include "stdafx.h"
#include "world.h"

void World::init()
{
	grass = new Texture("Textures/grass.png");
	brick = new Texture("Textures/brick.png");
	brick_small = new Texture("Textures/brick_small.png");
	stone = new Texture("Textures/stone.png");
}

//Check if a is bigger than b
bool World::floatBigger(float a, float b)
{
	float epsilon = 0.00001f;
	float check = a - b;
	return (check > epsilon);
}

//Check if a equals b
bool World::floatEquals(float a, float b)
{
	float epsilon = 0.00001f;
	float check = a - b;
	return (check < epsilon && check > -epsilon);
}

void World::draw()
{
	cube(0, 0, 0, 15, 0, 12, *grass);

	//palace
	cube(0, 0, 12, 15, 0.1, 15, *brick);
	cube(0, 2, 12, 15, 2.2, 15, *brick);
	cube(2, 0.1, 12, 2.5, 2, 12.5, *stone);
	cube(4.5, 0.1, 12, 5, 2, 12.5, *stone);
	cube(10, 0.1, 12, 10.5, 2, 12.5, *stone);
	cube(12.5, 0.1, 12, 13, 2, 12.5, *stone);

	//outer walls
	cube(0, 0, 0, 0, 2, 15, *brick_small);
	cube(0, 0, 0, 15, 2, 0, *brick_small);
	cube(15, 0, 0, 15, 2, 15, *brick_small);
	cube(0, 0, 15, 15, 2, 15, *brick_small);
}

void World::cube(float xStart, float yStart, float zStart, float xEnd, float yEnd, float zEnd, Texture texture)
{
	texture.bind();

	if (!floatEquals(xStart, xEnd) && !floatEquals(yStart, yEnd) && !floatEquals(zStart, zEnd))
	{
		for (float x1 = xStart; floatBigger(xEnd, x1); x1 ++)
		{
			float x2;
			if (floatBigger(1, xEnd - x1))
				x2 = xEnd;
			else
				x2 = x1 + 1;

			for (float y1 = yStart; floatBigger(yEnd, y1); y1 ++)
			{
				float y2;
				if (floatBigger(1, yEnd - y1))
					y2 = yEnd;
				else
					y2 = y1 + 1;

				for (float z1 = zStart; floatBigger(zEnd, z1); z1 ++)
				{
					float z2;
					if (floatBigger(1, zEnd - z1))
						z2 = zEnd;
					else
						z2 = z1 + 1;

					glEnable(GL_TEXTURE_2D);
					glBegin(GL_QUADS);
						//front side
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y1, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y1, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z1);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z1);

						//right side
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x2, y1, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y1, z2);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x2, y2, z1);

						//right side
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x2, y1, z2);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x1, y1, z2);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x1, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x2, y2, z2);

						//left side
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y1, z2);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x1, y1, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x1, y2, z1);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z2);

						//top side
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y2, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y2, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z2);

						//bottom side
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y1, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y1, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y1, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y1, z2);
					glEnd();
					glDisable(GL_TEXTURE_2D);
				}
			}
		}
	}
	else if (floatEquals(xStart, xEnd) ^ floatEquals(yStart, yEnd) ^ floatEquals(zStart, zEnd))
	{
		if (floatEquals(xStart, xEnd))
		{
			float x = xStart;

			for (float y1 = yStart; floatBigger(yEnd, y1); y1 ++)
			{
				float y2;
				if (floatBigger(1, yEnd - y1))
					y2 = yEnd;
				else
					y2 = y1 + 1;

				for (float z1 = zStart; floatBigger(zEnd, z1); z1 ++)
				{
					float z2;
					if (floatBigger(1, zEnd - z1))
						z2 = zEnd;
					else
						z2 = z1 + 1;

					glEnable(GL_TEXTURE_2D);
					glBegin(GL_QUADS);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x, y1, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x, y2, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x, y1, z2);
					glEnd();
				}
			}
		}

		if (floatEquals(yStart, yEnd))
		{
			float y = yStart;

			for (float x1 = xStart; floatBigger(xEnd, x1); x1 ++)
			{
				float x2;
				if (floatBigger(1, xEnd - x1))
					x2 = xEnd;
				else
					x2 = x1 + 1;

				for (float z1 = zStart; floatBigger(zEnd, z1); z1 ++)
				{
					float z2;
					if (floatBigger(1, zEnd - z1))
						z2 = zEnd;
					else
						z2 = z1 + 1;

					glEnable(GL_TEXTURE_2D);
					glBegin(GL_QUADS);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y, z2);
					glEnd();
				}
			}
		}

		if (floatEquals(zStart, zEnd))
		{
			float z = zStart;

			for (float x1 = xStart; floatBigger(xEnd, x1); x1 ++)
			{
				float x2;
				if (floatBigger(1, xEnd - x1))
					x2 = xEnd;
				else
					x2 = x1 + 1;

				for (float y1 = yStart; floatBigger(yEnd, y1); y1 ++)
				{
					float y2;
					if (floatBigger(1, yEnd - y1))
						y2 = yEnd;
					else
						y2 = y1 + 1;

					glEnable(GL_TEXTURE_2D);
					glBegin(GL_QUADS);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y1, z);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y1, z);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z);
					glEnd();
				}
			}
		}
	}
	else
	{
		std::cout << "Could not draw shape" << std::endl;
	}
	
}