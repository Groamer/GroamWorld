#include "stdafx.h"
#include "world.h"

void World::init()
{
	rotate = 0.0f;

	statue = new Model("Models/statue.obj", "Textures/Models/statue.png");
	windmill = new Model("Models/windmill.obj", "Textures/Models/windmill.png");
	chapel = new Model("Models/chapel.obj", "Textures/Models/chapel.png");

	grass = new Texture("Textures/Materials/grass.png");
	wall = new Texture("Textures/Materials/wall.png");
	wall_shattered = new Texture("Textures/Materials/wall_shattered.png");
	brick = new Texture("Textures/Materials/brick.png");
	brick_small = new Texture("Textures/Materials/brick_small.png");
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
	if (rotate >= 360.0f)
	{
		rotate = 0.0f;
	}

	rotate += 0.2f;

	//garden
	cube(0, 0, 0,	15, 0.1, 12, *grass);
	cube(6, 0, 2,	9, 0.2, 4, *brick);
	cube(7, 0, 4,	8, 0.11, 12, *brick);

	//palace
	cube(0, 0, 12, 15, 0.2, 15, *brick);
	cube(0, 2, 12, 15, 2.2, 15, *brick);
	cube(0, 0, 14.9, 15, 2.0, 15, *wall);

	//pillar
	cube(2, 0.1, 12.25, 2.5, 2, 12.75, *brick_small);
	cube(4.5, 0.1, 12.25, 5, 2, 12.75, *brick_small);
	cube(10, 0.1, 12.25, 10.5, 2, 12.75, *brick_small);
	cube(12.5, 0.1, 12.25, 13, 2, 12.75, *brick_small);

	//fence
	cube(0, 0, 0, 0.1, 1, 15, *wall_shattered);
	cube(0, 0, 0, 15, 1, 0.1, *wall_shattered);
	cube(14.9, 0, 0, 15, 1, 15, *wall_shattered);

	//models
	statue->draw(7.45, 0.2, 3, rotate, 0.5);
	windmill->draw(13, 0, 2, -45, 0.005);
	chapel->draw(-4.5, 0, 4, 90, 0.01);
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
						glNormal3f(0.0, 0.0, -1.0);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y1, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y1, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z1);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z1);

						//right side
						glNormal3f(1.0, 0.0, 0.0);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x2, y1, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y1, z2);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x2, y2, z1);

						//back side
						glNormal3f(0.0, 0.0, 1.0);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x2, y1, z2);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x1, y1, z2);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x1, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x2, y2, z2);

						//left side
						glNormal3f(-1.0, 0.0, 0.0);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y1, z2);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x1, y1, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x1, y2, z1);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z2);

						//top side
						glNormal3f(0.0, 1.0, 0.0);
						glTexCoord2f(0.0, 0.0);
						glVertex3f(x1, y2, z1);
						glTexCoord2f(1.0, 0.0);
						glVertex3f(x2, y2, z1);
						glTexCoord2f(1.0, 1.0);
						glVertex3f(x2, y2, z2);
						glTexCoord2f(0.0, 1.0);
						glVertex3f(x1, y2, z2);

						//bottom side
						glNormal3f(0.0, -1.0, 0.0);
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
					glDisable(GL_TEXTURE_2D);
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
					glDisable(GL_TEXTURE_2D);
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
					glDisable(GL_TEXTURE_2D);
				}
			}
		}
	}
	else
	{
		std::cout << "Could not draw shape" << std::endl;
	}
}