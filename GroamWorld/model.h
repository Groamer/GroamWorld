#pragma once
#include "vector.h"
#include "vertex.h"
#include "texture.h"
#include <stdlib.h>
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

class Model
{
	private:
		GLuint index;

		Texture* texture;

		std::vector<Vertex> vertexIndex;

		std::vector<Vector> vertices;
		std::vector<Vector> textures;
		std::vector<Vector> normals;
		std::vector <std::string> faces;

		std::vector<std::string> splitLine(const std::string&);
		std::vector<std::string> splitLine(const std::string&, char);

		void load(const std::string&);
		void bind();

	public:
		Model(const std::string&);
		Model(const std::string&, const std::string&);
		void draw(float, float, float, float, float);
};
