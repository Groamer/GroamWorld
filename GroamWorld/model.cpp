#include "stdafx.h"
#include "model.h"

Model::Model(const std::string& mod)
{
	load(mod);
}

Model::Model(const std::string& mod, const std::string& tex)
{
	load(mod);

	texture = new Texture(tex);
}

void Model::load(const std::string& file)
{
	std::cout << "Loading model '" << file << "'...\t";

	std::ifstream pFile(file.c_str());
	if (!pFile.is_open())
	{
		std::cout << "ERROR: Unable to load model." << std::endl;
		return;
	}

	while (!pFile.eof())
	{
		std::string line;
		std::getline(pFile, line);

		if (line == "" || !line[0] == '#')
			continue;

		std::vector<std::string> params = splitLine(line);

		if (params[0] == "v")
		{
			Vector vertex(std::atof(params[1].c_str()), std::atof(params[2].c_str()), std::atof(params[3].c_str()));

			vertices.push_back(vertex);
		}

		if (params[0] == "vt")
		{
			Vector texture(std::atof(params[1].c_str()), std::atof(params[2].c_str()), 0.0f);

			textures.push_back(texture);
		}

		if (params[0] == "vn")
		{
			Vector normal(std::atof(params[1].c_str()), std::atof(params[2].c_str()), std::atof(params[3].c_str()));

			normals.push_back(normal);
		}

		if (params[0] == "f")
		{
			//Triangle
			if (params.size() == 4)
				faces.push_back(params[1] + " " + params[2] + " " + params[3]);

			//Quad
			if (params.size() == 5)
				faces.push_back(params[1] + " " + params[2] + " " + params[3] + " " + params[4]);
		}
	}

	bind();

	std::cout << "SUCCESS" << std::endl;
}

void Model::bind()
{
	for (int i = 0; i < faces.size(); i++)
	{
		std::vector<std::string> segments = splitLine(faces[i]);

		//Triangles
		if (segments.size() == 3)
		{
			std::vector<std::string> segmentA = splitLine(segments[0], '/');
			std::vector<std::string> segmentB = splitLine(segments[1], '/');
			std::vector<std::string> segmentC = splitLine(segments[2], '/');

			//get vertices
			Vector verticeA(vertices[atoi(segmentA[0].c_str()) -1]);
			Vector verticeB(vertices[atoi(segmentB[0].c_str()) -1]);
			Vector verticeC(vertices[atoi(segmentC[0].c_str()) -1]);

			//get textures
			Vector textureA;
			Vector textureB;
			Vector textureC;

			if (segmentA[1] == "" || segmentB[1] == "" || segmentC[1] == "")
			{
				textureA = Vector(0.f, 0.f, 0.f);
				textureB = Vector(0.f, 0.f, 0.f);
				textureC = Vector(0.f, 0.f, 0.f);
			}
			else
			{
				textureA = Vector(textures[atoi(segmentA[1].c_str()) - 1]);
				textureB = Vector(textures[atoi(segmentB[1].c_str()) - 1]);
				textureC = Vector(textures[atoi(segmentC[1].c_str()) - 1]);
			}

			//get normals
			Vector normalA(normals[atoi(segmentA[2].c_str()) - 1]);
			Vector normalB(normals[atoi(segmentB[2].c_str()) - 1]);
			Vector normalC(normals[atoi(segmentC[2].c_str()) - 1]);
			
			vertexIndex.push_back(Vertex(verticeA, verticeB, verticeC, textureA, textureB, textureC, normalA, normalB, normalC));
		}

		//Quads
		if (segments.size() == 4)
		{
			std::vector<std::string> segmentA = splitLine(segments[0], '/');
			std::vector<std::string> segmentB = splitLine(segments[1], '/');
			std::vector<std::string> segmentC = splitLine(segments[2], '/');
			std::vector<std::string> segmentD = splitLine(segments[3], '/');

			//get vertices
			Vector verticeA(vertices[atoi(segmentA[0].c_str()) - 1]);
			Vector verticeB(vertices[atoi(segmentB[0].c_str()) - 1]);
			Vector verticeC(vertices[atoi(segmentC[0].c_str()) - 1]);
			Vector verticeD(vertices[atoi(segmentD[0].c_str()) - 1]);

			//get textures
			Vector textureA;
			Vector textureB;
			Vector textureC;
			Vector textureD;

			if (segmentA[1] == "" || segmentB[1] == "" || segmentC[1] == "" || segmentD[1] == "")
			{
				textureA = Vector(0.f, 0.f, 0.f);
				textureB = Vector(0.f, 0.f, 0.f);
				textureC = Vector(0.f, 0.f, 0.f);
				textureD = Vector(0.f, 0.f, 0.f);
			}
			else
			{
				textureA = Vector (textures[atoi(segmentA[1].c_str()) - 1]);
				textureB = Vector (textures[atoi(segmentB[1].c_str()) - 1]);
				textureC = Vector (textures[atoi(segmentC[1].c_str()) - 1]);
				textureD = Vector (textures[atoi(segmentD[1].c_str()) - 1]);
			}

			//get normals
			Vector normalA(normals[atoi(segmentA[2].c_str()) - 1]);
			Vector normalB(normals[atoi(segmentB[2].c_str()) - 1]);
			Vector normalC(normals[atoi(segmentC[2].c_str()) - 1]);
			Vector normalD(normals[atoi(segmentC[2].c_str()) - 1]);

			vertexIndex.push_back(Vertex(verticeA, verticeB, verticeC, verticeD, textureA, textureB, textureC, textureD, normalA, normalB, normalC, normalD));
		}
	}
}

void Model::draw(float x, float y, float z, float degrees, float scale)
{
	float scaleReset = 1 / scale;

	glTranslatef(x, y, z);
	glRotatef(degrees, 0.0f, 1.0f, 0.0f);
	glScalef(scale, scale, scale);

	if (texture)
	{
		texture->bind();

		for (int i = 0; i < vertexIndex.size(); i++)
		{
			glEnable(GL_TEXTURE_2D);
			vertexIndex[i].draw();
			glDisable(GL_TEXTURE_2D);
		}
	}
	else
	{
		for (int i = 0; i < vertexIndex.size(); i++)
		{
			vertexIndex[i].draw();
		}
	}
	
	glScalef(scaleReset, scaleReset, scaleReset);
	glRotatef(-degrees, 0.0f, 1.0f, 0.0f);
	glTranslatef(-x, -y, -z);
}

std::vector<std::string> Model::splitLine(const std::string& string)
{
	std::istringstream stream{ string };
	std::vector<std::string> strings
	{
		std::istream_iterator<std::string>{ stream },
		std::istream_iterator<std::string>{}
	};

	return strings;
}

std::vector<std::string> Model::splitLine(const std::string& string, char split)
{
	std::stringstream input(string);
	std::string segment;
	std::vector<std::string> strings;

	while (std::getline(input, segment, split))
	{
		strings.push_back(segment);
	}

	return strings;
}