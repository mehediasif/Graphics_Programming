#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL/glew.h>


class Shader
{

public:
	Shader();

	void CreateFromString(const char* vertexCode, const char* fragmentCode);
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLocation);

	std::string Readfile(const char* fileLocation);

	GLuint GetProjectionLocation();
	GLuint GetModelLoation();

	void UseShader();
	void ClearShader();
	~Shader();

private:
	GLuint shaderID, uniformModel, uniformProjection;

	void compileShader(const char* vertexCode, const char* fragmentCode);
	void AddShader(GLuint theprogram, const char* shaderCode, GLenum shaderType);
};

