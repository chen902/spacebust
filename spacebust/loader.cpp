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

void Loader::storeDataInArrayBuffer(unsigned int index, const float * buffer, size_t size)
{
	// generate a new buffer
	unsigned int vboID;
	glGenBuffers(1, &vboID);

	// bind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, vboID);

	// load data into buffer
	glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

	// keep track of created vbos so we can remove them later
	this->vbos.push_back(vboID);

	// enable the attribute at 'index' in the currently bound VAO (assumes it has been bound prior to this function call)
	glEnableVertexAttribArray(index);

	// set the format of the data in buffer and associate it with the currently bound VAO
	// index = the current attribute index, 2 = number of elements per vertex (2D), , , 0 = no stride between elements, 0= no offset.
	glVertexAttribPointer(index, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// unbind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::unbindVAO()
{
	glBindVertexArray(0);
}

RawModel& Loader::loadToVAO(const float* indexBuffer, size_t indexBufferSize)
{
	// create a new VAO in GPU
	unsigned int vaoID = this->createVAO();

	// bind VAO
	glBindVertexArray(vaoID);

	// save vertices vbo to attribute with index 0
	this->storeDataInArrayBuffer(0, indexBuffer, indexBufferSize);
	
	// unbind VAO
	this->unbindVAO();

	// num of vertices = indexBufferSize(bytes) / sizeof float / 2 floats per vertex
	return *(new RawModel(vaoID, indexBufferSize / sizeof(float) / 2.0));
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
