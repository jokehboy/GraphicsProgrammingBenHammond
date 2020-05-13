#pragma once
#include <string>
#include <vector>
#include <GL\glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);

	GLuint loadCubeMap(std::vector <std::string> faces);
	GLint getTextureHandler() { return textureHandler; };

	void Bind(unsigned int unit); // bind upto 32 textures

	Texture();

	~Texture();

protected:
private:

	GLuint textureHandler;
};

