#include "loader.h"



Loader::Loader()
{
	
}


Loader::~Loader()
{
}

unsigned int Loader::createVAO()
{
	unsigned int vaoID;
	glGenVertexArrays(1, &vaoID);
	
	// keep track of all the VAOs we're creating
	vaos.push_back(vaoID);
	
	return vaoID;
}

void Loader::storeDataInArrayBuffer(const float * buffer, size_t size)
{
	unsigned int vboID;
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

	// keep track of created vbos so we can remove them later
	this->vbos.push_back(vboID);
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}

RawModel& Loader::loadToVAO(const float* indexBuffer, size_t indexBufferSize)
{
	// create a new VAO in GPU
	unsigned int vaoID = this->createVAO();

	glBindVertexArray(vaoID);

	// save vertices to vbo
	this->storeDataInArrayBuffer(indexBuffer, indexBufferSize);
	this->unbindVAO();

	// num of vertices = indexBufferSize(bytes) / sizeof float / 3 floats per vertex
	return *(new RawModel(vaoID, indexBufferSize / sizeof(float) / 3.0));
}

// Removes all VAOs from GPU
void Loader::cleanUp()
{
	for (unsigned int vao : this->vaos) {
		glDeleteVertexArrays(1, &vao);
	}

	for (unsigned int vbo : this->vbos) {
		glDeleteBuffers(1, &vbo);
	}

}
