#include "stdafx.h"
#include "model.h"

Model::Model(const std::string& file)
{
	std::ifstream pFile(file.c_str());
	if (!pFile.is_open())
	{
		std::cout << "Could not load model: " << file << std::endl;
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
			Vector vertex = Vector(std::atof(params[1].c_str()), std::atof(params[2].c_str()), std::atof(params[3].c_str()));

			vertices.push_back(vertex);
		}

		if (params[0] == "vt")
		{
			Vector texture(std::atof(params[1].c_str()), std::atof(params[2].c_str()), std::atof(params[3].c_str()));

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

	std::cout << "Loaded model: " << file << std::endl;
}

void Model::bind()
{
	for (int i = 0; i < faces.size(); i++)
	{
		std::vector<std::string> segments = splitLine(faces[i]);

		//Triangle
		if (segments.size() == 3)
		{
			std::vector<std::string> segmentA = splitLine(segments[0], '/');
			std::vector<std::string> segmentB = splitLine(segments[1], '/');
			std::vector<std::string> segmentC = splitLine(segments[2], '/');

			Vector verticeA(vertices[atoi(segmentA[0].c_str()) -1]);
			Vector verticeB(vertices[atoi(segmentB[0].c_str()) -1]);
			Vector verticeC(vertices[atoi(segmentC[0].c_str()) -1]);
			
			vertexIndex.push_back(Vertex(verticeA, verticeB, verticeC));
		}

		//Quad
		if (segments.size() == 4)
		{
			std::vector<std::string> segmentA = splitLine(segments[0], '/');
			std::vector<std::string> segmentB = splitLine(segments[1], '/');
			std::vector<std::string> segmentC = splitLine(segments[2], '/');
			std::vector<std::string> segmentD = splitLine(segments[3], '/');

			Vector verticeA(vertices[atoi(segmentA[0].c_str()) - 1]);
			Vector verticeB(vertices[atoi(segmentB[0].c_str()) - 1]);
			Vector verticeC(vertices[atoi(segmentC[0].c_str()) - 1]);
			Vector verticeD(vertices[atoi(segmentD[0].c_str()) - 1]);

			vertexIndex.push_back(Vertex(verticeA, verticeB, verticeC, verticeD));
		}
	}
}

void Model::draw(float size)
{
	glScalef(size, size, size);
	for (int i = 0; i < vertexIndex.size(); i++)
	{
		vertexIndex[i].draw();
	}
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