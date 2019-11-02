#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	unsigned int loadShader(const std::string& filepath, const GLenum& type);
	unsigned int createProgram();
	void startShader() const;
	void stopShader() const;

	//getters
	unsigned int getProgramID() const { return programID; }

private:
	unsigned int programID;
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;
	
	const char* VERTEX_SHADER_FILE = "simpleVertexShader.shader";
	const char* FRAGMENT_SHADER_FILE = "simpleFragmentShader.shader";

};

