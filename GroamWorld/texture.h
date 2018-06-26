#pragma once
#include "stb.h"
#include <string>
#include <iostream>
#include <fstream>
#include <freeglut.h>

class Texture
{
private:
	GLuint index;

public:
	Texture(const std::string&);
	void bind();
};
