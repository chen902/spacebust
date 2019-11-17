#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	unsigned int loadShader(const std::string& filepath, const GLenum& type);
	unsigned int createProgram();
	void startShader() const;
	void stopShader() const;
	
	void loadModelMatrix(const glm::mat4& matrix) const;
	void loadProjectionMatrix(const glm::mat4& matrix) const;

	//getters
	unsigned int getProgramID() const { return programID; }

private:
	unsigned int programID;
	unsigned int vertexShaderID;
	unsigned int fragmentShaderID;
	unsigned int modelMatrixUniformLocation;
	unsigned int projectionMatrixUniformLocation;
	
	const char* VERTEX_SHADER_FILE = "simpleVertexShader.shader";
	const char* FRAGMENT_SHADER_FILE = "simpleFragmentShader.shader";

	unsigned int getUniformLocation(const std::string& name);
	void getAllUniformLocations();
	void loadMatrix(unsigned int location, const glm::mat4& matrix) const;

};

