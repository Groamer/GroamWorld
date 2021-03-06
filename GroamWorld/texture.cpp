#include "stdafx.h"
#include "texture.h"

Texture::Texture(const std::string& file)
{
	std::cout << "Loading texture '" << file << "'...\t";

	std::ifstream pFile(file.c_str());
	if (!pFile.is_open())
	{
		std::cout << "ERROR: Unable to load texture." << std::endl;
		return;
	}

	int width, height, bpp;
	unsigned char* imgData = stbi_load(file.c_str(), &width, &height, &bpp, 4);

	glGenTextures(1, &index);
	glBindTexture(GL_TEXTURE_2D, index);

	glTexImage2D(GL_TEXTURE_2D,
		0,						//level
		GL_RGBA,				//internal format
		width,					//width
		height,					//height
		0,						//border
		GL_RGBA,				//data format
		GL_UNSIGNED_BYTE,		//data type
		imgData);				//data
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(imgData);

	std::cout << "SUCCESS" << std::endl;
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, index);
}