#include "ShaderProgram.h"


ShaderProgram::ShaderProgram()
{
	vertexShaderID = loadShader(VERTEX_SHADER_FILE, GL_VERTEX_SHADER);
	fragmentShaderID = loadShader(FRAGMENT_SHADER_FILE, GL_FRAGMENT_SHADER);
	programID = createProgram();
	getAllUniformLocations();
}


ShaderProgram::~ShaderProgram()
{
}

unsigned int ShaderProgram::loadShader(const std::string & filepath, const GLenum & type)
{
	std::stringstream source;
	
	unsigned int shaderID = glCreateShader(type);
	
	std::fstream file;

	try{
		file.open(filepath);
	}
	catch (std::exception e){
		std::cout << "Error opening shader file!\n" << e.what() << std::endl;
	}

	std::string line;
	
	// read shader sourcer from file
	while (std::getline(file, line)) {
		source << line << "\n";
	}
	
	file.close();

	std::string str_source = source.str();
	const char* source_c = str_source.c_str();

	// bind shader source
	glShaderSource(shaderID, 1, &source_c, NULL);

	// compile current shader
	glCompileShader(shaderID);
	
	int  success;
	char infoLog[512];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	
	if (!success) {
		glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
		std::cout << "Error loading shader! \n" << infoLog << std::endl;
	}

	return shaderID;
}

unsigned int ShaderProgram::createProgram()
{
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShaderID);
	glAttachShader(shaderProgram, fragmentShaderID);
	glLinkProgram(shaderProgram);
	
	int success;
	
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		
		std::cout << "Error creating shader! \n" << infoLog << std::endl;
		
		return -1;
	}

	// shaders should be deleted after linkage
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
	
	return shaderProgram;
}

void ShaderProgram::startShader() const
{
	glUseProgram(programID);
}

void ShaderProgram::stopShader() const
{
	glUseProgram(0);
}

void ShaderProgram::loadModelMatrix(const glm::mat4 &matrix) const
{
	this->loadMatrix(this->modelMatrixUniformLocation, matrix);
}

void ShaderProgram::loadProjectionMatrix(const glm::mat4 & matrix) const
{
	this->loadMatrix(this->projectionMatrixUniformLocation, matrix);
}

unsigned int ShaderProgram::getUniformLocation(const std::string & name)
{
	return glGetUniformLocation(this->programID, name.c_str());
}

void ShaderProgram::getAllUniformLocations() {
	this->modelMatrixUniformLocation = this->getUniformLocation("modelMatrix");
	this->projectionMatrixUniformLocation = this->getUniformLocation("projectionMatrix");
}

void ShaderProgram::loadMatrix(unsigned int location, const glm::mat4 & matrix) const
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	//std::cout << matrix[0][0] << " " << matrix[0][1] << " " << matrix[0][2] << " " << matrix[0][3] << "\n";
	//std::cout << matrix[1][0] << " " << matrix[1][1] << " " << matrix[1][2] << " " << matrix[1][3] << "\n";
	//std::cout << matrix[2][0] << " " << matrix[2][1] << " " << matrix[2][2] << " " << matrix[2][3] << "\n";
	//std::cout << matrix[3][0] << " " << matrix[3][1] << " " << matrix[3][2] << " " << matrix[3][3] << "\n";

}
